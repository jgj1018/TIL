[ref1](https://linuxconfig.org/internal-vs-external-linux-shell-commands)
[ref2](https://www.computerhope.com/unix/uman.htm)
[ref3](http://www.linfo.org/touch.html)
[ref4](https://www.tecmint.com/8-pratical-examples-of-linux-touch-command/)


# Internal Command and External Command

The internals (a small number, especially compared to the rest of them) are the commands that are built in your shell. This is why we deemed important to check the shell and the version, because other shells may have different built-ins or none at all. Commands that you will use very often like cd - change directory - are shell built-ins.

```
 $ type cd
cd is a shell builtin
 $ type bash
bash is /usr/bin/bash
 $ type type
type is a shell builtin
```

Let's see what external commands are. They are the commands that your system offer, the ones that are totally shell-independent and usually can be found in any Linux distribution. They mostly reside in /bin and /usr/bin, and those locations must be part of your $PATH variable in order to be usable.

# Man page Sections.

The section numbers of the manual are listed below. While reading documentation, if you see a command name followed by a number in parentheses, the number refers to one of these sections. For example, man is the documentation of man found in section number 1. Some commands may have documentation in more than one section, so the numbers after the command name may direct you to the correct section to find a specific type of information.

- 1: Executable programs or shell commands
- 2: System calls (functions provided by the kernel)
- 3: Library calls (functions within program libraries)
- 4: Special files (usually found in /dev)
- 5: File formats and conventions eg /etc/passwd
- 6: Games
- 7: Miscellaneous (including macro packages and conventions), e.g., man, groff
- 8: System administration commands (usually only for root)
- 9: Kernells routines [Non standard]

# touch Command

The touch command is the easiest way to create new, empty files. It is also used to change the timestamps (i.e., dates and times of the most recent access and modification) on existing files and directories.

touch's syntax is

```
touch [option] file_name(s)
```

A nice feature of touch is that, in contrast to some commands such as cp (which is used to copy files and directories) and mv (which is used to move or rename files and directories), it does not automatically overwrite (i.e., erase the contents of) existing files with the same name. Rather, it merely changes the last access times for such files to the current time.

Several of touch's options are specifically designed to allow the user to change the timestamps for files. For example, the -a option changes only the access time, while the -m option changes only the modification time. The use of both of these options together changes both the access and modification times to the current time, for example:

```
touch -am file3
```

the below command touch command with -t option will gives the tecmint file a time stamp of 18:30:55 p.m. on December 10, 2012.

```
touch -t 201212101830.55 tecmint
```
