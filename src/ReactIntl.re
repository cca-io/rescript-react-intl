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
  );

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
  );

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
  );

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
  );

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
  );

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
  );

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
  "localeMatcher": option(string),
  "formatMatcher": option(string),
  "timeZone": option(string),
  "hour12": option(bool),
  "weekday": option(string),
  "era": option(string),
  "year": option(string),
  "month": option(string),
  "day": option(string),
  "hour": option(string),
  "minute": option(string),
  "second": option(string),
  "timeZoneName": option(string),
  "format": option(string),
};

let mapReasonDateTimeFormatOptionsToJs =
    (options: dateTimeFormatOptionsRe): dateTimeFormatOptionsJs => {
  "localeMatcher": options##localeMatcher->mapReasonLocaleMatcherToJs,
  "formatMatcher": options##formatMatcher->mapReasonFormatMatcherToJs,
  "timeZone": options##timeZone,
  "hour12": options##hour12,
  "weekday": options##weekday->mapReasonTextualFormatToJs,
  "era": options##era->mapReasonTextualFormatToJs,
  "year": options##year->mapReasonNumeralFormatToJs,
  "month": options##month->mapReasonMixedFormatToJs,
  "day": options##day->mapReasonNumeralFormatToJs,
  "hour": options##hour->mapReasonNumeralFormatToJs,
  "minute": options##minute->mapReasonNumeralFormatToJs,
  "second": options##second->mapReasonNumeralFormatToJs,
  "timeZoneName": options##timeZoneName->mapReasonTimeZoneNameToJs,
  "format": options##format,
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
  );

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
  );

type relativeFormatOptionsRe = {
  .
  "style": option(relativeStyle),
  "units": option(units),
  "format": option(string),
  "now": option(int),
};

type relativeFormatOptionsJs = {
  .
  "style": option(string),
  "units": option(string),
  "format": option(string),
  "now": option(int),
};

let mapReasonRelativeFormatOptionsToJs =
    (options: relativeFormatOptionsRe): relativeFormatOptionsJs => {
  "style": options##style->mapReasonRelativeStyleToJs,
  "units": options##units->mapReasonUnitsToJs,
  "format": options##format,
  "now": options##now,
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
  );

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
  );

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
  "localeMatcher": option(string),
  "style": option(string),
  "currency": option(string),
  "currencyDisplay": option(string),
  "useGrouping": option(bool),
  "minimumIntegerDigits": option(int),
  "minimumFractionDigits": option(int),
  "maximumFractionDigits": option(int),
  "minimumSignificantDigits": option(int),
  "maximumSignificantDigits": option(int),
};

let mapReasonNumberFormatOptionsToJs =
    (options: numberFormatOptionsRe): numberFormatOptionsJs => {
  "localeMatcher": options##localeMatcher->mapReasonLocaleMatcherToJs,
  "style": options##style->mapReasonNumberStyleToJs,
  "currency": options##currency,
  "currencyDisplay": options##currencyDisplay->mapReasonCurrencyDisplayToJs,
  "useGrouping": options##useGrouping,
  "minimumIntegerDigits": options##minimumIntegerDigits,
  "minimumFractionDigits": options##minimumFractionDigits,
  "maximumFractionDigits": options##maximumFractionDigits,
  "minimumSignificantDigits": options##minimumSignificantDigits,
  "maximumSignificantDigits": options##maximumSignificantDigits,
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
  );

type pluralFormatOptionsRe = {. "style": option(pluralStyle)};

type pluralFormatOptionsJs = {. "style": option(string)};

