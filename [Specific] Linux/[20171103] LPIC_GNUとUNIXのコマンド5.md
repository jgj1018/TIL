# 3.4 正規表現を使ったテキスト検索

シェルのメタキャラクタと同様、任意の文字列パターンを表すための表現方法

# 3.4.1　正規表現

- 任意の一文字 
.（ピリオド）

ex) a..d can be `abcd` and `a12d`

- 文字クラス
：一連の文字集合を表す時 [ ]を使う

ex) c[au]t can be cat and cut.

-を使って範囲を指定することもできる

ex) [0-9] [a-zA-Z]

^ハット膜が先頭に置かれている場所は「～以外」を表す

ex) [^abc]がaでもbでもcでもない一文字という意味

- 行頭と行末

^ : 行頭 
$ : 行末 

ex）^a, a$ 

文字クラス内での^は「～以外」の意味だが、普通は行頭を表す

- 繰り返し
直前の文字を0回以上の繰り返し表すには*を使う 
ex) ab*z can be [az], [abz] [abbz]

特殊文字

:バックスラッシュを使う。ただし、\が有効なのは直後の一文字だけ

# 3.4.2 grepコマンド

grepコマンドは、ファイルやテキストストリームの中に、正規表現によって表される検索文字列があるかどうか調べることができる

grep [option] pattern [file]

- -c --count: suppress normal output. Instead print a count of matching lines for each input files.
- -f --file : Obtain patterns from file.
- -i --ignore-case : Ignore case distinctions in both the pattern and the input file
- -n --line-number : Prifix each line of output with the 1-based line number within its input file.
- -v --invert-match : Invert the sense of matching, to select non-matching file.
- -E --extended-regexp : Interpret apttern as an extended regular expression.

```
$ grep -v '^#' /etc/httpd/conf/httpd.conf
```

use egrep comamnd when I want to use extended-regexp.

- + :直前の文字の1回以上の繰り返し
- ? :直前の文字の0回もしくは1回の繰り返し
- | :左右いずれかの記述にマッチする

```
$ egrep '\s(22|53)/tcp' /etc/services
```

use fgrep command when I don't want to use regexp.


```
$ fgrep '.*' sample.txt

is the same as

$ grep '\.\*' sample.txt
```
 
# 3.4.3 sedコマンド

：テキストストリームに対して編集を行う

- sed [option] command [file]
- sed [option] -e command1 [-e command2 ...] [file]
- sed [option] -f script [file]

- main option 
- -f [file] : add the contents of script-file to the commands to be executed.

: sedコマンド内で指定できる主なコマンド
- d : マッチする行を削除する
- s : パターンに基づいて置換する。gスイッチを使うと、マッチ箇所すべてを置換する
- y : 文字を変換する

```
$ sed '1,5d' file1.txt > file2.txt
```

:sedはもとのファイルを変更しません。 -iオプションを指定すると、元のファイル内容を変更する

```
$sed s/linux/LINUX/ file1.txt
```

sコマンドでは、検索パターンにマッチする部分が一行に複数あっても、最初にマッチした部分だけを置換する。マッチする部分すべてを置換するには、gスイッチを最初に記述する

```
$ sed s/linux/LINUX/g file1.txt
```

コマンド部分を単一引用符で囲んだのは、シェルが>記号をリダイレクト記号と翻訳しないようにするため

```
$ sed '1.5s/^/>/g' /etc/passwd
```

yを使うと、ストリーム中に検索文字にマッチするもh時があった場合、その文字を置換文字の同じ位置の文字に置き換える

```
$sed y/ABC/123/ sample.txt
```

example of -f option

```
$cat sedscripts
1, 10s/linux/LINUX/g
$ sed -f sedscripts file5.txt
```