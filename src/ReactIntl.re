/* Common */
type message = {
  .
  "id": string,
  "defaultMessage": string,
};

type jsonMessage = {
  .
  "id": string,
  "defaultMessage": string,
  "message": Js.nullable(string),
};

type jsonMessages = array(jsonMessage);

/* addLocaleData */
type localeData('t) = {.. "locale": string} as 't;

[@bs.module "react-intl"] external addLocaleData: localeData('t) => unit = "";

/* defineMessages */
type defineMessages('m) = (. 'm) => 'm;

[@bs.module "react-intl"]
external defineMessages: defineMessages(Js.t({..})) = "";

/* Formatters */
type localeMatcher =
  | BestFitLocaleMatcher
  | LookupLocaleMatcher;

let mapReasonLocaleMatcherToJs = localeMatcher =>
  Js.Option.map(
    (. localeMatcher) =>
      switch (localeMatcher) {
      | BestFitLocaleMatcher => "best fit"
      | LookupLocaleMatcher => "lookup"
      },
    localeMatcher,
  )
  |> Js.Nullable.fromOption;

type formatMatcher =
  | BestFitFormatMatcher
  | BasicFormatMatcher;

let mapReasonFormatMatcherToJs = formatMatcher =>
  Js.Option.map(
    (. formatMatcher) =>
      switch (formatMatcher) {
      | BestFitFormatMatcher => "best fit"
      | BasicFormatMatcher => "basic"
      },
    formatMatcher,
  )
  |> Js.Nullable.fromOption;

type numeralFormat =
  | NumericNumeralFormat
  | TwoDigitNumeralFormat;

let mapReasonNumeralFormatToJs = numeralFormat =>
  Js.Option.map(
    (. numeralFormat) =>
      switch (numeralFormat) {
      | NumericNumeralFormat => "numeric"
      | TwoDigitNumeralFormat => "2-digit"
      },
    numeralFormat,
  )
  |> Js.Nullable.fromOption;

type textualFormat =
  | NarrowTextualFormat
  | ShortTextualFormat
  | LongTextualFormat;

let mapReasonTextualFormatToJs = textualFormat =>
  Js.Option.map(
    (. textualFormat) =>
      switch (textualFormat) {
      | NarrowTextualFormat => "narrow"
      | ShortTextualFormat => "short"
      | LongTextualFormat => "long"
      },
    textualFormat,
  )
  |> Js.Nullable.fromOption;

type mixedFormat =
  | NumericMixedFormat
  | TwoDigitMixedFormat
  | NarrowMixedFormat
  | ShortMixedFormat
  | LongMixedFormat;

let mapReasonMixedFormatToJs = mixedFormat =>
  Js.Option.map(
    (. mixedFormat) =>
      switch (mixedFormat) {
      | NarrowMixedFormat => "narrow"
      | ShortMixedFormat => "short"
      | LongMixedFormat => "long"
      | NumericMixedFormat => "numeric"
      | TwoDigitMixedFormat => "2-digit"
      },
    mixedFormat,
  )
  |> Js.Nullable.fromOption;

type timeZoneName =
  | ShortTimeZoneName
  | LongTimeZoneName;

let mapReasonTimeZoneNameToJs = timeZoneName =>
  Js.Option.map(
    (. timeZoneName) =>
      switch (timeZoneName) {
      | ShortTimeZoneName => "short"
      | LongTimeZoneName => "long"
      },
    timeZoneName,
  )
  |> Js.Nullable.fromOption;

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
  "format": option(string),
};

type dateTimeFormatOptionsJs = {
  .
  "localeMatcher": Js.nullable(string),
  "formatMatcher": Js.nullable(string),
  "timeZone": Js.nullable(string),
  "hour12": Js.nullable(bool),
  "weekday": Js.nullable(string),
  "era": Js.nullable(string),
  "year": Js.nullable(string),
  "month": Js.nullable(string),
  "day": Js.nullable(string),
  "hour": Js.nullable(string),
  "minute": Js.nullable(string),
  "second": Js.nullable(string),
  "timeZoneName": Js.nullable(string),
  "format": Js.nullable(string),
};

let mapReasonDateTimeFormatOptionsToJs =
    (options: dateTimeFormatOptionsRe): dateTimeFormatOptionsJs => {
  "localeMatcher": options##localeMatcher |> mapReasonLocaleMatcherToJs,
  "formatMatcher": options##formatMatcher |> mapReasonFormatMatcherToJs,
  "timeZone": options##timeZone |> Js.Nullable.fromOption,
  "hour12": options##hour12 |> Js.Nullable.fromOption,
  "weekday": options##weekday |> mapReasonTextualFormatToJs,
  "era": options##era |> mapReasonTextualFormatToJs,
  "year": options##year |> mapReasonNumeralFormatToJs,
  "month": options##month |> mapReasonMixedFormatToJs,
  "day": options##day |> mapReasonNumeralFormatToJs,
  "hour": options##hour |> mapReasonNumeralFormatToJs,
  "minute": options##minute |> mapReasonNumeralFormatToJs,
  "second": options##second |> mapReasonNumeralFormatToJs,
  "timeZoneName": options##timeZoneName |> mapReasonTimeZoneNameToJs,
  "format": options##format |> Js.Nullable.fromOption,
};

type relativeStyle =
  | BestFitRelativeStyle
  | NumericRelativeStyle;

let mapReasonRelativeStyleToJs = relativeStyle =>
  Js.Option.map(
    (. relativeStyle) =>
      switch (relativeStyle) {
      | BestFitRelativeStyle => "best fit"
      | NumericRelativeStyle => "numeric"
      },
    relativeStyle,
  )
  |> Js.Nullable.fromOption;

type units =
  | Second
  | Minute
  | Hour
  | Day
  | Month
  | Year;

let mapReasonUnitsToJs = units =>
  Js.Option.map(
    (. units) =>
      switch (units) {
      | Second => "second"
      | Minute => "minute"
      | Hour => "hour"
      | Day => "day"
      | Month => "month"
      | Year => "year"
      },
    units,
  )
  |> Js.Nullable.fromOption;

type relativeFormatOptionsRe = {
  .
  "style": option(relativeStyle),
  "units": option(units),
  "format": option(string),
  "now": option(int),
};

type relativeFormatOptionsJs = {
  .
  "style": Js.nullable(string),
  "units": Js.nullable(string),
  "format": Js.nullable(string),
  "now": Js.nullable(int),
};

let mapReasonRelativeFormatOptionsToJs =
    (options: relativeFormatOptionsRe): relativeFormatOptionsJs => {
  "style": options##style |> mapReasonRelativeStyleToJs,
  "units": options##units |> mapReasonUnitsToJs,
  "format": options##format |> Js.Nullable.fromOption,
  "now": options##now |> Js.Nullable.fromOption,
};

type numberStyle =
  | DecimalNumberStyle
  | CurrencyNumberStyle
  | PercentNumberStyle;

let mapReasonNumberStyleToJs = numberStyle =>
  Js.Option.map(
    (. numberStyle) =>
      switch (numberStyle) {
      | DecimalNumberStyle => "decimal"
      | CurrencyNumberStyle => "currency"
      | PercentNumberStyle => "percent"
      },
    numberStyle,
  )
  |> Js.Nullable.fromOption;

type currencyDisplay =
  | SymbolCurrencyDisplay
  | CodeCurrencyDisplay
  | NameCurrencyDisplay;

let mapReasonCurrencyDisplayToJs = currencyDisplay =>
  Js.Option.map(
    (. currencyDisplay) =>
      switch (currencyDisplay) {
      | SymbolCurrencyDisplay => "symbol"
      | CodeCurrencyDisplay => "code"
      | NameCurrencyDisplay => "name"
      },
    currencyDisplay,
  )
  |> Js.Nullable.fromOption;

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
  "maximumSignificantDigits": option(int),
};

