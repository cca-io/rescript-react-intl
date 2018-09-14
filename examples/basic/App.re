type state = {locale: Locale.locale};

type action =
  | SetLocale(Locale.locale);

let component = ReasonReact.reducerComponent(__MODULE__);

let make = _ => {
  ...component,
  initialState: () => {locale: Locale.En},
  reducer: (action, _) =>
    switch (action) {
    | SetLocale(locale) => ReasonReact.Update({locale: locale})
    },
  render: ({state, send}) =>
    <ReactIntl.IntlProvider
      locale=state.locale->Locale.toString
      messages=state.locale->Locale.toMessages->ReactIntl.messagesArrayToDict>
      <Page
        locale={state.locale}
        setLocale={locale => locale->SetLocale->send}
      />
    </ReactIntl.IntlProvider>,
};
