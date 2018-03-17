[@bs.module] external en : ReactIntl.jsonMessages = "./translations/en.json";

[@bs.module] external ru : ReactIntl.jsonMessages = "./translations/ru.json";

type locale =
  | En
  | Ru;

let mapLocaleToString = locale =>
  switch (locale) {
  | En => "en"
  | Ru => "ru"
  };

let mapLocaleToMessages = locale =>
  switch (locale) {
  | En => en
  | Ru => ru
  };