type numberFormatOptionsJs = {
  .
  "localeMatcher": Js.nullable(string),
  "style": Js.nullable(string),
  "currency": Js.nullable(string),
  "currencyDisplay": Js.nullable(string),
  "useGrouping": Js.nullable(bool),
  "minimumIntegerDigits": Js.nullable(int),
  "minimumFractionDigits": Js.nullable(int),
  "maximumFractionDigits": Js.nullable(int),
  "minimumSignificantDigits": Js.nullable(int),
  "maximumSignificantDigits": Js.nullable(int),
};

let mapReasonNumberFormatOptionsToJs = options => {
  "localeMatcher": options##localeMatcher |> mapReasonLocaleMatcherToJs,
  "style": options##style |> mapReasonNumberStyleToJs,
  "currency": options##currency |> Js.Nullable.fromOption,
  "currencyDisplay": options##currencyDisplay |> mapReasonCurrencyDisplayToJs,
  "useGrouping": options##useGrouping |> Js.Nullable.fromOption,
  "minimumIntegerDigits":
    options##minimumIntegerDigits |> Js.Nullable.fromOption,
  "minimumFractionDigits":
    options##minimumFractionDigits |> Js.Nullable.fromOption,
  "maximumFractionDigits":
    options##maximumFractionDigits |> Js.Nullable.fromOption,
  "minimumSignificantDigits":
    options##minimumSignificantDigits |> Js.Nullable.fromOption,
  "maximumSignificantDigits":
    options##maximumSignificantDigits |> Js.Nullable.fromOption,
};

