open ReactIntl

@react.component
let make = (~locale, ~setLocale) => {
  let intl = ReactIntl.useIntl()
  let className = locale' => locale' === locale ? "active" : ""

  <div className="container">
    <div className="buttons">
      <button className={Locale.En->className} onClick={_ => Locale.En->setLocale}>
        {Locale.En->Locale.toString->React.string}
      </button>
      <button className={Locale.Ru->className} onClick={_ => Locale.Ru->setLocale}>
        {Locale.Ru->Locale.toString->React.string}
      </button>
    </div>
    <div className="message">
      <FormattedMessage id="page.hello" defaultMessage="Hello" />
      {" "->React.string}
      <FormattedMessage id="page.world" defaultMessage="World" />
    </div>
    <div>
      {intl->Intl.formatMessage(PageLocale.today)->React.string}
      {" "->React.string}
      {intl->Intl.formatDate(Js.Date.make())->React.string}
      {" (intl.formatDate)"->React.string}
      <br />
      {intl->Intl.formatMessage(PageLocale.today)->React.string}
      {" "->React.string}
      <FormattedDate value={Js.Date.make()} />
      {" (FormattedDate)"->React.string}
    </div>
    <div>
      <FormattedMessage
        id="page.html"
        defaultMessage="HTML example: <bold>bold text</bold>, <combined><italic>italic bold</italic> text</combined>"
        values={
          "bold": text => <strong> text </strong>,
          "italic": text => <em> text </em>,
          "combined": (italicBold, text) => <strong> italicBold text </strong>,
        }
      />
    </div>
  </div>
}
