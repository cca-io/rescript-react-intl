[@bs.module "./translations/en.json"]
external en: array(ReactIntl.translation) = "default";
[@bs.module "./translations/ru.json"]
external ru: array(ReactIntl.translation) = "default";

type locale =
  | En
  | Ru;

let all = [|En, Ru|];

let toString =
  fun
  | En => "en"
  | Ru => "ru";

let translations =
  fun
  | En => en
  | Ru => ru;
