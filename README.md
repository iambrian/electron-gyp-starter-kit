# electron-gyp-starter-kit
Boilerplate for using native addons with electron

### Usage:

Install modules:
```
npm install
```

Build addons:
```
HOME=~/.electron-gyp node-gyp rebuild --target=1.3.1 --arch=x64 --dist-url=https://atom.io/download/atom-shell
```

Start app:
```
npm start
```

### Based on:
* https://github.com/nodejs/node-addon-examples/tree/master/1_hello_world
* https://github.com/electron/electron-quick-start
