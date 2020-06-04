[@bs.module "./translations/en.json"]
external en: array(Translation.t) = "default";
[@bs.module "./translations/ru.json"]
external ru: array(Translation.t) = "default";

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
