const path = require('path')
const TerserPlugin = require("terser-webpack-plugin");
module.exports = {
    entry: {
        app:'./src/index.js'
    },
    output: {
        filename: '[name].js',
        path: path.resolve(__dirname,'./dist'),
        publicPath: '/dist'
    },
    module:{
        rules:[{
            test:/\.js$/,
            exclude: '/node_modules',
            use: 'babel-loader'
        },
        {
            test: /\.css$/, use: ["style-loader", "css-loader"]
        }
    ]
    },
    devServer:{
        client: {overlay: true},
        static: {directory: path.join(__dirname)}
    },
    optimization: {
        minimize: true,
        minimizer: [new TerserPlugin({
          terserOptions: {
            format: {
              comments: false,
            }
          },
          extractComments: false,
          parallel: true
        })]
      }
}