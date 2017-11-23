const path = require('path');

module.exports = {
  entry: {
    basic: './examples/basic/index.bs.js',
  },
  output: {
    path: path.join(__dirname, "build"),
    filename: '[name].js',
  },
};
