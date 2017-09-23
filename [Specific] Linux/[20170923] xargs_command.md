# xargs command

: build and execute command lines from `standard input`
This executes /bin/echo command over the input from stdin. 

```
find /tmp -name core -type f -print | xargs /bin/rm -f
```

Find files named **core** in or below the directory **/tmp** and delete them. Note that this will work incorrectly if there are any filenames containing newlines or spaces.

```
find /tmp -name core -type f -print0 | xargs -0 /bin/rm -f
```

Find files named **core** in or below the directory **/tmp** and delete them, processing filenames in such a way that file or directory names containing spaces or newlines are correctly handled.



- -0 --null

 Input items are terminated by a null character instead of by whitespace, and the quotes and backslash are not special(every character is taken literally). Disables the end of file string, which is treated like any other argument. Useful when input items might contain white space, quote marks, or backslashes. The GNU find -print0 option produces input suitable for this mode.


[references 1](http://www.tutorialspoint.com/unix_commands/xargs.htm)

[references 2](http://www.thegeekstuff.com/2013/12/xargs-examples)