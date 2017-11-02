`join`

: join lines of two files on a command field.

- -j [field] equivalent to '-1 field -2 field'

```
$ join -j 1 sample1.txt sample2.txt
```

`paste`

: write lines consisting of the sequentially corresponding lines from each file, sepereated by tabs, to standard output. 

- -d [LIST] reuse characters from LIST instead of tabs.

```
$ paste -d";" sample1.txt sample2.txt
```

`tr` [OPTION] SET1 [SET2]

: translate, squeeze, and/or delete characters from standard input, writing to standard output.

- -d dleete characters in SET1, do not translate
- -s replace each input sequence of a repeated character that is listed in SET1 with a single occurrence of that character.
```
$ cat /etc/hosts | tr 'a-z' 'A-Z'
```
: /etc/hostsファイル中の小文字をすべて大文字に変更している

```
$ cat /etc/hosts | tr [:lower:] [:upper:]
```
: クラスを使った例

```
$ tr -d : < file1
```
file1の中にある :を削除する

`sort`

: sort lines of text files.

- -b ignore leading blanks.
- -f fold lower case to upper case characters.
- -n compare according to string numerical value.
- -r reverse the result of comparisons.

`split`

: split a file into pieces.

-行数　入力ファイルを指定された行ごとに分割する

```
$split -100 sample.txt s_sample.
```
:sample.txtを100行ごとに分割し、s_sample.aa,s_sample.ab...というファイル名で保存している

`uniq`

:Report or filter out repeated lines in a file. Reads standard input comparing adjacent lines, and writes a copy of each unique line to the standard output. The second and succeeding copies of identical adjacent input lines are not written.

- -d : Print only duplicate lines.
- -u : Don't output lines that are repeated in the input. Print only lines that are unique in the INPUT.

`pr`

:convert text files for printing

- +開始ページ[:終了ページ:] : 開始ページと終了ぺージを指定する
- -h ヘッダ文字列 : use a centered HEADER instead of filename in page header, -h "" prints a blank line, don't use -h ""
- -l ページ長 : set the page length to PAGE_LENGTH(66) lines.

```
$ pr -l 30 +1:2 /etc/services
```
:/etc/serviceファイルを1ページあたり30行とし、1ページメと2ページ目を出力

`fmt`

:simple optimal text formatter
テキストを決められた桁に整形する
- -w maximum line width.

`expand`

:convert tabs to spaces.

- -i do not convert tabs after non blanks.
- -t [N]  have tabs N characters apart instead of 8

`unexpand`

:convert spaces to tabs

- -a convert all blanks, instead of just initial blanks.
- -t [N] have tabs N characters apart instead of 8

`wc`

: print newline, word, and byte counts for each file.

- -c print the byte counts.
- -l print the newline counts.
- -w print the word counts.

without any option, print newline, word and byte.

`xargs`

標準入力から上とった文字列を引数に指定して、与えられたコマンドを実行する。

```
$ find . -mtime +60 -type f | xargs rm
```

:利点は、引数の数が多すぎた場合でも処理できるということ

```
$ echo * | xargs rm
```