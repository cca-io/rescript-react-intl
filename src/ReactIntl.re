type dateTimeFormatOptions;

[@bs.obj]
external dateTimeFormatOptions:
  (
    ~localeMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `lookup]=?,
    ~formatMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `basic]=?,
    ~timeZone: string=?,
    ~hour12: bool=?,
    ~weekday: [@bs.string] [ | `narrow | `short | `long]=?,
    ~era: [@bs.string] [ | `narrow | `short | `long]=?,
    ~year: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
    ~month: [@bs.string] [
              | `numeric
              | [@bs.as "2-digit"] `twoDigit
              | `narrow
              | `short
              | `long
            ]
              =?,
    ~day: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
    ~hour: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
    ~minute: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
    ~second: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
    ~timeZoneName: [@bs.string] [ | `short | `long]=?,
    ~format: string=?,
    unit
  ) =>
  dateTimeFormatOptions;

type relativeTimeFormatOptions;

[@bs.obj]
external relativeTimeFormatOptions:
  (
    ~numeric: [@bs.string] [ | `always | `auto]=?,
    ~style: [@bs.string] [ | `long | `short | `narrow]=?,
    ~format: string=?,
    unit
  ) =>
  relativeTimeFormatOptions;

type numberFormatOptions;

[@bs.obj]
external numberFormatOptions:
  (
    ~localeMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `lookup]=?,
    ~style: [@bs.string] [ | `decimal | `currency | `percent]=?,
    ~currency: string=?,
    ~currencyDisplay: [@bs.string] [ | `symbol | `code | `name]=?,
    ~useGrouping: bool=?,
    ~minimumIntegerDigits: int=?,
    ~minimumFractionDigits: int=?,
    ~maximumFractionDigits: int=?,
    ~minimumSignificantDigits: int=?,
    ~maximumSignificantDigits: int=?,
    unit
  ) =>
  numberFormatOptions;

type pluralFormatOptions;

[@bs.obj]
external pluralFormatOptions:
  (~style: [@bs.string] [ | `cardinal | `ordinal]=?, unit) =>
  pluralFormatOptions;

type listFormatOptions;

[@bs.obj]
external listFormatOptions:
  (
    ~style: [@bs.string] [ | `long | `short | `narrow]=?,
    ~_type: [@bs.string] [ | `disjunction | `conjunction | `unit]=?,
    unit
  ) =>
  listFormatOptions;

type message = {
  .
  "id": string,
  "defaultMessage": string,
};

type translation = {
  .
  "id": string,
  "defaultMessage": string,
  "message": Js.nullable(string),
};

module Intl = {
  type t;

  [@bs.get] external locale: t => string = "locale";
  [@bs.get] [@bs.return nullable]
  external timeZone: t => option(string) = "timeZone";
  [@bs.get] external formats: t => Js.t({..}) = "formats";
  [@bs.get] external messages: t => Js.Dict.t(string) = "messages";
  [@bs.get] external defaultLocale: t => string = "defaultLocale";
  [@bs.get] external defaultFormats: t => Js.t({..}) = "defaultFormats";
  [@bs.send] external formatDate: (t, Js.Date.t) => string = "formatDate";
  [@bs.send]
  external formatDateWithOptions:
    (t, Js.Date.t, dateTimeFormatOptions) => string =
    "formatDate";
  [@bs.send] external formatTime: (t, Js.Date.t) => string = "formatTime";
  [@bs.send]
  external formatTimeWithOptions:
    (t, Js.Date.t, dateTimeFormatOptions) => string =
    "formatTime";
  [@bs.send]
  external formatRelativeTime: (t, float) => string = "formatRelativeTime";
  [@bs.send]
  external formatRelativeTimeWithUnit:
    (
      t,
      float,
      [@bs.string] [
        | `second
        | `minute
        | `hour
        | `day
        | `week
        | `month
        | `quarter
        | `year
      ]
    ) =>
    string =
    "formatRelativeTime";
  [@bs.send]
  external formatRelativeTimeWithUnitAndOptions:
    (
      t,
      float,
      [@bs.string] [
        | `second
        | `minute
        | `hour
        | `day
        | `week
        | `month
        | `quarter
        | `year
      ],
      relativeTimeFormatOptions
    ) =>
    string =
    "formatRelativeTime";
  [@bs.send] external formatNumber: (t, float) => string = "formatNumber";
  [@bs.send]
  external formatNumberWithOptions: (t, float, numberFormatOptions) => string =
    "formatNumber";
  [@bs.send] external formatPlural: (t, int) => string = "formatPlural";
  [@bs.send]
  external formatPluralWithOptions: (t, int, pluralFormatOptions) => string =
    "formatPlural";
  [@bs.send] external formatMessage: (t, message) => string = "formatMessage";
  [@bs.send]
  external formatMessageWithValues: (t, message, Js.t({..})) => string =
    "formatMessage";
  [@bs.send] external formatList: (t, array(string)) => string = "formatList";
  [@bs.send]
  external formatListWithOptions:
    (t, array(string), listFormatOptions) => string =
    "formatList";
  [@bs.send] external now: (t, unit) => int = "now";
};

[@bs.val] [@bs.module "react-intl"]
external context: React.Context.t(Intl.t) = "IntlContext";

[@bs.module "react-intl"] external useIntl: unit => Intl.t = "useIntl";

type textComponent;

external domTag: string => textComponent = "%identity";
external textComponent: React.component('props) => textComponent =
  "%identity";

type intlCache;

[@bs.module "react-intl"]
external createIntlCache: unit => intlCache = "createIntlCache";

type intlConfig;

[@bs.obj]
external intlConfig:
  (
    ~locale: string,
    ~timeZone: string=?,
    ~formats: Js.t({..})=?, /* TODO */
    ~textComponent: textComponent=?,
    ~messages: Js.Dict.t(string),
    ~defaultLocale: string=?,
    ~defaultFormats: Js.t({..})=?, /* TODO */
    ~onError: string => unit=?,
    unit
  ) =>
  intlConfig;

[@bs.module "react-intl"]
external createIntl: (intlConfig, intlCache) => Intl.t = "createIntl";

module RawIntlProvider = {
  [@react.component] [@bs.module "react-intl"]
  external make: (~value: Intl.t, ~children: React.element) => React.element =
    "RawIntlProvider";
};

module IntlProvider = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~locale: string=?,
      ~formats: Js.t({..})=?, /* TODO */
      ~messages: Js.Dict.t(string)=?,
      ~defaultLocale: string=?,
      ~defaultFormats: Js.t({..})=?, /* TODO */
      ~textComponent: textComponent=?,
      ~initialNow: int=?,
      ~onError: string => unit=?,
      ~children: React.element
    ) =>
    React.element =
    "IntlProvider";
};

module FormattedMessage = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~id: string,
      ~defaultMessage: string,
      ~values: Js.t({..})=?,
      ~tagName: string=?,
      ~children: (~formattedMessage: React.element) => React.element=?
    ) =>
    React.element =
    "FormattedMessage";
};

module FormattedDate = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~value: Js.Date.t,
      ~localeMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `lookup]
                        =?,
      ~formatMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `basic]=?,
      ~timeZone: string=?,
      ~hour12: bool=?,
      ~weekday: [@bs.string] [ | `narrow | `short | `long]=?,
      ~era: [@bs.string] [ | `narrow | `short | `long]=?,
      ~year: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~month: [@bs.string] [
                | `numeric
                | [@bs.as "2-digit"] `twoDigit
                | `narrow
                | `short
                | `long
              ]
                =?,
      ~day: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~hour: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~minute: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~second: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~timeZoneName: [@bs.string] [ | `short | `long]=?,
      ~format: string=?,
      ~children: (~formattedDate: string) => React.element=?
    ) =>
    React.element =
    "FormattedDate";
};