type pluralStyle =
  | CardinalPluralStyle
  | OrdinalPluralStyle;

let mapReasonPluralStyleToJs = pluralStyle =>
  Js.Option.map(
    (. pluralStyle) =>
      switch (pluralStyle) {
      | CardinalPluralStyle => "cardinal"
      | OrdinalPluralStyle => "ordinal"
      },
    pluralStyle,
  )
  |> Js.Nullable.fromOption;

type pluralFormatOptionsRe = {. "style": option(pluralStyle)};

type pluralFormatOptionsJs = {. "style": Js.nullable(string)};

let mapReasonPluralFormatOptionsToJs = options => {
  "style": options##style |> mapReasonPluralStyleToJs,
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
  switch (tag) {
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
  switch (tag) {
  | Some(tag) => Some(tag |> mapDomTagToString)
  | None => None
  };

module IntlProvider = {
  [@bs.module "react-intl"]
  external reactClass: ReasonReact.reactClass = "IntlProvider";
  let make =
      (
        ~locale: option(string)=?,
        ~formats: option(Js.t({..}))=?, /* TODO */
        ~messages: option(Js.Dict.t(string))=?,
        ~defaultLocale: option(string)=?,
        ~defaultFormats: option(Js.t({..}))=?, /* TODO */
        ~textComponent: option(domTag)=?,
        ~initialNow: option(int)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "locale": locale |> Js.Nullable.fromOption,
        "formats": formats |> Js.Nullable.fromOption,
        "messages": messages |> Js.Nullable.fromOption,
        "defaultLocale": defaultLocale |> Js.Nullable.fromOption,
        "defaultFormats": defaultFormats |> Js.Nullable.fromOption,
        "textComponent":
          textComponent |> mapOptDomTagToString |> Js.Nullable.fromOption,
        "initialNow": initialNow |> Js.Nullable.fromOption,
      },
      children,
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
      [@bs.meth] (
        (Js.Date.t, Js.nullable(dateTimeFormatOptionsJs)) => string
      ),
    "formatTime":
      [@bs.meth] (
        (Js.Date.t, Js.nullable(dateTimeFormatOptionsJs)) => string
      ),
    "formatRelative":
      [@bs.meth] (
        (Js.Date.t, Js.nullable(relativeFormatOptionsJs)) => string
      ),
    "formatNumber":
      [@bs.meth] ((float, Js.nullable(numberFormatOptionsJs)) => string),
    "formatPlural":
      [@bs.meth] ((int, Js.nullable(pluralFormatOptionsJs)) => string),
    "formatMessage":
      [@bs.meth] ((message, Js.nullable(Js.t({..}))) => string),
    "formatHTMLMessage":
      [@bs.meth] ((message, Js.nullable(Js.t({..}))) => string),
    "now": [@bs.meth] (unit => int),
  } as 't;

type intl('t) = {
  locale: string,
  formats: Js.t({..} as 't), /* TODO */
  messages: Js.Dict.t(string),
  defaultLocale: string,
  defaultFormats: Js.t({..} as 't), /* TODO */
  formatDate: Js.Date.t => string,
  formatDateWithOptions: (dateTimeFormatOptionsRe, Js.Date.t) => string,
  formatTime: Js.Date.t => string,
  formatTimeWithOptions: (dateTimeFormatOptionsRe, Js.Date.t) => string,
  formatRelative: Js.Date.t => string,
  formatRelativeWithOptions: (relativeFormatOptionsRe, Js.Date.t) => string,
  formatInt: int => string,
  formatIntWithOptions: (numberFormatOptionsRe, int) => string,
  formatFloat: float => string,
  formatFloatWithOptions: (numberFormatOptionsRe, float) => string,
  formatPlural: int => string,
  formatPluralWithOptions: (pluralFormatOptionsRe, int) => string,
  formatMessage: message => string,
  formatMessageWithValues: (Js.t({..} as 't), message) => string,
  formatHTMLMessage: message => string,
  formatHTMLMessageWithValues: (Js.t({..} as 't), message) => string,
  now: unit => int,
};

let mapIntlJsToReason = (intlJs: intlJs('t)): intl('a) => {
  locale: intlJs##locale,
  formats: intlJs##formats,
  messages: intlJs##messages,
  defaultLocale: intlJs##defaultLocale,
  defaultFormats: intlJs##defaultFormats,
  formatDate: value =>
    intlJs##formatDate(value, None |> Js.Nullable.fromOption),
  formatDateWithOptions: (options, value) =>
    intlJs##formatDate(
      value,
      Some(options |> mapReasonDateTimeFormatOptionsToJs)
      |> Js.Nullable.fromOption,
    ),
  formatTime: value =>
    intlJs##formatTime(value, None |> Js.Nullable.fromOption),
  formatTimeWithOptions: (options, value) =>
    intlJs##formatTime(
      value,
      Some(options |> mapReasonDateTimeFormatOptionsToJs)
      |> Js.Nullable.fromOption,
    ),
  formatRelative: value =>
    intlJs##formatRelative(value, None |> Js.Nullable.fromOption),
  formatRelativeWithOptions: (options, value) =>
    intlJs##formatRelative(
      value,
      Some(options |> mapReasonRelativeFormatOptionsToJs)
      |> Js.Nullable.fromOption,
    ),
  formatInt: value =>
    intlJs##formatNumber(
      value |> float_of_int,
      None |> Js.Nullable.fromOption,
    ),
  formatIntWithOptions: (options, value) =>
    intlJs##formatNumber(
      value |> float_of_int,
      Some(options |> mapReasonNumberFormatOptionsToJs)
      |> Js.Nullable.fromOption,
    ),
  formatFloat: value =>
    intlJs##formatNumber(value, None |> Js.Nullable.fromOption),
  formatFloatWithOptions: (options, value) =>
    intlJs##formatNumber(
      value,
      Some(options |> mapReasonNumberFormatOptionsToJs)
      |> Js.Nullable.fromOption,
    ),
  formatPlural: value =>
    intlJs##formatPlural(value, None |> Js.Nullable.fromOption),
  formatPluralWithOptions: (options, value) =>
    intlJs##formatPlural(
      value,
      Some(options |> mapReasonPluralFormatOptionsToJs)
      |> Js.Nullable.fromOption,
    ),
  formatMessage: message =>
    intlJs##formatMessage(message, None |> Js.Nullable.fromOption),
  formatMessageWithValues: (values, message) =>
    intlJs##formatMessage(message, Some(values) |> Js.Nullable.fromOption),
  formatHTMLMessage: message =>
    intlJs##formatHTMLMessage(message, None |> Js.Nullable.fromOption),
  formatHTMLMessageWithValues: (values, message) =>
    intlJs##formatHTMLMessage(
      message,
      Some(values) |> Js.Nullable.fromOption,
    ),
  now: () => intlJs##now(),
};

module IntlInjector = {
  let reactClass: ReasonReact.reactClass = [%bs.raw
    {|
    require("react-intl").injectIntl(function(_ref) {
      var intl = _ref.intl, children = _ref.children;
      return children(intl);
    })
    |}
  ];
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass, ~props=Js.Obj.empty(), (intlJs: intlJs('t)) =>
      children(mapIntlJsToReason(intlJs))
    );
};

module FormattedMessage = {
  [@bs.module "react-intl"]
  external reactClass: ReasonReact.reactClass = "FormattedMessage";
  let make =
      (
        ~id: string,
        ~defaultMessage: string,
        ~values: option(Js.t({..}))=?,
        ~tagName: option(domTag)=?,
        _,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "id": id,
        "defaultMessage": defaultMessage,
        "values": values |> Js.Nullable.fromOption,
        "tagName": tagName |> mapOptDomTagToString |> Js.Nullable.fromOption,
      },
      [||],
    );
};

/* DefinedMessage is another wrapper for FormattedMessage.
   It takes the id and defaultMessage props from a passed message object. */
module DefinedMessage = {
  [@bs.module "react-intl"]
  external reactClass: ReasonReact.reactClass = "FormattedMessage";
  let make =
      (
        ~message: message,
        ~values: option(Js.t({..}))=?,
        ~tagName: option(domTag)=?,
        _,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "id": message##id,
        "defaultMessage": message##defaultMessage,
        "values": values |> Js.Nullable.fromOption,
        "tagName": tagName |> mapOptDomTagToString |> Js.Nullable.fromOption,
      },
      [||],
    );
};

