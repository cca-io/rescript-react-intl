let wrapUnicodeString = (input: string) => {j|$input|j};

let wrapOptUnicodeString = (input: Js.nullable(string)) =>
  switch (input->Js.Nullable.toOption) {
  | Some(input) => input->wrapUnicodeString
  | None => ""
  };

let translationsToDict = (translations: array(ReactIntl.translation)) => {
  translations->Belt.Array.reduce(
    Js.Dict.empty(),
    (dict, message) => {
      let unicodeMessage = message##message->wrapOptUnicodeString;
      let unicodeDefaultMessage = message##defaultMessage->wrapUnicodeString;
      dict->Js.Dict.set(
        message##id,
        unicodeMessage !== "" ? unicodeMessage : unicodeDefaultMessage,
      );
      dict;
    },
  );
};
