open Belt;

module Fs = Node.Fs;
module Cp = Node.Child_process;
module Path = Node.Path;
module Process = Node.Process;

let cwd = Process.cwd();
let src = Path.join([|cwd, "examples"|]);
let bin = Path.join([|cwd, "node_modules", ".bin"|]);

Js.log({j|=== ⏳  Extracting messages...|j});
let extracted =
  {j|$(bin)/bs-react-intl-extractor $(src)|j}
  ->Cp.execSync(Cp.option(~encoding="utf8", ()))
  ->Js.Json.parseExn
  ->Js.Json.decodeArray
  ->Option.getExn;
Js.log({j|=== ✅  Extracting messages... done.\n|j});

Locale.all
->Array.forEach(locale => {
    let locale = locale->Locale.toString;

    Js.log({j|=== ⏳  Updating $(locale) translations...|j});
    let file = Path.join([|src, "translations", {j|$(locale).json|j}|]);
    let cache =
      file
      ->Fs.readFileSync(`utf8)
      ->Js.Json.parseExn
      ->Js.Json.decodeArray
      ->Option.getExn
      ->Array.reduce(
          Js.Dict.empty(),
          (acc, json) => {
            let msg = json->Js.Json.decodeObject->Option.getExn;
            let id =
              msg
              ->Js.Dict.unsafeGet("id")
              ->Js.Json.decodeString
              ->Option.getExn;
            acc->Js.Dict.set(id, msg);
            acc;
          },
        );
    let messages =
      extracted
      ->Array.map(json => {
          let msg = json->Js.Json.decodeObject->Option.getExn;
          let id =
            msg->Js.Dict.unsafeGet("id")->Js.Json.decodeString->Option.getExn;
          let defaultMessage =
            msg
            ->Js.Dict.unsafeGet("defaultMessage")
            ->Js.Json.decodeString
            ->Option.getExn;
          let message =
            switch (cache->Js.Dict.get(id)) {
            | None => ""
            | Some(msg) =>
              switch (msg->Js.Dict.get("message")) {
              | None => ""
              | Some(message)
                  when message->Js.Json.decodeString->Option.getExn == "" => ""
              | Some(message) => message->Js.Json.decodeString->Option.getExn
              }
            };
          msg->Js.Dict.set("id", id->Js.Json.string);
          msg->Js.Dict.set("defaultMessage", defaultMessage->Js.Json.string);
          msg->Js.Dict.set("message", message->Js.Json.string);
          msg->Js.Json.object_;
        })
      ->Js.Json.array
      ->Js.Json.stringifyWithSpace(2);

    file->Fs.writeFileAsUtf8Sync(messages ++ "\n");

    Js.log({j|=== ✅  Updating $(locale) translations... done.\n|j});
  });

Js.log({j|✨ Done.|j});
