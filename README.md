# bs-react-intl

[BuckleScript](https://bucklescript.github.io) bindings to [react-intl](https://github.com/yahoo/react-intl).

To extract messages from [Reason](https://reasonml.github.io) source files for localization, use [bs-react-intl-extractor](https://github.com/cknitt/bs-react-intl-extractor).

## Installation
```shell
# yarn
yarn add bs-react-intl

# or npm
npm install --save bs-react-intl
```

## Examples
Clone this repo.

```shell
yarn install
yarn start
```

## Status
Despite lots of unchecked the most hard work is done. I'll add bindings to the rest of the components once I need them. Feel free to help me out and submit a PR.

- [x] addLocaleData
- [x] intlShape
- [x] injectIntl
- [x] defineMessages
- [x] IntlProvider
- [x] FormattedDate
- [ ] FormattedDate (children-as-function)
- [x] FormattedTime
- [ ] FormattedTime (children-as-function)
- [ ] FormattedRelative
- [ ] FormattedRelative (children-as-function)
- [ ] FormattedNumber
- [ ] FormattedNumber (children-as-function)
- [ ] FormattedPlural
- [ ] FormattedPlural (children-as-function)
- [x] FormattedMessage
- [ ] FormattedMessage (children-as-function)
- [x] DefinedMessage
- [ ] DefinedMessage (children-as-function)
- [ ] FormattedHTMLMessage
- [ ] FormattedHTMLMessage (children-as-function)

## Usage
See [`examples`](./examples) folder.
