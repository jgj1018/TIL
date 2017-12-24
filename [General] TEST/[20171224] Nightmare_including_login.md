[ref1](http://okakacacao.wpblog.jp/technology/nightmare-js-implementation)

# ログインが必要なページを含む場合

ログインの仕組みにもよりますが、クッキーを使った一般的なサイトであれば、次のような流れで実装できます。

- Nightmareで一度ログインページにアクセスし、実際にログイン
- ログイン後、ブラウザのクッキーを取得し、Nightmareを閉じる
- クッキーをプログラム側で保持
- テスト用のNightmareインスタンスを新しく作成し、保持しているクッキーをセット
- ログインが必要なページにアクセス

```
const Nightmare = require('nightmare');
const loginNightmare = Nightmare({
    show: true
});
const nightmare = Nightmare({
    show: true
});
 
 
const id = '*****';
const password = '*****';
let loginCookies;
 
const login = n => {
    return new Promise((resolve, reject) => {
 
        n
            .goto('https://account.nicovideo.jp/login')
            .type('#input__mailtel', id)
            .type('#input__password', password)
            .click('#login__submit')
            .wait(4000)
            .cookies.get()
            .end()
            .then(function(cookies) {
                loginCookies = cookies;
                resolve();
            })
            .catch(function(error) {
                console.error('Login failed:', error);
                reject();
            });
    });
};
 
const setCookie = n => {
    return new Promise((resolve, reject) => {
        n
            .goto('http://www.nicovideo.jp/')
            .cookies.set(loginCookies)
            .then(function() {
                resolve();
            })
            .catch(function(error) {
                console.error('setCookie failed:', error);
                reject();
            });
    });
};
 
const example = n => {
    return new Promise((resolve, reject) => {
        n
	    .goto('http://www.nicovideo.jp/')
	    .type('#searchWord', 'テスト')
	    .click('#searchSubmit')
	    .wait(5000)
            .evaluate(function() {
                return document.querySelector('title').innerHTML;
            })
            .end()
            .then(function(result) {
                console.log(result);
                resolve();
            })
            .catch(function(error) {
                console.error('Transition failed:', error);
                reject();
            });
    });
 
};
 
login(loginNightmare).then(() => {
	return setCookie(nightmare);
}).then(() => {
	return example(nightmare);
});
```