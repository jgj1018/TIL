# 3.1.6 引用符

- 単一引用符(シングルクォーテーション）
： 単一引用符の中は、全て文字列であると判断

- 二重引用符（ダブルフォーテーション）
：基本的には文字列扱い、ただし変数が含まれていたら内容を展開
展開したくない場合は、バックスラッシュを使う。（エスケープ文字）

- バッククォーテーション
：バッククォーテーション内にコマンドがあれば、そのコマンドを実行した結果が展開される。また、変数の場合は、変数に格納されているコマンドを実行した結果が展開される

```
$ DATE=date
$ echo $DATE
date
$ echo '$DATE'
$DATE
$ echo "$DATE"
date
$ echo `$DATE`
Sun Feb 8 12:42:18 JST 2017
```

# 3.1.7 コマンドの履歴

- !文字列：実施したコマンドの中で、指定した文字列から始まるコマンドを実行する
- !?文字列：実施したコマンドの中で、指定した文字列を含むコマンドを実行する
- !!：直前に実行したコマンドを再実施
- !履歴番号：履歴番号のコマンドを実施

# 3.1.8 マニュアルの参照

/usr/share/man
MANPATHを参照。何も設定されてなければ、/etc/man.configもしくは、/etc/man.confを参照

```
man [option] [session] command or keyword
```
- option
- -a : By default, man will exit after displaying the first manual page it finds.
- -f : Equivalent to whatis.
- -k : Displays the header lines that contain any of the keywords. Equivalent to apropos
- -w : Don't actually display the man pages, but do print the location(s) of the files that would be formatted or displayed.

manでは、デフォルトのページャとしてlessが設定されています。

whatis = man -f
apropos = man -k
makewhatis : キーワードで検索できるようにするとき、キーワード検索用のデータベースを用意する


*lessの主なキー操作*

- ?検索文字列:上方向に文字列を検索
- スペースキー、fキー：下方向に1画面スクロール
- bキー：上方向に1画面スクロール

- 同一の名前で異なる内容を扱えるようにするために、セクションが設定されている。セクションとは、ドキュメントの内容による分類である

- 1: ユーザーコマンド
- 2: システムコール（カーネルの機能を使うための関数）
- 3: ライブラリ(c言語の関数)
- 4: デバイスファイル
- 5: 設定ファイル
- 6: ゲーム
- 7: そのほか
- 8: システム管理システム
- 9: Linux独自のカーネル用ドキュメント

```
man -a passwd
```

# 3.1.9 ファイル操作コマンド

*ls*

- -a list all files including hidden file starting with '.'
- -A do not list implied . and ..
- -d list directories - with ' */'
- -F add one char of */=>@| to enteries
- -i list file's inode index number
- -l list with long format - show permissions
- -t sort by time & date
- -h with -l and/or -s, print human readable sizes (e.g., 1K 234M 2G)

*cp*

- -f force copy by removing the destination file if needed
- -i interactive - ask before overwrite
- -p same as --preserve=mode,ownership,timestamps
- -r -R recursive copy (including hidden files)
- -d same as --no-dereference --preserve=links
- -a archive files

*mv*

- -f force move by overwriting destination file without prompt
- -i interactive prompt before overwrite

*mkdir*

- -p Creates missing intermediate path name directories. If the -p flag is not specified, the parent directory of each-newly created directory must already exist.
- -m Sets the permission bits for the newly-created directories to the value specified by the Mode variable

```
$ mkdir -m 700 mydir
```

