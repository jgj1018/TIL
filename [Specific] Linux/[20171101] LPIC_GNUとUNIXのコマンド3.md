# 3.1.9, 3.1.10 メタキャラクタの利用

`touch` command

: ファイルのタイムスタンプを変更する

-t CCYYMMDDhhssSS
-a　アクセス時刻だけ変更する
-m 修正時刻だけ変更する

`file` command

: ファイルの種別を表示する

`メタキャラクタとは、ファイル名のパターンを表す特殊な記号のこと`

- * : 0文字以上の文字または文字列にマッチ、0文字にもマッチする
- ? : 任意の1文字にマッチ
- [] :[]なかに列挙されている文字のいずれか1文字にマッチ。a[bcd]はab ac adとマッチ。連続した文字列には -ハイフンを使える [0-9] = [0123456789]。範囲指定の先頭に!を使うと、マッチしない範囲を指定できる。a[!bcd]はaa, a1とはマッチ、 ab acはマッチしない 
- {} :,で区切られた文字列にマッチする。test{1,2}はtest1とtest2とマッチ

# 3.2 パイプとリダイレクト
# 3.2.1　標準入出力

0 標準入力　キーボード
1 標準出力　画面（端末）
2　標準エラー出力　画面（端末）

# 3.2.2  パイプ

```
$ dmesg | less
```

dmesgコマンドを単体で実行すると、出力が画面からあふれてしまうため、lessコマンドを介して1画面ずつ表示できるようにしている

- tee コマンド
標準入力から読み込み、それをファイルと標準出力へとT字型に分岐させます。つまり、実行結果をファイルに書き込みつつ、次のコマンドへと実行結果を渡すことができる

- -a : ファイルに上書きするのではなく追記する

```
$ls -l | tee ls_log | wc -l
```

# 3.2.3 リダイレクト

特定の文字列が現れるまで入力を続けるには、リダイレクト記号の<<を使う。
`ヒアドキュメント`という。

コマンド　<<　終了文字

:終了文字が現れるまで標準入力へ送る

コマンド >　ファイル 2>&1

:ファイルの標準出力と標準エラー出力を書き込む

コマンド &> ファイル

：標準出力と標準エラー出力を同じファイルに書き込む

コマンド > /dev/null 2>&1

：コマンドが出力するメッセージを一切画面上表示したくない場合。/dev/nullは特殊なファイルで、入力されたすべてのデータを消し去る

# 3.3 テキスト処理フィルタ

*cat*

Concatenate File(s) to standart output.
With no File, or when file is -, read standard input.

- -n --number number all output lines.

*nl*

Write each file to standart output, with line numbers added. With no File, or when file is -, read standard input.
 
- -b --body-numbering
- -h --header-numbering
- -f --footer-numbering

- a : number all lines
- t : number only nonempty lines.
- n : number no lines.

*od* 

write an unambiguous representation. octal bytes by default. of file to standard output. With more than one file argument, concatenate them in the listed order to form the input. 

- option 
- -t [type] select output format or formats.

- output type
- c ASCII Code
- o octal
- x hexadecimal

```
$ od -t x /etc/localtime
```

*head*

: output the first part of files.

- -n [num] print the first num lines instead of the first 10.
- -[number] same as above. but not recommended
- -c [bytes] print the first bytes of each files. 


*tail*

:output the last part of files.

the main options are same as head

- -f --follow : output appended data as the file grows.

*cut*

print selected parts of lines from each file to standard output. 

- -c [list] select only these characters.
- -d [delim] use delin instead of Tab for field delimiter.
- -f [list] select only these fields, also print any line that contains no delimiter character.

```
$ cut -c 1-7 /etc/resolv.conf
```

```
$cut -d: -f 6 /etc/passwd
```
区切り文字を:として、/etc/passwdファイルの各行から第6フィールドだけを取り出している





