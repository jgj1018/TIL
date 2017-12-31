[ref1](https://unix.stackexchange.com/questions/198178/what-are-the-concepts-of-kernel-ring-buffer-user-level-log-level)
[ref2](https://www.liquidweb.com/kb/linux-runlevels-explained/)

# System booting flow

BIOS/UEFI -> bootloader -> kernel -> init/systemd

# dmesg

print or control the kernel ring buffer. The default action is to read all messages from kernel ring buffer.

# Ring buffer? 

The kernel keeps its logs in a ring buffer. The main reason for this is so that the logs from the system startup get saved until the syslog daemon gets a chance to start up and collect them. Otherwise there would be no record of any logs prior to the startup of the syslog daemon. The contents of that ring buffer can be seen at any time using the dmesg command, and its contents are also saved to /var/log/dmesg just as the syslog daemon is starting up.

All logs that do not come from the kernel are sent as they are generated to the syslog daemon so they are not kept in any buffers. The kernel logs are also picked up by the syslog daemon as they are generated but they also continue to be saved (unnecessarily, arguably) to the ring buffer.

```
LOG_EMERG: system is unusable
LOG_ALERT: action must be taken immediately
LOG_CRIT: critical conditions
LOG_ERR: error conditions
LOG_WARNING: warning conditions
LOG_NOTICE: normal, but significant, condition
LOG_INFO: informational message
LOG_DEBUG: debug-level message
```

# Run level

A runlevel is one of the modes that a Unix -based operating system will run in. Each runlevel has a certain number of services stopped or started, giving the user control over the behavior of the machine. Conventionally, seven runlevels exist, numbered from zero to six.

runlevel prints the previous and current SysV runlevel if they are known.

```
#runlevel
N 5
```
