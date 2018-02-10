open PageLocale;

let component = ReasonReact.statelessComponent("Page");

let make = (~locale, ~setLocale, _) => {
  let getClassName = locale' => locale' === locale ? "active" : "";
  let setEnLocale = (_) => setLocale(Locale.En);
  let setRuLocale = (_) => setLocale(Locale.Ru);
  let localeToElement = locale =>
    locale |> Locale.mapLocaleToString |> ReasonReact.stringToElement;
  {
    ...component,
    render: (_) =>
      <div className="container">
        <div className="buttons">
          <button className=(getClassName(Locale.En)) onClick=setEnLocale>
            (Locale.En |> localeToElement)
          </button>
          <button className=(getClassName(Locale.Ru)) onClick=setRuLocale>
            (Locale.Ru |> localeToElement)
          </button>
        </div>
        <div className="message">
          <ReactIntl.FormattedMessage message=pageLocale##hello />
          (ReasonReact.stringToElement(" "))
          <ReactIntl.FormattedMessage message=pageLocale##world />
        </div>
        <ReactIntl.IntlInjector>
          ...(
               intl =>
                 <div>
                   <ReactIntl.FormattedMessage message=pageLocale##today />
                   (ReasonReact.stringToElement(" "))
                   (
                     intl.formatDate(Js.Date.now() |> Js.Date.fromFloat)
                     |> ReasonReact.stringToElement
                   )
                 </div>
             )
        </ReactIntl.IntlInjector>
      </div>
  };
};
