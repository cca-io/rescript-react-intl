[@bs.module] external en: ReactIntl.jsonMessages = "./translations/en.json";
[@bs.module] external ru: ReactIntl.jsonMessages = "./translations/ru.json";

type locale =
  | En
  | Ru;

let all = [|En, Ru|];

let toString =
  fun
  | En => "en"
  | Ru => "ru";

let toMessages =
  fun
  | En => en
  | Ru => ru;