module FormattedDate = {
  [@bs.module "react-intl"]
  external reactClass: ReasonReact.reactClass = "FormattedDate";
  let make =
      (
        ~value: Js.Date.t,
        ~format: option(string)=?,
        ~localeMatcher: option(localeMatcher)=?,
        ~formatMatcher: option(formatMatcher)=?,
        ~timeZone: option(string)=?,
        ~hour12: option(bool)=?,
        ~weekday: option(textualFormat)=?,
        ~era: option(textualFormat)=?,
        ~year: option(numeralFormat)=?,
        ~month: option(mixedFormat)=?,
        ~day: option(numeralFormat)=?,
        ~hour: option(numeralFormat)=?,
        ~minute: option(numeralFormat)=?,
        ~second: option(numeralFormat)=?,
        ~timeZoneName: option(timeZoneName)=?,
        _,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": value,
        "format": format |> Js.Nullable.fromOption,
        "localeMatcher": localeMatcher |> mapReasonLocaleMatcherToJs,
        "formatMatcher": formatMatcher |> mapReasonFormatMatcherToJs,
        "timeZone": timeZone |> Js.Nullable.fromOption,
        "hour12": hour12 |> Js.Nullable.fromOption,
        "weekday": weekday |> mapReasonTextualFormatToJs,
        "era": era |> mapReasonTextualFormatToJs,
        "year": year |> mapReasonNumeralFormatToJs,
        "month": month |> mapReasonMixedFormatToJs,
        "day": day |> mapReasonNumeralFormatToJs,
        "hour": hour |> mapReasonNumeralFormatToJs,
        "minute": minute |> mapReasonNumeralFormatToJs,
        "second": second |> mapReasonNumeralFormatToJs,
        "timeZoneName": timeZoneName |> mapReasonTimeZoneNameToJs,
      },
      [||],
    );
};