module FormattedTime = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~value: Js.Date.t,
      ~localeMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `lookup]
                        =?,
      ~formatMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `basic]=?,
      ~timeZone: string=?,
      ~hour12: bool=?,
      ~weekday: [@bs.string] [ | `narrow | `short | `long]=?,
      ~era: [@bs.string] [ | `narrow | `short | `long]=?,
      ~year: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~month: [@bs.string] [
                | `numeric
                | [@bs.as "2-digit"] `twoDigit
                | `narrow
                | `short
                | `long
              ]
                =?,
      ~day: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~hour: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~minute: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~second: [@bs.string] [ | `numeric | [@bs.as "2-digit"] `twoDigit]=?,
      ~timeZoneName: [@bs.string] [ | `short | `long]=?,
      ~format: string=?,
      ~children: (~formattedDate: string) => React.element=?
    ) =>
    React.element =
    "FormattedTime";
};

module FormattedRelativeTime = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~value: float,
      ~unit: [@bs.string] [
               | `second
               | `minute
               | `hour
               | `day
               | `week
               | `month
               | `quarter
               | `year
             ]
               =?,
      ~numeric: [@bs.string] [ | `always | `auto]=?,
      ~style: [@bs.string] [ | `long | `short | `narrow]=?,
      ~format: string=?,
      ~updateIntervalInSeconds: float=?,
      ~children: (~formattedDate: string) => React.element=?
    ) =>
    React.element =
    "FormattedRelativeTime";
};

module FormattedNumber = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~value: float,
      ~localeMatcher: [@bs.string] [ | [@bs.as "best fit"] `bestFit | `lookup]
                        =?,
      ~style: [@bs.string] [ | `decimal | `currency | `percent]=?,
      ~currency: string=?,
      ~currencyDisplay: [@bs.string] [ | `symbol | `code | `name]=?,
      ~useGrouping: bool=?,
      ~minimumIntegerDigits: int=?,
      ~minimumFractionDigits: int=?,
      ~maximumFractionDigits: int=?,
      ~minimumSignificantDigits: int=?,
      ~maximumSignificantDigits: int=?,
      ~format: string=?,
      ~children: (~formattedNumber: string) => React.element=?
    ) =>
    React.element =
    "FormattedNumber";
};

module FormattedPlural = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~value: int,
      ~style: [@bs.string] [ | `cardinal | `ordinal]=?,
      ~other: React.element,
      ~zero: React.element=?,
      ~one: React.element=?,
      ~two: React.element=?,
      ~few: React.element=?,
      ~many: React.element=?,
      ~children: (~formattedPlural: string) => React.element=?
    ) =>
    React.element =
    "FormattedPlural";
};

module FormattedList = {
  [@react.component] [@bs.module "react-intl"]
  external make:
    (
      ~value: array(string),
      ~style: [@bs.string] [ | `long | `short | `narrow]=?,
      ~_type: [@bs.string] [ | `disjunction | `conjunction | `unit]=?,
      ~children: (~formattedList: string) => React.element=?
    ) =>
    React.element =
    "FormattedList";
};
