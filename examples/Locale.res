@module("./translations/en.json")
external en: array<Translation.t> = "default"
@module("./translations/ru.json")
external ru: array<Translation.t> = "default"

type locale =
  | En
  | Ru

let all = [En, Ru]

let toString = x =>
  switch x {
  | En => "en"
  | Ru => "ru"
  }

let translations = x =>
  switch x {
  | En => en
  | Ru => ru
  }
