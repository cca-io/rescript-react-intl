[@bs.module] external en : ReactIntl.messages = "./translations/en.json";

[@bs.module] external ru : ReactIntl.messages = "./translations/ru.json";

type locale =
  | En
  | Ru;

let mapLocaleToString = locale =>
  switch locale {
  | En => "en"
  | Ru => "ru"
  };

let mapLocaleToMessages = locale =>
  switch locale {
  | En => en
  | Ru => ru
  };
