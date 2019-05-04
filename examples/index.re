[@bs.module "react-intl/locale-data/en"]
external en: ReactIntl.localeData('t) = "default";
[@bs.module "react-intl/locale-data/ru"]
external ru: ReactIntl.localeData('t) = "default";

ReactIntl.addLocaleData(en);
ReactIntl.addLocaleData(ru);

ReactDOMRe.renderToElementWithId(<App />, "app");
