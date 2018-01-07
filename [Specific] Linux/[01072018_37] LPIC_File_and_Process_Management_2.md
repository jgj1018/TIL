[ref1](https://slackbook.org/html/process-control-ps.html)
[ref2](http://meinit.nl/the-3-most-important-kill-signals-on-the-linux-unix-command-line)

## ps Command

```
% ps
   PID TTY          TIME CMD
  7923 ttyp0    00:00:00 bash
  8059 ttyp0    00:00:00 ps
```

# TTY ?

The TTY column indicates which terminal the process is running on. Doing a plain ps will only list all the programs running on the current terminal, so all the processes give the same information in the TTY column. As you can see, both processes listed are running on ttyp0. This indicates that they are either running remotely or from an X terminal of some variety.

```
% ps -ax
 PID TTY      STAT   TIME COMMAND
   1 ?        S      0:03 init [3]
   2 ?        SW     0:13 [kflushd]
   3 ?        SW     0:14 [kupdate]
   4 ?        SW     0:00 [kpiod]
   ...
```

# TTY "?"?
First, you'll notice that most of these processes are listed as running on tty “?”. Those are not attached to any particular terminal. This is most common with daemons, which are processes which run without attaching to any particular terminal. Common daemons are sendmail, BIND, apache, and NFS. They typically listen for some request from a client, and return information to it upon request.

# STAT?

there is a new column: STAT. It shows the status of the process. PROCESS STATE CODES
Here are the different values that the s, stat and state output specifiers (header "STAT" or "S") will display to describe the state of a process:

```
               D    uninterruptible sleep (usually IO)
               R    running or runnable (on run queue)
               S    interruptible sleep (waiting for an event to complete)
               T    stopped by job control signal
               t    stopped by debugger during the tracing
               W    paging (not valid since the 2.6.xx kernel)
               X    dead (should never be seen)
               Z    defunct ("zombie") process, terminated but not reaped by its parent
```

For BSD formats and when the stat keyword is used, additional characters may be displayed:

```
               <    high-priority (not nice to other users)
               N    low-priority (nice to other users)
               L    has pages locked into memory (for real-time and custom IO)
               s    is a session leader
               l    is multi-threaded (using CLONE_THREAD, like NPTL pthreads do)
               +    is in the foreground process group


```

# Signal number 15 > 9 

Generally, you should use kill -15 before kill -9 to give the target process a chance to clean up after itself. (Processes can't catch or ignore SIGKILL, but they can and often do catch SIGTERM.) If you don't give the process a chance to finish what it's doing and clean up, it may leave corrupted files (or other state) around that it won't be able to understand once restarted.

# Signal HUP (1)
-1 or -HUP - This argument makes kill send the "Hang Up" signal to processes. This probably originates from the modem/dial-in era. Processes have to be programmed to actually listen to this process and do something with it. Most daemons are programmed to re-read their configuration when they receive such a signal. Anyway; this is very likely the safest kill signal there is, it should not obstruct anything.