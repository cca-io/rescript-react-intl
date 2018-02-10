type state = {locale: Locale.locale};

type action =
  | SetLocale(Locale.locale);

let component = ReasonReact.reducerComponent("App");

let make = (_) => {
  ...component,
  initialState: () => {locale: Locale.En},
  reducer: (action, _) =>
    switch action {
    | SetLocale(locale) => ReasonReact.Update({locale: locale})
    },
  render: ({state, reduce}) =>
    <ReactIntl.IntlProvider
      locale=(state.locale |> Locale.mapLocaleToString)
      messages=(
        state.locale
        |> Locale.mapLocaleToMessages
        |> ReactIntl.messagesArrayToDict
      )>
      <Page
        locale=state.locale
        setLocale=(reduce(locale => SetLocale(locale)))
      />
    </ReactIntl.IntlProvider>
};
