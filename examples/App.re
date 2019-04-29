type action =
  | SetLocale(Locale.locale);

let initialState = Locale.En;

let reducer = (_, action) =>
  switch (action) {
  | SetLocale(locale) => locale
  };

[@react.component]
let make = () => {
  let (locale, dispatch) = reducer->React.useReducer(initialState);

  <ReactIntl.IntlProvider
    locale={locale->Locale.toString}
    messages={locale->Locale.toMessages->ReactIntl.messagesArrayToDict}>
    <Page locale setLocale={locale => locale->SetLocale->dispatch} />
  </ReactIntl.IntlProvider>;
};
