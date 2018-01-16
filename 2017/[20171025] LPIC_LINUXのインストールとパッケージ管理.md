reference : LPIC レベル1　EXAMPRESS(SESHOEISHA)
[reference2](https://askubuntu.com/questions/347203/what-exactly-is-grub)
# 2.1 LINUXインストールに必要なパーティション
# 2.1.1 LINUXインストールに必要なパーティション

(1)　ルートファイルシステムにありあてるルーツパーティション
(2)　スワップ領域

次に示すてぃれくとり群は、独立したパーティションに割り当てるのが一般的です。

/home /var /usr /boot /スワップ領域 /(root)

# 2.1.2 パーティションのレイアウト設計

# 2.2　ブートローダのインストール

ハードディスクなどのストレージからOSを読み込んで起動するプログラムをブートローダといいます。代表的なLINUXのブートローダはGRUB(GRand Unified Bootloder)です。

Basically, GRUB bootloader is the software that loads the Linux kernel. (It has other uses as well.) It is the first software that starts at a system cool. When the computer starts, BIOS first run a Power on self-test(POST) to check hardware like memory, disk drives and that it works properly.

The BIOS checks the Master Boot Record (MBR), which is a 512 byte section located first on the Hard Drive. It looks for a bootloader (like GRUB). The hard drive's partition tables are also located here.

Then I'll by prompted by the GRUB menu which can contain a list of the operation systems installed, or perhaps the different kernels installed in a Linux distro.

# 2.2.1 GRUBのインストール

```
$grub-install /dev/sda
```
how to install grub

```
$grub-install -v
```
how to check the version of grub

# 2.2.2 GRUB Legacyの設定

/boot/grub/menu.lst or /boot/grub/grub.conf

parameters
: timeout, default, title, root, kernel, makeactive, chainloader, hiddenmenu
(detailed on the book)

# 2.2.3 GRUB2の設定

GRUB2はGRUB Legacyと異なり、直接ファイルを編集そろことはしません。/etc/default/grubで設定を行い、grub-mkconfigコマンド（またはgrub2-mkconfig）を実行すると、設定に基づいて、/boot/grub/grub.cfgが生成されます。

# 2.2.4　ブートオプションの指定

ブートローダ起動時に、システムの動作を指定するための様々なブートオプションを指定できます。GRUBでブートオプションを指定するには、起動時の画面でEキーを押します。

（detailed on the book） 

# 2.3　共有ライブラリ管理
# 2.3.1 スタティックリンクとダイナミックリンク

プログラムの実行時にロードされ、複数のプログラムの間で共有されるライブラリを、共有ライブラリといいます。

リンク：プログラム本体からライブラリの機能（関数）を利用します。
スタティックリンク（静的リンク）：コンパイラをする辞典で、コンパイラがライブラリを実行ファイル内に埋め込みます。
ダイナミックリンク（動的リンク）：実行ファイルへライブラリを埋め込むことはせず、実行時にライブラリの機能を呼び出す方法

ダイナミックリンクによって呼び出されるライブラリを共有ライブラリという
普通 /lib、または/usr/libの配下にlib~ .so~の名前で配置されている

# 2.3.2 必要な共有ライブラリ

```
$ldd /bin/cat
```
:print the shared labraries required by each program or shared library specified on the command line. 上のコマンドはcatコマンドが必要とする共有ライブラリを表示しています。

/lib, /usr/libディレクトリ以外のライブラリも検索する場合は、/etc/ld.so.confを参照

しかし、プロフラムを実行するたびにこれらのディレクトリを検索するのは非効率なので、実際にはバイナリのキャッシュファイルである/etc/ld.so.cacheが参照される

```
#ldconfig
```
:creates the necessary links and cache to the most recent shared libraries found in the directories specified on the command line, in the file /etc/ld.so.conf, and in the trusted directories /lib and /usr/lib. The cache is used by the run-time linker, ld.so or ld-linux.so


そのほかのディレクトリも検索対象に加えたい場合は、環境関数 LD_LIBRARY_PATH

```
$export LD_LIBRARY_PATH=$LD_LABRARY_PATH:/home/student/mylib
```　
