/* Common */
type message = {. "id": string, "message": Js.nullable(string), "defaultMessage": string};

type messages = array(message);

/* addLocaleData */
type localeData('t) = {.. "locale": string} as 't;

[@bs.module "react-intl"] external addLocaleData : localeData('t) => unit = "";

/* defineMessages */
type defineMessages('m) = [@bs] ('m => 'm);

[@bs.module "react-intl"] external defineMessages : defineMessages(Js.t({..})) = "";

/* Components */
type domTag =
  | Span
  | Div
  | H1
  | H2
  | H3
  | H4
  | H5
  | H6
  | P
  | Strong
  | B
  | I
  | Em
  | Mark
  | Small
  | Del
  | Ins
  | Sub
  | Sup;

let mapDomTagToString = (tag) =>
  switch tag {
  | Span => "span"
  | Div => "div"
  | P => "p"
  | H1 => "h1"
  | H2 => "h2"
  | H3 => "h3"
  | H4 => "h4"
  | H5 => "h5"
  | H6 => "h6"
  | Strong => "strong"
  | B => "b"
  | I => "i"
  | Em => "em"
  | Mark => "mark"
  | Small => "small"
  | Del => "del"
  | Ins => "ins"
  | Sub => "sub"
  | Sup => "sup"
  };

let mapOptDomTagToString = (tag) =>
  switch tag {
  | Some(tag) => Some(tag |> mapDomTagToString)
  | None => None
  };

module IntlProvider = {
  [@bs.module "react-intl"] external reactClass : ReasonReact.reactClass = "IntlProvider";
  let make =
      (
        ~locale: option(string)=?,
        ~formats: option(Js.t({..}))=?, /* TODO */
        ~messages: option(Js.Dict.t(string))=?,
        ~defaultLocale: option(string)=?,
        ~defaultFormats: option(Js.t({..}))=?, /* TODO */
        ~textComponent: option(domTag)=?,
        ~initialNow: option(int)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "locale": locale |> Js.Nullable.from_opt,
        "formats": formats |> Js.Nullable.from_opt,
        "messages": messages |> Js.Nullable.from_opt,
        "defaultLocale": defaultLocale |> Js.Nullable.from_opt,
        "defaultFormats": defaultFormats |> Js.Nullable.from_opt,
        "textComponent": textComponent |> mapOptDomTagToString |> Js.Nullable.from_opt,
        "initialNow": initialNow |> Js.Nullable.from_opt
      },
      children
    );
};

module FormattedMessage = {
  [@bs.module "react-intl"] external reactClass : ReasonReact.reactClass = "FormattedMessage";
  type message('t) = {. "id": string, "defaultMessage": string} as 't;
  let make = (~message: message('t), ~values: option(Js.t({..}))=?, ~tagName: option(domTag)=?, _) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "id": message##id,
        "defaultMessage": message##defaultMessage,
        "values": values |> Js.Nullable.from_opt,
        "tagName": tagName |> mapOptDomTagToString |> Js.Nullable.from_opt
      },
      [||]
    );
};

/* Utils */
let wrapUnicodeString = (input: string) => {j|$input|j};

let wrapOptUnicodeString = (input: Js.nullable(string)) =>
  switch (Js.Nullable.to_opt(input)) {
  | Some(input) => input |> wrapUnicodeString
  | None => ""
  };

let messagesArrayToDict = (translation: array(message)) =>
  translation
  |> Array.fold_left(
       (dict, message) => {
         let unicodeMessage = message##message |> wrapOptUnicodeString;
         let unicodeDefaultMessage = message##defaultMessage |> wrapUnicodeString;
         Js.Dict.set(
           dict,
           message##id,
           unicodeMessage !== "" ? unicodeMessage : unicodeDefaultMessage
         );
         dict
       },
       Js.Dict.empty()
     );
