type action =
  | SetLocale(Locale.locale);

let initialState = Locale.En;

let reducer = (_, action) =>
  switch (action) {
  | SetLocale(locale) => locale
  };

// As an alternative to using IntlProvider like in the main make function below,
// you can construct the intl instance yourself and pass it to RawIntlProvider instead.
// This is especially useful if you need to create/use the intl instance outside of a
// React component.
module WithRawIntlProvider = {
  let createIntlForLocale = locale => {
    let intlConfig =
      ReactIntl.intlConfig(
        ~locale=locale->Locale.toString,
        ~messages=locale->Locale.translations->Util.translationsToDict,
        (),
      );
    let intlCache = ReactIntl.createIntlCache();

    ReactIntl.createIntl(intlConfig, intlCache);
  };

  [@react.component]
  let make = () => {
    let (locale, dispatch) = reducer->React.useReducer(initialState);

    let intl =
      React.useMemo1(() => createIntlForLocale(locale), [|locale|]);

    <ReactIntl.RawIntlProvider value=intl>
      <Page locale setLocale={locale => locale->SetLocale->dispatch} />
    </ReactIntl.RawIntlProvider>;
  };
};

[@react.component]
let make = () => {
  let (locale, dispatch) = reducer->React.useReducer(initialState);

  <ReactIntl.IntlProvider
    locale={locale->Locale.toString}
    messages={locale->Locale.translations->Util.translationsToDict}>
    <Page locale setLocale={locale => locale->SetLocale->dispatch} />
  </ReactIntl.IntlProvider>;
};
