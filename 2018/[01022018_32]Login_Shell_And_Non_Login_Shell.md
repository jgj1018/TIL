[ref1](http://howtolamp.com/articles/difference-between-login-and-non-login-shell/)
[ref2](https://stackoverflow.com/questions/18186929/what-are-the-differences-between-a-login-shell-and-interactive-shell)
[ref3](http://www.theunixschool.com/2010/05/login-shell-or-non-login-shell.html)

# Login Shells

A Login shell is started after a successful login, using /bin/login, by reading the /etc/passwd file. Login shell is the first process that executes under our user ID when we log in to a session. 

When Bash is invoked as a Login shell;

- Login process calls /etc/profile
- /etc/profile calls the scripts in /etc/profile.d/
- Login process calls ~/.bash_profile
- ~/.bash_profile calls ~/.bashrc
- ~/.bashrc calls /etc/bashrc

If the output is the name of our shell, prepended by a dash, then it is a login shell.
For example -bash, -su etc.

# Non Login Shells

A Non login shell is started by a program without a login. In this case, the program just passes the name of the shell executable. Sub shell or a non-login is a shell which is invoked from the login shell or from a different sub shell by just typing the name of the shell. In fact, whenever a shell script is run, a sub-shell is opened internally and the script is run from the sub-shell.


When bash is invoked as a Non login shell;

- Non-login process(shell) calls ~/.bashrc
- ~/.bashrc calls /etc/bashrc
- /etc/bashrc calls the scripts in /etc/profile.d/

If the output is the name of our shell, does not prepend by a dash, then it is a Non login shell.
For example bash, su etc.

# Login Shell and Interactive Shell.

A login shell is a shell where I login. I can recognize a login shell from a ps -f listing, it will have a hyphen at the start of the program name, for example:

```
root      3561  3553  0 09:38 pts/0    00:00:00 -bash
qa        7327  3432  0 10:46 pts/1    00:00:00 -bash
```

An interactive shell is one which reads commands from it's standard-input, usually a terminal.

For example, if I login to bash using an xterm or terminal emulator like putty, then the session is both a login shell and an interactive one. If I then type bash then I enter an interactive shell, but it is not a login shell.

If a shell script (a file containing shell commands) is run, then it is neither a login shell nor an interactive one.

# Environment variable regarding Shells.

Two environment variables are available to find or identify whether a shell is login or sub-shell.

- $SHELL : This always tells the login shell.
- $0 : This always tells the current shell.

```
#echo $SHELL
tcsh
#ksh
#echo $SHELL
tcsh
#echo $0
ksh
#
```