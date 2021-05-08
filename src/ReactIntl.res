type dateTimeFormatOptions

@obj
external dateTimeFormatOptions: (
  ~localeMatcher: [#"best fit" | #lookup]=?,
  ~formatMatcher: [#"best fit" | #basic]=?,
  ~timeZone: string=?,
  ~hour12: bool=?,
  ~weekday: [#narrow | #short | #long]=?,
  ~era: [#narrow | #short | #long]=?,
  ~year: [#numeric | #"2-digit"]=?,
  ~month: [
    | #numeric
    | #"2-digit"
    | #narrow
    | #short
    | #long
  ]=?,
  ~day: [#numeric | #"2-digit"]=?,
  ~hour: [#numeric | #"2-digit"]=?,
  ~minute: [#numeric | #"2-digit"]=?,
  ~second: [#numeric | #"2-digit"]=?,
  ~timeZoneName: [#short | #long]=?,
  ~format: string=?,
  unit,
) => dateTimeFormatOptions = ""

type relativeTimeFormatOptions

@obj
external relativeTimeFormatOptions: (
  ~numeric: [#always | #auto]=?,
  ~style: [#long | #short | #narrow]=?,
  ~format: string=?,
  unit,
) => relativeTimeFormatOptions = ""

type numberFormatOptions

@obj
external numberFormatOptions: (
  ~localeMatcher: [#"best fit" | #lookup]=?,
  ~style: [#decimal | #currency | #percent]=?,
  ~currency: string=?,
  ~currencyDisplay: [#symbol | #code | #name]=?,
  ~useGrouping: bool=?,
  ~minimumIntegerDigits: int=?,
  ~minimumFractionDigits: int=?,
  ~maximumFractionDigits: int=?,
  ~minimumSignificantDigits: int=?,
  ~maximumSignificantDigits: int=?,
  unit,
) => numberFormatOptions = ""

type pluralFormatOptions

@obj
external pluralFormatOptions: (~style: [#cardinal | #ordinal]=?, unit) => pluralFormatOptions = ""

type listFormatOptions

@obj
external listFormatOptions: (
  ~style: [#long | #short | #narrow]=?,
  ~_type: [#disjunction | #conjunction | #unit]=?,
  unit,
) => listFormatOptions = ""

type displayNameFormatOptions

@obj
external displayNameFormatOptions: (
  ~style: [#long | #short | #narrow]=?,
  ~_type: [#language | #region | #script | #currency]=?,
  ~fallback: [#code | #none]=?,
) => displayNameFormatOptions = ""

type message = {
  id: string,
  defaultMessage: string,
}

type part = {
  @as("type")
  type_: string,
  value: string,
}

module Intl = {
  type t

  @get external locale: t => string = "locale"
  @get @return(nullable)
  external timeZone: t => option<string> = "timeZone"
  @get external formats: t => {..} = "formats"
  @get external messages: t => Js.Dict.t<string> = "messages"
  @get external defaultLocale: t => string = "defaultLocale"
  @get external defaultFormats: t => {..} = "defaultFormats"
  @send external formatDate: (t, Js.Date.t) => string = "formatDate"
  @send
  external formatDateToParts: (t, Js.Date.t) => array<part> = "formatDateToParts"
  @send
  external formatDateWithOptions: (t, Js.Date.t, dateTimeFormatOptions) => string = "formatDate"
  @send
  external formatDateWithOptionsToParts: (t, Js.Date.t, dateTimeFormatOptions) => array<part> =
    "formatDateToParts"
  @send external formatTime: (t, Js.Date.t) => string = "formatTime"
  @send
  external formatTimeToParts: (t, Js.Date.t) => array<part> = "formatTimeToParts"
  @send
  external formatTimeWithOptions: (t, Js.Date.t, dateTimeFormatOptions) => string = "formatTime"
  @send
  external formatTimeWithOptionsToParts: (t, Js.Date.t, dateTimeFormatOptions) => array<part> =
    "formatTimeToParts"
  @send
  external formatRelativeTime: (t, float) => string = "formatRelativeTime"
  @send
  external formatRelativeTimeWithUnit: (
    t,
    float,
    [
      | #second
      | #minute
      | #hour
      | #day
      | #week
      | #month
      | #quarter
      | #year
    ],
  ) => string = "formatRelativeTime"
  @send
  external formatRelativeTimeWithUnitAndOptions: (
    t,
    float,
    [
      | #second
      | #minute
      | #hour
      | #day
      | #week
      | #month
      | #quarter
      | #year
    ],
    relativeTimeFormatOptions,
  ) => string = "formatRelativeTime"
  @send external formatNumber: (t, float) => string = "formatNumber"
  @send
  external formatNumberToParts: (t, float) => array<part> = "formatNumberToParts"
  @send
  external formatNumberWithOptions: (t, float, numberFormatOptions) => string = "formatNumber"
  @send
  external formatNumberWithOptionsToParts: (t, float, numberFormatOptions) => array<part> =
    "formatNumberToParts"
  @send external formatPlural: (t, int) => string = "formatPlural"
  @send
  external formatPluralWithOptions: (t, int, pluralFormatOptions) => string = "formatPlural"
  @send external formatMessage: (t, message) => string = "formatMessage"
  @send
  external formatMessageWithValues: (t, message, {..}) => string = "formatMessage"
  @send external formatList: (t, array<string>) => string = "formatList"
  @send
  external formatListWithOptions: (t, array<string>, listFormatOptions) => string = "formatList"
  @send
  external formatDisplayName: (t, string) => string = "formatDisplayName"
  @send
  external formatDisplayNameWithOptions: (t, string, displayNameFormatOptions) => string =
    "formatDisplayName"
}

@val @module("react-intl")
external context: React.Context.t<Intl.t> = "IntlContext"

@module("react-intl") external useIntl: unit => Intl.t = "useIntl"

type textComponent

external domTag: string => textComponent = "%identity"
external textComponent: React.component<'props> => textComponent = "%identity"

type intlCache

@module("react-intl")
external createIntlCache: unit => intlCache = "createIntlCache"

type intlConfig

@obj
external intlConfig: (
  ~locale: string,
  ~timeZone: string=?,
  ~formats: {..}=? /* TODO */,
  ~textComponent: textComponent=?,
  ~messages: Js.Dict.t<string>,
  ~defaultLocale: string=?,
  ~defaultFormats: {..}=? /* TODO */,
  ~onError: string => unit=?,
  unit,
) => intlConfig = ""

@module("react-intl")
external createIntl: (intlConfig, intlCache) => Intl.t = "createIntl"

module RawIntlProvider = {
  @react.component @module("react-intl")
  external make: (~value: Intl.t, ~children: React.element) => React.element = "RawIntlProvider"
}

module IntlProvider = {
  @react.component @module("react-intl")
  external make: (
    ~locale: string=?,
    ~formats: {..}=? /* TODO */,
    ~messages: Js.Dict.t<string>=?,
    ~defaultLocale: string=?,
    ~defaultFormats: {..}=? /* TODO */,
    ~textComponent: textComponent=?,
    ~initialNow: int=?,
    ~onError: string => unit=?,
    ~children: React.element,
  ) => React.element = "IntlProvider"
}

module FormattedMessage = {
  @react.component @module("react-intl")
  external make: (
    ~id: string,
    ~defaultMessage: string,
    ~values: {..}=?,
    ~tagName: string=?,
    ~children: (~formattedMessage: React.element) => React.element=?,
  ) => React.element = "FormattedMessage"
}

module FormattedDate = {
  @react.component @module("react-intl")
  external make: (
    ~value: Js.Date.t,
    ~localeMatcher: [#"best fit" | #lookup]=?,
    ~formatMatcher: [#"best fit" | #basic]=?,
    ~timeZone: string=?,
    ~hour12: bool=?,
    ~weekday: [#narrow | #short | #long]=?,
    ~era: [#narrow | #short | #long]=?,
    ~year: [#numeric | #"2-digit"]=?,
    ~month: [
      | #numeric
      | #"2-digit"
      | #narrow
      | #short
      | #long
    ]=?,
    ~day: [#numeric | #"2-digit"]=?,
    ~hour: [#numeric | #"2-digit"]=?,
    ~minute: [#numeric | #"2-digit"]=?,
    ~second: [#numeric | #"2-digit"]=?,
    ~timeZoneName: [#short | #long]=?,
    ~format: string=?,
    ~children: (~formattedDate: string) => React.element=?,
  ) => React.element = "FormattedDate"
}

module FormattedDateParts = {
  @react.component @module("react-intl")
  external make: (
    ~value: Js.Date.t,
    ~localeMatcher: [#"best fit" | #lookup]=?,
    ~formatMatcher: [#"best fit" | #basic]=?,
    ~timeZone: string=?,
    ~hour12: bool=?,
    ~weekday: [#narrow | #short | #long]=?,
    ~era: [#narrow | #short | #long]=?,
    ~year: [#numeric | #"2-digit"]=?,
    ~month: [
      | #numeric
      | #"2-digit"
      | #narrow
      | #short
      | #long
    ]=?,
    ~day: [#numeric | #"2-digit"]=?,
    ~hour: [#numeric | #"2-digit"]=?,
    ~minute: [#numeric | #"2-digit"]=?,
    ~second: [#numeric | #"2-digit"]=?,
    ~timeZoneName: [#short | #long]=?,
    ~format: string=?,
    ~children: (~formattedDateParts: array<part>) => React.element,
  ) => React.element = "FormattedDateParts"
}

module FormattedTime = {
  @react.component @module("react-intl")
  external make: (
    ~value: Js.Date.t,
    ~localeMatcher: [#"best fit" | #lookup]=?,
    ~formatMatcher: [#"best fit" | #basic]=?,
    ~timeZone: string=?,
    ~hour12: bool=?,
    ~weekday: [#narrow | #short | #long]=?,
    ~era: [#narrow | #short | #long]=?,
    ~year: [#numeric | #"2-digit"]=?,
    ~month: [
      | #numeric
      | #"2-digit"
      | #narrow
      | #short
      | #long
    ]=?,
    ~day: [#numeric | #"2-digit"]=?,
    ~hour: [#numeric | #"2-digit"]=?,
    ~minute: [#numeric | #"2-digit"]=?,
    ~second: [#numeric | #"2-digit"]=?,
    ~timeZoneName: [#short | #long]=?,
    ~format: string=?,
    ~children: (~formattedTime: string) => React.element=?,
  ) => React.element = "FormattedTime"
}

module FormattedTimeParts = {
  @react.component @module("react-intl")
  external make: (
    ~value: Js.Date.t,
    ~localeMatcher: [#"best fit" | #lookup]=?,
    ~formatMatcher: [#"best fit" | #basic]=?,
    ~timeZone: string=?,
    ~hour12: bool=?,
    ~weekday: [#narrow | #short | #long]=?,
    ~era: [#narrow | #short | #long]=?,
    ~year: [#numeric | #"2-digit"]=?,
    ~month: [
      | #numeric
      | #"2-digit"
      | #narrow
      | #short
      | #long
    ]=?,
    ~day: [#numeric | #"2-digit"]=?,
    ~hour: [#numeric | #"2-digit"]=?,
    ~minute: [#numeric | #"2-digit"]=?,
    ~second: [#numeric | #"2-digit"]=?,
    ~timeZoneName: [#short | #long]=?,
    ~format: string=?,
    ~children: (~formattedTimeParts: array<part>) => React.element,
  ) => React.element = "FormattedTimeParts"
}

module FormattedRelativeTime = {
  @react.component @module("react-intl")
  external make: (
    ~value: float,
    ~unit: [
      | #second
      | #minute
      | #hour
      | #day
      | #week
      | #month
      | #quarter
      | #year
    ]=?,
    ~numeric: [#always | #auto]=?,
    ~style: [#long | #short | #narrow]=?,
    ~format: string=?,
    ~updateIntervalInSeconds: float=?,
    ~children: (~formattedDate: string) => React.element=?,
  ) => React.element = "FormattedRelativeTime"
}

module FormattedNumber = {
  @react.component @module("react-intl")
  external make: (
    ~value: float,
    ~localeMatcher: [#"best fit" | #lookup]=?,
    ~style: [#decimal | #currency | #percent]=?,
    ~currency: string=?,
    ~currencyDisplay: [#symbol | #code | #name]=?,
    ~useGrouping: bool=?,
    ~minimumIntegerDigits: int=?,
    ~minimumFractionDigits: int=?,
    ~maximumFractionDigits: int=?,
    ~minimumSignificantDigits: int=?,
    ~maximumSignificantDigits: int=?,
    ~format: string=?,
    ~children: (~formattedNumber: string) => React.element=?,
  ) => React.element = "FormattedNumber"
}

module FormattedNumberParts = {
  @react.component @module("react-intl")
  external make: (
    ~value: float,
    ~localeMatcher: [#"best fit" | #lookup]=?,
    ~style: [#decimal | #currency | #percent]=?,
    ~currency: string=?,
    ~currencyDisplay: [#symbol | #code | #name]=?,
    ~useGrouping: bool=?,
    ~minimumIntegerDigits: int=?,
    ~minimumFractionDigits: int=?,
    ~maximumFractionDigits: int=?,
    ~minimumSignificantDigits: int=?,
    ~maximumSignificantDigits: int=?,
    ~format: string=?,
    ~children: (~formattedNumberParts: array<part>) => React.element,
  ) => React.element = "FormattedNumberParts"
}

module FormattedPlural = {
  @react.component @module("react-intl")
  external make: (
    ~value: int,
    ~style: [#cardinal | #ordinal]=?,
    ~other: React.element,
    ~zero: React.element=?,
    ~one: React.element=?,
    ~two: React.element=?,
    ~few: React.element=?,
    ~many: React.element=?,
    ~children: (~formattedPlural: string) => React.element=?,
  ) => React.element = "FormattedPlural"
}

module FormattedList = {
  @react.component @module("react-intl")
  external make: (
    ~value: array<string>,
    ~style: [#long | #short | #narrow]=?,
    ~_type: [#disjunction | #conjunction | #unit]=?,
    ~children: (~formattedList: string) => React.element=?,
  ) => React.element = "FormattedList"
}

module FormattedDisplayName = {
  @react.component @module("react-intl")
  external make: (
    ~value: string,
    ~style: [#long | #short | #narrow]=?,
    ~_type: [#language | #region | #script | #currency]=?,
    ~fallback: [#code | #none]=?,
  ) => React.element = "FormattedDisplayName"
}
