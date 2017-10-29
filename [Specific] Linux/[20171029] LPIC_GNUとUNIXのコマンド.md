# 3.1 コマンドライン操作

# 3.1.1　シェル & 3.1.2 シェルの基本操作と設定

ユーザーからのコマンドを受け付け、必要なプログラムを実行しているのは、シェルというプログラムです。
システムにログインした直後に起動されたシェルは、ログインシェルと呼ばれます。

in Bash,

- $ normal user
- # root user

- ctrl+a : カーソルが行頭に行く
- ctrl+e : カーソルが行末に行く
- ctrl+l : カーソル部分の一文字を削除
- ctrl+h : カーソルの左側にある一文字を削除
- ctrl+c : 処理を中断
- ctrl+z : 処理を一時中断

- ~ home directory
- . current directory
- .. upper directory
- ~ home directory ( root -> /root : user -> /home/user/ 

# 3.1.3 シェル変数と環境変数

shell variable : 有効範囲は、その変数を定義したシェル・プロセスのみになります。
environment variable : その変数を定義したシェル上、およびそのシェルで実行されるプログラムにも引き継がれる変数。環境変数は、シェル変数をexportコマンドでエクスポートすることによって設定する

主な環境関数

PATH PWD HOSTNAME USER LANG HOME LOGHOME 

- HISTSIZE : The maximum number of commands to remember on the history list, default is 500
- HISTFILE : The name of the file to which the command history is saved, The defailt value is ~/.bash_history
- HISTFILESIZE : The maximum number of lines contained in the history file, defaults to 500.
- TERM : the kind of terminal


- unset : 変数を削除
- env, printenv : 定義した環境変数を一覧

エクスポートと変数の定義を一行で書くこともできる

```
$export VAR=lpic
``` 

定義する際には、変数名の先頭に$記号は不要、参照する際には$記号が必要

```
$VAR=Linux
$echo $VAR
```

# 3.1.4 環境関数PATH

Commandはに種類ある

(1)内部コマンド：シェル自体に組み込まれているもの　
(2)外部コマンド：独立したプログラムとして存在するもの

外部コマンドは、環境関数PATHに指定されたディレクトリを順に調べて見つけ出す。
PATH変数に含まれていないディレクトリにあるコマンドでも、絶対パスを指定すれば実行することができる。（コマンドを実行する権限は別）

```
PATH=$PATH:追加するディレクトリ名
```

# 3.1.5　コマンドの実行

- COMMAND1 ; COMMAND2 :COMMAND1に続きてCOMMAND2を実行する
- COMMAND1 && COMMAND2：COMMAND1が正常に終了したときのみ、COMMAND2を実行する
- COMMAND1 || COMMAND2：COMMAND1が正常に終了しなかった場合のみ、COMMAND2を実行する
- (COMMAND1 ; COMMAND2)：COMMAND1とCOMMAND2を、ひとまとまりのコマンドグループとして実行する
- {COMMAND1 ; COMMAND2}：現在のシェル内でCOMMAND1とCOMMAND2を実行する









