When there is a crisis and I have to look though the log files to identify the issue.

**/etc/rsyslog.conf** controls what goes inside some of the log files. 

- /var/log/messages : Contains global system messages,
including the messages that are logged during system startup. There are several things that are logged in /var/log/messages including mail, cron, daemon, kern, auth, etc.

- /var/log/dmesg : Contains kernel ring buffer information. When the system boots up, it prints number of messages on the screen that displays information about the hardware devices that the kernal detects during boot process. These messages are available in kernel ring buffer and whenever the new messages comes the old message gets overwritten.

- /var/log/daemon.log : Contains information logged by the various background daemons that runs on the system.

- /var/log/auth.log : Contains system authorization information, including user logins and authentication machinsm that were used.

further informations(refer) : http://www.thegeekstuff.com/2011/08/linux-var-log-files/








