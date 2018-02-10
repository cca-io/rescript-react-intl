/* Common */
type message = {
  .
  "id": string,
  "message": Js.nullable(string),
  "defaultMessage": string
};

type messages = array(message);

/* addLocaleData */
type localeData('t) = {.. "locale": string} as 't;

[@bs.module "react-intl"] external addLocaleData : localeData('t) => unit = "";

/* defineMessages */
type defineMessages('m) = [@bs] ('m => 'm);

[@bs.module "react-intl"]
external defineMessages : defineMessages(Js.t({..})) = "";

/* Formatters */
let mapOptBoolToJs = maybeBool =>
  Js.Option.map([@bs] (bool => bool |> Js.Boolean.to_js_boolean), maybeBool)
  |> Js.Nullable.from_opt;

type localeMatcher =
  | BestFitLocaleMatcher
  | LookupLocaleMatcher;

let mapReasonLocaleMatcherToJs = localeMatcher =>
  Js.Option.map(
    [@bs]
    (
      localeMatcher =>
        switch localeMatcher {
        | BestFitLocaleMatcher => "best fit"
        | LookupLocaleMatcher => "lookup"
        }
    ),
    localeMatcher
  )
  |> Js.Nullable.from_opt;

type formatMatcher =
  | BestFitFormatMatcher
  | BasicFormatMatcher;

let mapReasonFormatMatcherToJs = formatMatcher =>
  Js.Option.map(
    [@bs]
    (
      formatMatcher =>
        switch formatMatcher {
        | BestFitFormatMatcher => "best fit"
        | BasicFormatMatcher => "basic"
        }
    ),
    formatMatcher
  )
  |> Js.Nullable.from_opt;

type numeralFormat =
  | NumericNumeralFormat
  | TwoDigitNumeralFormat;

let mapReasonNumeralFormatToJs = numeralFormat =>
  Js.Option.map(
    [@bs]
    (
      numeralFormat =>
        switch numeralFormat {
        | NumericNumeralFormat => "numeric"
        | TwoDigitNumeralFormat => "2-digit"
        }
    ),
    numeralFormat
  )
  |> Js.Nullable.from_opt;

type textualFormat =
  | NarrowTextualFormat
  | ShortTextualFormat
  | LongTextualFormat;

let mapReasonTextualFormatToJs = textualFormat =>
  Js.Option.map(
    [@bs]
    (
      textualFormat =>
        switch textualFormat {
        | NarrowTextualFormat => "narrow"
        | ShortTextualFormat => "short"
        | LongTextualFormat => "long"
        }
    ),
    textualFormat
  )
  |> Js.Nullable.from_opt;

type mixedFormat =
  | NumericMixedFormat
  | TwoDigitMixedFormat
  | NarrowMixedFormat
  | ShortMixedFormat
  | LongMixedFormat;

let mapReasonMixedFormatToJs = mixedFormat =>
  Js.Option.map(
    [@bs]
    (
      mixedFormat =>
        switch mixedFormat {
        | NarrowMixedFormat => "narrow"
        | ShortMixedFormat => "short"
        | LongMixedFormat => "long"
        | NumericMixedFormat => "numeric"
        | TwoDigitMixedFormat => "2-digit"
        }
    ),
    mixedFormat
  )
  |> Js.Nullable.from_opt;

type timeZoneName =
  | ShortTimeZoneName
  | LongTimeZoneName;

let mapReasonTimeZoneNameToJs = timeZoneName =>
  Js.Option.map(
    [@bs]
    (
      timeZoneName =>
        switch timeZoneName {
        | ShortTimeZoneName => "short"
        | LongTimeZoneName => "long"
        }
    ),
    timeZoneName
  )
  |> Js.Nullable.from_opt;

type dateTimeFormatOptionsRe = {
  .
  "localeMatcher": option(localeMatcher),
  "formatMatcher": option(formatMatcher),
  "timeZone": option(string),
  "hour12": option(bool),
  "weekday": option(textualFormat),
  "era": option(textualFormat),
  "year": option(numeralFormat),
  "month": option(mixedFormat),
  "day": option(numeralFormat),
  "hour": option(numeralFormat),
  "minute": option(numeralFormat),
  "second": option(numeralFormat),
  "timeZoneName": option(timeZoneName),
  "format": option(string)
};

type dateTimeFormatOptionsJs = {
  .
  "localeMatcher": Js.nullable(string),
  "formatMatcher": Js.nullable(string),
  "timeZone": Js.nullable(string),
  "hour12": Js.nullable(Js.boolean),
  "weekday": Js.nullable(string),
  "era": Js.nullable(string),
  "year": Js.nullable(string),
  "month": Js.nullable(string),
  "day": Js.nullable(string),
  "hour": Js.nullable(string),
  "minute": Js.nullable(string),
  "second": Js.nullable(string),
  "timeZoneName": Js.nullable(string),
  "format": Js.nullable(string)
};

let mapReasonDateTimeFormatOptionsToJs =
    (options: dateTimeFormatOptionsRe)
    : dateTimeFormatOptionsJs => {
  "localeMatcher": options##localeMatcher |> mapReasonLocaleMatcherToJs,
  "formatMatcher": options##formatMatcher |> mapReasonFormatMatcherToJs,
  "timeZone": options##timeZone |> Js.Nullable.from_opt,
  "hour12": options##hour12 |> mapOptBoolToJs,
  "weekday": options##weekday |> mapReasonTextualFormatToJs,
  "era": options##era |> mapReasonTextualFormatToJs,
  "year": options##year |> mapReasonNumeralFormatToJs,
  "month": options##month |> mapReasonMixedFormatToJs,
  "day": options##day |> mapReasonNumeralFormatToJs,
  "hour": options##hour |> mapReasonNumeralFormatToJs,
  "minute": options##minute |> mapReasonNumeralFormatToJs,
  "second": options##second |> mapReasonNumeralFormatToJs,
  "timeZoneName": options##timeZoneName |> mapReasonTimeZoneNameToJs,
  "format": options##format |> Js.Nullable.from_opt
};

type relativeStyle =
  | BestFitRelativeStyle
  | NumericRelativeStyle;

let mapReasonRelativeStyleToJs = relativeStyle =>
  Js.Option.map(
    [@bs]
    (
      relativeStyle =>
        switch relativeStyle {
        | BestFitRelativeStyle => "best fit"
        | NumericRelativeStyle => "numeric"
        }
    ),
    relativeStyle
  )
  |> Js.Nullable.from_opt;

type units =
  | Second
  | Minute
  | Hour
  | Day
  | Month
  | Year;

let mapReasonUnitsToJs = units =>
  Js.Option.map(
    [@bs]
    (
      units =>
        switch units {
        | Second => "second"
        | Minute => "minute"
        | Hour => "hour"
        | Day => "day"
        | Month => "month"
        | Year => "year"
        }
    ),
    units
  )
  |> Js.Nullable.from_opt;

type relativeFormatOptionsRe = {
  .
  "style": option(relativeStyle),
  "units": option(units),
  "format": option(string),
  "now": option(int)
};

type relativeFormatOptionsJs = {
  .
  "style": Js.nullable(string),
  "units": Js.nullable(string),
  "format": Js.nullable(string),
  "now": Js.nullable(int)
};

let mapReasonRelativeFormatOptionsToJs =
    (options: relativeFormatOptionsRe)
    : relativeFormatOptionsJs => {
  "style": options##style |> mapReasonRelativeStyleToJs,
  "units": options##units |> mapReasonUnitsToJs,
  "format": options##format |> Js.Nullable.from_opt,
  "now": options##now |> Js.Nullable.from_opt
};

type numberStyle =
  | DecimalNumberStyle
  | CurrencyNumberStyle
  | PercentNumberStyle;

let mapReasonNumberStyleToJs = numberStyle =>
  Js.Option.map(
    [@bs]
    (
      numberStyle =>
        switch numberStyle {
        | DecimalNumberStyle => "decimal"
        | CurrencyNumberStyle => "currency"
        | PercentNumberStyle => "percent"
        }
    ),
    numberStyle
  )
  |> Js.Nullable.from_opt;

type currencyDisplay =
  | SymbolCurrencyDisplay
  | CodeCurrencyDisplay
  | NameCurrencyDisplay;

let mapReasonCurrencyDisplayToJs = currencyDisplay =>
  Js.Option.map(
    [@bs]
    (
      currencyDisplay =>
        switch currencyDisplay {
        | SymbolCurrencyDisplay => "symbol"
        | CodeCurrencyDisplay => "code"
        | NameCurrencyDisplay => "name"
        }
    ),
    currencyDisplay
  )
  |> Js.Nullable.from_opt;

type numberFormatOptionsRe = {
  .
  "localeMatcher": option(localeMatcher),
  "style": option(numberStyle),
  "currency": option(string),
  "currencyDisplay": option(currencyDisplay),
  "useGrouping": option(bool),
  "minimumIntegerDigits": option(int),
  "minimumFractionDigits": option(int),
  "maximumFractionDigits": option(int),
  "minimumSignificantDigits": option(int),
  "maximumSignificantDigits": option(int)
};

type numberFormatOptionsJs = {
  .
  "localeMatcher": Js.nullable(string),
  "style": Js.nullable(string),
  "currency": Js.nullable(string),
  "currencyDisplay": Js.nullable(string),
  "useGrouping": Js.nullable(Js.boolean),
  "minimumIntegerDigits": Js.nullable(int),
  "minimumFractionDigits": Js.nullable(int),
  "maximumFractionDigits": Js.nullable(int),
  "minimumSignificantDigits": Js.nullable(int),
  "maximumSignificantDigits": Js.nullable(int)
};

let mapReasonNumberFormatOptionsToJs = options => {
  "localeMatcher": options##localeMatcher |> mapReasonLocaleMatcherToJs,
  "style": options##style |> mapReasonNumberStyleToJs,
  "currency": options##currency |> Js.Nullable.from_opt,
  "currencyDisplay": options##currencyDisplay |> mapReasonCurrencyDisplayToJs,
  "useGrouping": options##useGrouping |> mapOptBoolToJs,
  "minimumIntegerDigits": options##minimumIntegerDigits |> Js.Nullable.from_opt,
  "minimumFractionDigits":
    options##minimumFractionDigits |> Js.Nullable.from_opt,
  "maximumFractionDigits":
    options##maximumFractionDigits |> Js.Nullable.from_opt,
  "minimumSignificantDigits":
    options##minimumSignificantDigits |> Js.Nullable.from_opt,
  "maximumSignificantDigits":
    options##maximumSignificantDigits |> Js.Nullable.from_opt
};

type pluralStyle =
  | CardinalPluralStyle
  | OrdinalPluralStyle;

let mapReasonPluralStyleToJs = pluralStyle =>
  Js.Option.map(
    [@bs]
    (
      pluralStyle =>
        switch pluralStyle {
        | CardinalPluralStyle => "cardinal"
        | OrdinalPluralStyle => "ordinal"
        }
    ),
    pluralStyle
  )
  |> Js.Nullable.from_opt;

type pluralFormatOptionsRe = {. "style": option(pluralStyle)};

type pluralFormatOptionsJs = {. "style": Js.nullable(string)};

let mapReasonPluralFormatOptionsToJs = options => {
  "style": options##style |> mapReasonPluralStyleToJs
};

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

let mapDomTagToString = tag =>
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

let mapOptDomTagToString = tag =>
  switch tag {
  | Some(tag) => Some(tag |> mapDomTagToString)
  | None => None
  };

module IntlProvider = {
  [@bs.module "react-intl"]
  external reactClass : ReasonReact.reactClass = "IntlProvider";
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
        "textComponent":
          textComponent |> mapOptDomTagToString |> Js.Nullable.from_opt,
        "initialNow": initialNow |> Js.Nullable.from_opt
      },
      children
    );
};

type intlJs('t) =
  {
    .
    "locale": string,
    "formats": Js.t({..}), /* TODO */
    "messages": Js.Dict.t(string),
    "defaultLocale": string,
    "defaultFormats": Js.t({..}), /* TODO */
    "formatDate":
      [@bs.meth] ((Js.Date.t, Js.nullable(dateTimeFormatOptionsJs)) => string),
    "formatTime":
      [@bs.meth] ((Js.Date.t, Js.nullable(dateTimeFormatOptionsJs)) => string),
    "formatRelative":
      [@bs.meth] ((Js.Date.t, Js.nullable(relativeFormatOptionsJs)) => string),
    "formatNumber":
      [@bs.meth] ((float, Js.nullable(numberFormatOptionsJs)) => string),
    "formatPlural":
      [@bs.meth] ((int, Js.nullable(pluralFormatOptionsJs)) => string),
    "formatMessage": [@bs.meth] ((message, Js.nullable(Js.t({..}))) => string),
    "formatHTMLMessage":
      [@bs.meth] ((message, Js.nullable(Js.t({..}))) => string),
    "now": [@bs.meth] (unit => int)
  } as 't;

type intl('t) = {
  locale: string,
  formats: Js.t({..} as 't), /* TODO */
  messages: Js.Dict.t(string),
  defaultLocale: string,
  defaultFormats: Js.t({..} as 't), /* TODO */
  formatDate: Js.Date.t => string,
  formatDateWithOptions: (Js.Date.t, dateTimeFormatOptionsRe) => string,
  formatTime: Js.Date.t => string,
  formatTimeWithOptions: (Js.Date.t, dateTimeFormatOptionsRe) => string,
  formatRelative: Js.Date.t => string,
  formatRelativeWithOptions: (Js.Date.t, relativeFormatOptionsRe) => string,
  formatInt: int => string,
  formatIntWithOptions: (int, numberFormatOptionsRe) => string,
  formatFloat: float => string,
  formatFloatWithOptions: (float, numberFormatOptionsRe) => string,
  formatPlural: int => string,
  formatPluralWithOptions: (int, pluralFormatOptionsRe) => string,
  formatMessage: message => string,
  formatMessageWithValues: (message, Js.t({..} as 't)) => string,
  formatHTMLMessage: message => string,
  formatHTMLMessageWithValues: (message, Js.t({..} as 't)) => string,
  now: unit => int
};

let mapIntlJsToReason = (intlJs: intlJs('t)) : intl('a) => {
  locale: intlJs##locale,
  formats: intlJs##formats,
  messages: intlJs##messages,
  defaultLocale: intlJs##defaultLocale,
  defaultFormats: intlJs##defaultFormats,
  formatDate: value => intlJs##formatDate(value, Js.Nullable.from_opt(None)),
  formatDateWithOptions: (value, options) =>
    intlJs##formatDate(
      value,
      Some(options |> mapReasonDateTimeFormatOptionsToJs)
      |> Js.Nullable.from_opt
    ),
  formatTime: value => intlJs##formatTime(value, Js.Nullable.from_opt(None)),
  formatTimeWithOptions: (value, options) =>
    intlJs##formatTime(
      value,
      Some(options |> mapReasonDateTimeFormatOptionsToJs)
      |> Js.Nullable.from_opt
    ),
  formatRelative: value =>
    intlJs##formatRelative(value, Js.Nullable.from_opt(None)),
  formatRelativeWithOptions: (value, options) =>
    intlJs##formatRelative(
      value,
      Some(options |> mapReasonRelativeFormatOptionsToJs)
      |> Js.Nullable.from_opt
    ),
  formatInt: value =>
    intlJs##formatNumber(value |> float_of_int, Js.Nullable.from_opt(None)),
  formatIntWithOptions: (value, options) =>
    intlJs##formatNumber(
      value |> float_of_int,
      Some(options |> mapReasonNumberFormatOptionsToJs) |> Js.Nullable.from_opt
    ),
  formatFloat: value => intlJs##formatNumber(value, Js.Nullable.from_opt(None)),
  formatFloatWithOptions: (value, options) =>
    intlJs##formatNumber(
      value,
      Some(options |> mapReasonNumberFormatOptionsToJs) |> Js.Nullable.from_opt
    ),
  formatPlural: value =>
    intlJs##formatPlural(value, Js.Nullable.from_opt(None)),
  formatPluralWithOptions: (value, options) =>
    intlJs##formatPlural(
      value,
      Some(options |> mapReasonPluralFormatOptionsToJs) |> Js.Nullable.from_opt
    ),
  formatMessage: message =>
    intlJs##formatMessage(message, Js.Nullable.from_opt(None)),
  formatMessageWithValues: (message, values) =>
    intlJs##formatMessage(message, Js.Nullable.from_opt(Some(values))),
  formatHTMLMessage: message =>
    intlJs##formatHTMLMessage(message, Js.Nullable.from_opt(None)),
  formatHTMLMessageWithValues: (message, values) =>
    intlJs##formatHTMLMessage(message, Js.Nullable.from_opt(Some(values))),
  now: () => intlJs##now()
};

module IntlInjector = {
  [@bs.module "./IntlInjector.js"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass, ~props=Js.Obj.empty(), (intlJs: intlJs('t)) =>
      children(mapIntlJsToReason(intlJs))
    );
};

module FormattedMessage = {
  [@bs.module "react-intl"]
  external reactClass : ReasonReact.reactClass = "FormattedMessage";
  type message('t) =
    {
      .
      "id": string,
      "defaultMessage": string
    } as 't;
  let make =
      (
        ~message: message('t),
        ~values: option(Js.t({..}))=?,
        ~tagName: option(domTag)=?,
        _
      ) =>
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
         let unicodeDefaultMessage =
           message##defaultMessage |> wrapUnicodeString;
         Js.Dict.set(
           dict,
           message##id,
           unicodeMessage !== "" ? unicodeMessage : unicodeDefaultMessage
         );
         dict;
       },
       Js.Dict.empty()
     );