let mapReasonPluralFormatOptionsToJs = options => {
  "style": options##style->mapReasonPluralStyleToJs,
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

type textComponent('props) =
  | DomTag(domTag)
  | ReactComponent(React.component('props));

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
  | Some(tag) => Some(tag->mapDomTagToString)
  | None => None
  };

let mapTextComponentToJs = textComponent =>
  switch (textComponent) {
  | DomTag(domTag) => domTag->mapDomTagToString->Obj.magic
  | ReactComponent(reactComponent) => reactComponent->Obj.magic
  };

let mapOptTextComponentToJs = textComponent =>
  textComponent->Belt.Option.map(mapTextComponentToJs);

type errorHandler = string => unit;

module IntlProvider = {
  type props('a, 'b) = {
    .
    "locale": option(string),
    "formats": option(Js.t({..} as 'a)), /* TODO */
    "messages": option(Js.Dict.t(string)),
    "defaultLocale": option(string),
    "defaultFormats": option(Js.t({..} as 'a)), /* TODO */
    "textComponent": option(textComponent('b)),
    "initialNow": option(int),
    "onError": option(errorHandler),
  };

  [@bs.obj]
  external makeProps:
    (
      ~locale: string=?,
      ~formats: Js.t({..} as 'a)=?, /* TODO */
      ~messages: Js.Dict.t(string)=?,
      ~defaultLocale: string=?,
      ~defaultFormats: Js.t({..} as 'a)=?, /* TODO */
      ~textComponent: option(textComponent('b))=?,
      ~initialNow: int=?,
      ~onError: errorHandler=?,
      ~children: React.element,
      ~key: string=?,
      unit
    ) =>
    props('a, 'b) =
    "";

  let makeProps =
      (
        ~locale=?,
        ~formats=?,
        ~messages=?,
        ~defaultLocale=?,
        ~defaultFormats=?,
        ~textComponent=?,
        ~initialNow=?,
        ~onError=?,
        ~children,
        ~key=?,
        (),
      ) =>
    makeProps(
      ~locale?,
      ~formats?,
      ~messages?,
      ~defaultLocale?,
      ~defaultFormats?,
      ~textComponent=?textComponent->mapOptTextComponentToJs,
      ~initialNow?,
      ~onError?,
      ~children,
      ~key?,
      (),
    );

  [@bs.module "react-intl"]
  external make: React.component(props('a, 'b)) = "IntlProvider";
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
        (Js.Date.t, Js.undefined(dateTimeFormatOptionsJs)) => string
      ),
    "formatTime":
      [@bs.meth] (
        (Js.Date.t, Js.undefined(dateTimeFormatOptionsJs)) => string
      ),
    "formatRelative":
      [@bs.meth] (
        (Js.Date.t, Js.undefined(relativeFormatOptionsJs)) => string
      ),
    "formatNumber":
      [@bs.meth] ((float, Js.undefined(numberFormatOptionsJs)) => string),
    "formatPlural":
      [@bs.meth] ((int, Js.undefined(pluralFormatOptionsJs)) => string),
    "formatMessage":
      [@bs.meth] ((message, Js.undefined(Js.t({..}))) => string),
    "formatHTMLMessage":
      [@bs.meth] ((message, Js.undefined(Js.t({..}))) => string),
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
  formatDate: value => intlJs##formatDate(value, Js.undefined),
  formatDateWithOptions: (options, value) =>
    intlJs##formatDate(
      value,
      Some(options->mapReasonDateTimeFormatOptionsToJs)
      ->Js.Undefined.fromOption,
    ),
  formatTime: value => intlJs##formatTime(value, Js.undefined),
  formatTimeWithOptions: (options, value) =>
    intlJs##formatTime(
      value,
      Some(options->mapReasonDateTimeFormatOptionsToJs)
      ->Js.Undefined.fromOption,
    ),
  formatRelative: value => intlJs##formatRelative(value, Js.undefined),
  formatRelativeWithOptions: (options, value) =>
    intlJs##formatRelative(
      value,
      Some(options->mapReasonRelativeFormatOptionsToJs)
      ->Js.Undefined.fromOption,
    ),
  formatInt: value => intlJs##formatNumber(value->float_of_int, Js.undefined),
  formatIntWithOptions: (options, value) =>
    intlJs##formatNumber(
      value->float_of_int,
      Some(options->mapReasonNumberFormatOptionsToJs)
      ->Js.Undefined.fromOption,
    ),
  formatFloat: value => intlJs##formatNumber(value, Js.undefined),
  formatFloatWithOptions: (options, value) =>
    intlJs##formatNumber(
      value,
      Some(options->mapReasonNumberFormatOptionsToJs)
      ->Js.Undefined.fromOption,
    ),
  formatPlural: value => intlJs##formatPlural(value, Js.undefined),
  formatPluralWithOptions: (options, value) =>
    intlJs##formatPlural(
      value,
      Some(options->mapReasonPluralFormatOptionsToJs)
      ->Js.Undefined.fromOption,
    ),
  formatMessage: message => intlJs##formatMessage(message, Js.undefined),
  formatMessageWithValues: (values, message) =>
    intlJs##formatMessage(message, Some(values)->Js.Undefined.fromOption),
  formatHTMLMessage: message =>
    intlJs##formatHTMLMessage(message, Js.undefined),
  formatHTMLMessageWithValues: (values, message) =>
    intlJs##formatHTMLMessage(
      message,
      Some(values)->Js.Undefined.fromOption,
    ),
  now: () => intlJs##now(),
};

[@bs.module "react-intl"] external useIntl: unit => intlJs('t) = "useIntl";
let useIntl = () => useIntl()->mapIntlJsToReason;

module FormattedMessage = {
  [@bs.module "react-intl"] [@react.component]
  external make:
    (
      ~id: string,
      ~defaultMessage: string,
      ~values: Js.t({..}) as 'a=?,
      ~tagName: [@bs.string] [
                  | `span
                  | `div
                  | `p
                  | `h1
                  | `h2
                  | `h3
                  | `h4
                  | `h5
                  | `h6
                  | `strong
                  | `b
                  | `i
                  | `em
                  | `mark
                  | `small
                  | `del
                  | `ins
                  | `sub
                  | `sup
                ]
                  =?
    ) =>
    React.element =
    "FormattedMessage";
};

// DefinedMessage is another wrapper for FormattedMessage.
// It takes the id and defaultMessage props from a passed message object.
module DefinedMessage = {
  let make = FormattedMessage.make;
  let makeProps = (~message: message, ~values=?, ~tagName=?, ~key=?, ()) =>
    FormattedMessage.makeProps(
      ~id=message##id,
      ~defaultMessage=message##defaultMessage,
      ~values?,
      ~tagName?,
      ~key?,
      (),
    );
};

module FormattedDate = {
  type props = {
    .
    "value": Js.Date.t,
    "format": option(string),
    "localeMatcher": option(string),
    "formatMatcher": option(string),
    "timeZone": option(string),
    "hour12": option(bool),
    "weekday": option(string),
    "era": option(string),
    "year": option(string),
    "month": option(string),
    "day": option(string),
    "hour": option(string),
    "minute": option(string),
    "second": option(string),
    "timeZoneName": option(string),
  };

  [@bs.obj]
  external makeProps:
    (
      ~value: Js.Date.t,
      ~format: string=?,
      ~localeMatcher: string=?,
      ~formatMatcher: string=?,
      ~timeZone: string=?,
      ~hour12: bool=?,
      ~weekday: string=?,
      ~era: string=?,
      ~year: string=?,
      ~month: string=?,
      ~day: string=?,
      ~hour: string=?,
      ~minute: string=?,
      ~second: string=?,
      ~timeZoneName: string=?,
      ~key: string=?,
      unit
    ) =>
    props =
    "";

  let makeProps =
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
        ~key=?,
        (),
      ) =>
    makeProps(
      ~value,
      ~format?,
      ~localeMatcher=?localeMatcher->mapReasonLocaleMatcherToJs,
      ~formatMatcher=?formatMatcher->mapReasonFormatMatcherToJs,
      ~timeZone?,
      ~hour12?,
      ~weekday=?weekday->mapReasonTextualFormatToJs,
      ~era=?era->mapReasonTextualFormatToJs,
      ~year=?year->mapReasonNumeralFormatToJs,
      ~month=?month->mapReasonMixedFormatToJs,
      ~day=?day->mapReasonNumeralFormatToJs,
      ~hour=?hour->mapReasonNumeralFormatToJs,
      ~minute=?minute->mapReasonNumeralFormatToJs,
      ~second=?second->mapReasonNumeralFormatToJs,
      ~timeZoneName=?timeZoneName->mapReasonTimeZoneNameToJs,
      ~key?,
      (),
    );

  [@bs.module "react-intl"]
  external make: React.component(props) = "FormattedDate";
};

module FormattedTime = {
  type props = {
    .
    "value": Js.Date.t,
    "format": option(string),
    "localeMatcher": option(string),
    "formatMatcher": option(string),
    "timeZone": option(string),
    "hour12": option(bool),
    "weekday": option(string),
    "era": option(string),
    "year": option(string),
    "month": option(string),
    "day": option(string),
    "hour": option(string),
    "minute": option(string),
    "second": option(string),
    "timeZoneName": option(string),
  };

  [@bs.obj]
  external makeProps:
    (
      ~value: Js.Date.t,
      ~format: string=?,
      ~localeMatcher: string=?,
      ~formatMatcher: string=?,
      ~timeZone: string=?,
      ~hour12: bool=?,
      ~weekday: string=?,
      ~era: string=?,
      ~year: string=?,
      ~month: string=?,
      ~day: string=?,
      ~hour: string=?,
      ~minute: string=?,
      ~second: string=?,
      ~timeZoneName: string=?,
      ~key: string=?,
      unit
    ) =>
    props =
    "";

  let makeProps =
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
        ~key=?,
        (),
      ) =>
    makeProps(
      ~value,
      ~format?,
      ~localeMatcher=?localeMatcher->mapReasonLocaleMatcherToJs,
      ~formatMatcher=?formatMatcher->mapReasonFormatMatcherToJs,
      ~timeZone?,
      ~hour12?,
      ~weekday=?weekday->mapReasonTextualFormatToJs,
      ~era=?era->mapReasonTextualFormatToJs,
      ~year=?year->mapReasonNumeralFormatToJs,
      ~month=?month->mapReasonMixedFormatToJs,
      ~day=?day->mapReasonNumeralFormatToJs,
      ~hour=?hour->mapReasonNumeralFormatToJs,
      ~minute=?minute->mapReasonNumeralFormatToJs,
      ~second=?second->mapReasonNumeralFormatToJs,
      ~timeZoneName=?timeZoneName->mapReasonTimeZoneNameToJs,
      ~key?,
      (),
    );

  [@bs.module "react-intl"]
  external make: React.component(props) = "FormattedDate";
};

/* Utils */
let wrapUnicodeString = (input: string) => {j|$input|j};

let wrapOptUnicodeString = (input: Js.nullable(string)) =>
  switch (input->Js.Nullable.toOption) {
  | Some(input) => input->wrapUnicodeString
  | None => ""
  };

let messagesArrayToDict = (translation: jsonMessages) =>
  translation->Belt.Array.reduce(
    Js.Dict.empty(),
    (dict, message) => {
      let unicodeMessage = message##message->wrapOptUnicodeString;
      let unicodeDefaultMessage = message##defaultMessage->wrapUnicodeString;
      Js.Dict.set(
        dict,
        message##id,
        unicodeMessage !== "" ? unicodeMessage : unicodeDefaultMessage,
      );
      dict;
    },
  );
