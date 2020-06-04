# 2.0.0
* **[ BREAKING ]** `bs-platform >=7.2.2`.
* **[ BREAKING ]** `react-intl >=4.0.0`:
  - Added `Intl.timeZone`
  - Added `FormattedList`, `Intl.formatList` & `Intl.formatListWithOptions`
  - Added `FormattedDisplayName`, `Intl.formatDisplayName` & `Intl.formatDisplayNameWithOptions`
  - Added `FormattedDateParts`, `Intl.formatDateToParts` & `Intl.formatDateToPartsWithOptions`
  - Added `FormattedTimeParts`, `Intl.formatTimeToParts` & `Intl.formatTimeToPartsWithOptions`
  - Added `FormattedNumberParts`, `Intl.formatNumberToParts` & `Intl.formatNumberToPartsWithOptions`
  - Removed `FormattedHTMLMessage`, `Intl.formatHTMLMessage` & `Intl.formatHtmlMessageWithValues`
  - Removed `Intl.now`
  - `FormattedRelative` has been renamed to `FormattedRelativeTime` and its API has been changed as well
  - `Intl.formatRelative` has been renamed to `Intl.formatRelativeTime` and its API has been changed as well
* **[ BREAKING ]** Changed `ReactIntl.message` to record type.
* **[ BREAKING ]** Removed `ReactIntl.translation`.
* **[ BREAKING ]** Removed `ReactIntlCompat`.

# 1.1.0
* Added `createIntlCache`, `intlConfig`, `createIntl`, `RawIntlProvider`.

# 1.0.0
* Updated for react-intl 3.0.0+, including support for the `useIntl` hook.
* **[ BREAKING ]** This requires `reason-react >=0.7.0` and `bs-platform >=5.0.3`.

# 0.8.0
* **[ BREAKING ]** `bs-platform` updated to `5.0.0`.
* **[ BREAKING ]** `reason-react` updated to `0.6.0`.

# 0.7.0
* Add support for react-intl 2.7.x custom error handling ([#15](https://github.com/alexfedoseev/bs-react-intl/pull/15)).

# 0.6.0
* **[ BREAKING ]** Make compatible with React Native ([#13](https://github.com/alexfedoseev/bs-react-intl/pull/13)).

# 0.5.0
* **[ BREAKING ]** `bs-platform` updated to `4.0.5`.
* **[ BREAKING ]** `reason-react` updated to `0.5.3`.

# 0.4.0
* **[ BREAKING ]** `bs-platform` updated to `3.0.0`.

# 0.3.0
* Add `FormattedDate` component.
* Add `FormattedTime` component.

# 0.2.1
* Inline `injectIntl` HOC.

# 0.2.0
* **[ BREAKING ]** `reason-cli` updated to `3.1.0`.
* **[ BREAKING ]** `FormattedMessage` component now matches API of JS version (instead of `message` prop it accepts `id` & `defaultMessage`).
* If you want to pass `message` prop use `DefinedMessage` component.

# 0.1.0
* **[ BREAKING ]** `bs-platform` updated to `2.2.2`.

# 0.0.1
Initial release.
