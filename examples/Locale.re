[@bs.module "./translations/en.json"]
external en: array(Util.translation) = "default";
[@bs.module "./translations/ru.json"]
external ru: array(Util.translation) = "default";

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
