type state = {locale: Locale.locale};

type action =
  | SetLocale(Locale.locale);

let component = "App" |> ReasonReact.reducerComponent;

let make = (_) => {
  ...component,
  initialState: () => {locale: Locale.En},
  reducer: (action, _) =>
    switch (action) {
    | SetLocale(locale) => ReasonReact.Update({locale: locale})
    },
  render: ({state, send}) =>
    <ReactIntl.IntlProvider
      locale=(state.locale |> Locale.mapLocaleToString)
      messages=(
        state.locale
        |> Locale.mapLocaleToMessages
        |> ReactIntl.messagesArrayToDict
      )>
      <Page
        locale=state.locale
        setLocale=(locale => SetLocale(locale) |> send)
      />
    </ReactIntl.IntlProvider>,
};
