[@bs.module]
external en : ReactIntl.localeData('t) = "react-intl/locale-data/en";

[@bs.module]
external ru : ReactIntl.localeData('t) = "react-intl/locale-data/ru";

ReactIntl.addLocaleData(en);

ReactIntl.addLocaleData(ru);

ReactDOMRe.renderToElementWithId(<App />, "app");
