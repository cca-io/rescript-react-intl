open PageLocale;

let component = "Page" |> ReasonReact.statelessComponent;

let make = (~locale, ~setLocale, _) => {
  let className = locale' => locale' === locale ? "active" : "";

  {
    ...component,
    render: _ =>
      <div className="container">
        <div className="buttons">
          <button
            className=Locale.En->className onClick={_ => Locale.En->setLocale}>
            Locale.En->Locale.toString->ReasonReact.string
          </button>
          <button
            className=Locale.Ru->className onClick={_ => Locale.Ru->setLocale}>
            Locale.Ru->Locale.toString->ReasonReact.string
          </button>
        </div>
        <div className="message">
          <ReactIntl.DefinedMessage message=pageLocale##hello />
          " "->ReasonReact.string
          <ReactIntl.DefinedMessage message=pageLocale##world />
        </div>
        <ReactIntl.IntlInjector>
          ...{
               intl =>
                 <div>
                   <ReactIntl.DefinedMessage message=pageLocale##today />
                   " "->ReasonReact.string
                   ()->Js.Date.make->(intl.formatDate)->ReasonReact.string
                   " (intl.formatDate)"->ReasonReact.string
                   <br />
                   <ReactIntl.DefinedMessage message=pageLocale##today />
                   " "->ReasonReact.string
                   <ReactIntl.FormattedDate value={Js.Date.make()} />
                   " (FormattedDate)"->ReasonReact.string
                 </div>
             }
        </ReactIntl.IntlInjector>
      </div>,
  };
};
