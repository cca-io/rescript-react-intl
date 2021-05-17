# rescript-react-intl

[![NPM](https://nodei.co/npm/rescript-react-intl.png?compact=true)](https://nodei.co/npm/rescript-react-intl/)  
![Build Status](https://github.com/cca-io/rescript-react-intl/workflows/CI/badge.svg)

[ReScript] bindings to [react-intl].

To extract messages from [ReScript] source files for localization, use [rescript-react-intl-extractor].

## Installation

```shell
# yarn
yarn add rescript-react-intl

# or npm
npm install --save rescript-react-intl
```

Note: If you need version of the bindings that still supports the old Reason syntax, use the old package name `bs-react-intl` instead.

## Examples

Clone this repo.

```shell
yarn install
yarn start
```

## Status

rescript-react-intl should cover all of the [react-intl] 3.0.0 API. If you find anything missing, please file an issue.

## Usage

See [`examples`](./examples) folder.

[rescript]: https://rescript-lang.org
[react-intl]: https://github.com/formatjs/react-intl
[rescript-react-intl-extractor]: https://github.com/cca-io/rescript-react-intl-extractor
