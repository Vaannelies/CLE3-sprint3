import path from 'path';
export default {
  entry: [
    'C:/Users/thoma/OneDrive/Bureaublad/Code/School/periode3/CLE3/basic-nodebot/browser.js',
  ],
  output: {
    filename: 'bundle.js',
    path: path.resolve(__dirname, 'dist'),
  },
  module: {
    // loaders: [
    //   {
    //     test: /\.js?$/,
    //     loader: 'babel-loader',
    //     exclude: /node_modules/,
    //   },
    // ],
  },
  resolve: {
    extensions: ['.js'],
  },
  devtool: 'source-map',
  mode: "none"
};
