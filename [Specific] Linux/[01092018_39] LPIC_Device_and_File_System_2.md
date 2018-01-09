[ref1](https://www.howtogeek.com/howto/38125/htg-explains-what-is-the-linux-fstab-and-how-does-it-work/)
[ref2](https://askubuntu.com/questions/754091/what-is-the-difference-between-etc-fstab-and-etc-mtab)
[ref3](http://www.linfo.org/etc_fstab.html)
[ref4](https://unix.stackexchange.com/questions/5915/difference-between-bin-and-usr-bin)

## Fstab?

Fstab is my operating system’s file system table. it was the primary way that the system mounted files automatically. I tell the computer that anytime a specific device was plugged in, it should be automatically mounted in a specific place. This is where fstab came in.

# /etc/fstab 

/etc/fstab is created automatically when the operating system is installed, and it is modified automatically when changes are made to the filesystems. 

```
# <file system>        <dir>         <type>    <options>             <dump> <pass>

/dev/sda1              /             ext4      defaults,noatime      0      1
/dev/sda2              none          swap      defaults              0      0
/dev/sda3              /home         ext4      defaults,noatime      0      2
```

- The first column lists the physical location of each filesystem
- The second column shows the mount point, which is the directory in which the filesystem listed on that line is attached to the root filesystem
- The third column shows the filesystem type with which each partition or device is formatted.
- The fourth column adds some basic security to the system by designating by whom and how the filesystem or device can be used. Numerous possible options are available, and any number of them can be used, provided that they are separated with commas and do not conflict with each other.
- The fifth column is used to determine whether the dump command will back up the filesystem. This column is rarely used and has two options: 0, do not dump, which is used for most partitions, and 1, dump, which is used for the root partition.
- he sixth column is used by the fsck program to determine the order in which the computer checks the filesystems when it boots. The three possible values for the column are: 0, do not check, 1, check first (only the root partition should have this setting) and 2, check after the root partition has been checked. Most Linux distributions set all the partitions to 0, except for the root partition. If maintenance is important, 2 should be used, although this can increase the amount of time required for booting.

# tmpfs?

tmpfs is a file system that stores all the files in virtual memory. tmpfs doesn't create any files on my hard drive. So if I unmount a tmpfs file system, all the files residing in it are lost for ever. 

tmpfs is similar to ramfs and RAM disk but with a few additional features. tmpfs is able to grow or shrink its space to accommodate files,and it can use swap space to store unneeded data. ramfs and RAM disk doesn't have this capability.

# between /etc/fstab and /etc/mtab

/etc/fstab is list of filesystems to be mounted at boot time. If I want my Windows or file-storage partition mounted once my computer boots , I put appropriate entry into /etc/fstab.

/etc/mtab is list of currently mounted filesystems. If I have a disk connected but not mounted, it won't show up in the /etc/mtab file. Once I mount it, it will show up there.

# between /bin and /usr/bin

- /bin

contains commands that may be used by both the system administrator and by users, but which are required when no other filesystems are mounted (e.g. in single user mode). It may also contain commands which are used indirectly by scripts

- /usr/bin/

This is the primary directory of executable commands on the system.