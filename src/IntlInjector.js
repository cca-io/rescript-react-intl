var injectIntl = require("react-intl").injectIntl;

var IntlInjector = function IntlInjector(_ref) {
  var intl = _ref.intl,
      children = _ref.children;
  return children(intl);
};

exports.default = injectIntl(IntlInjector);
