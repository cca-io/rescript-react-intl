open PageLocale;

[@react.component]
let make = (~locale, ~setLocale) => {
  let intl = ReactIntl.useIntl();
  let className = locale' => locale' === locale ? "active" : "";

  <div className="container">
    <div className="buttons">
      <button
        className={Locale.En->className} onClick={_ => Locale.En->setLocale}>
        {Locale.En->Locale.toString->React.string}
      </button>
      <button
        className={Locale.Ru->className} onClick={_ => Locale.Ru->setLocale}>
        {Locale.Ru->Locale.toString->React.string}
      </button>
    </div>
    <div className="message">
      <ReactIntl.DefinedMessage message=pageLocale##hello />
      " "->React.string
      <ReactIntl.DefinedMessage message=pageLocale##world />
    </div>
    <div>
      <ReactIntl.DefinedMessage message=pageLocale##today />
      " "->React.string
      {intl.formatDate(Js.Date.make())->React.string}
      " (intl.formatDate)"->React.string
      <br />
      <ReactIntl.DefinedMessage message=pageLocale##today />
      " "->React.string
      <ReactIntl.FormattedDate value={Js.Date.make()} />
      " (FormattedDate)"->React.string
    </div>
  </div>;
};