module FormattedTime = {
  [@bs.module "react-intl"]
  external reactClass: ReasonReact.reactClass = "FormattedTime";
  let make =
      (
        ~value: Js.Date.t,
        ~format: option(string)=?,
        ~localeMatcher: option(localeMatcher)=?,
        ~formatMatcher: option(formatMatcher)=?,
        ~timeZone: option(string)=?,
        ~hour12: option(bool)=?,
        ~weekday: option(textualFormat)=?,
        ~era: option(textualFormat)=?,
        ~year: option(numeralFormat)=?,
        ~month: option(mixedFormat)=?,
        ~day: option(numeralFormat)=?,
        ~hour: option(numeralFormat)=?,
        ~minute: option(numeralFormat)=?,
        ~second: option(numeralFormat)=?,
        ~timeZoneName: option(timeZoneName)=?,
        _,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": value,
        "format": format |> Js.Nullable.fromOption,
        "localeMatcher": localeMatcher |> mapReasonLocaleMatcherToJs,
        "formatMatcher": formatMatcher |> mapReasonFormatMatcherToJs,
        "timeZone": timeZone |> Js.Nullable.fromOption,
        "hour12": hour12 |> Js.Nullable.fromOption,
        "weekday": weekday |> mapReasonTextualFormatToJs,
        "era": era |> mapReasonTextualFormatToJs,
        "year": year |> mapReasonNumeralFormatToJs,
        "month": month |> mapReasonMixedFormatToJs,
        "day": day |> mapReasonNumeralFormatToJs,
        "hour": hour |> mapReasonNumeralFormatToJs,
        "minute": minute |> mapReasonNumeralFormatToJs,
        "second": second |> mapReasonNumeralFormatToJs,
        "timeZoneName": timeZoneName |> mapReasonTimeZoneNameToJs,
      },
      [||],
    );
};

/* Utils */
let wrapUnicodeString = (input: string) => {j|$input|j};

let wrapOptUnicodeString = (input: Js.nullable(string)) =>
  switch (input |> Js.Nullable.toOption) {
  | Some(input) => input |> wrapUnicodeString
  | None => ""
  };

let messagesArrayToDict = (translation: jsonMessages) =>
  translation
  |> Array.fold_left(
       (dict, message) => {
         let unicodeMessage = message##message |> wrapOptUnicodeString;
         let unicodeDefaultMessage =
           message##defaultMessage |> wrapUnicodeString;
         Js.Dict.set(
           dict,
           message##id,
           unicodeMessage !== "" ? unicodeMessage : unicodeDefaultMessage,
         );
         dict;
       },
       Js.Dict.empty(),
     );
