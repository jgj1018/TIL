[ref1](https://www.crybit.com/difference-between-tar-and-gzip/)
[ref2](http://www.differencebetween.net/technology/difference-between-gzip-and-tar/)
[ref3](http://www.penguintutor.com/linux/file-permissions-reference)

# Difference Between GZIP and TAR

The .tar.gz extension is a very popular one when downloading files especially in non Windows operating systems. But unlike most extensions, this is not meant to identify a single program that would be used to open this file; it points to two. Tar is a file format but is also the name of the program that produces the file. Tar is an archiver, meaning it would archive multiple files into a single file but without compression. Gzip which handles the .gz extension is the compression tool that is used to reduce the disk space used by the file.

- 1, Gzip is a compression tool used to reduce the size of a file
- 2, Tar is an archiver used to to combine multiple files into one

# Permission - Octal Number

In Octal format the mode is based upon a octal number representing the different mode permissions, where each of the permission groups (user, group, others) has an octal value representing the read, write and execute bits. This requires a little bit of knowledge on binary or octal number bases. The format is actually octal (but this can be likened to 3 separate binary to decimal conversions for each of the user/group/all permissions). The main benefits of using octal format is that all the permissions are set at the same time and the command is much shorter than if all the permissions were set using the symbolic format.

```
            User    Group   Others

Symbolic    rwx     rw-     r--

Binary      111     110     100

            4+2+1   4+2+0   4+0+0

Octal       7       6       4
```

The above file would have the octal number 764 and would therefore be changed using the command

- chmod 764 file1

An alternative way of working out the octal values is to add the following numbers depending upon the permission required.

```
Read = 4
Write = 2
Execute = 1
```

Therefore if I wanted to set read to yes, write to no and execute to yes, this would be 4+1=5