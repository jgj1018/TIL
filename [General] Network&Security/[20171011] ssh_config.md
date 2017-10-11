
[reference 1](https://www.cyberciti.biz/faq/linux-unix-ssh-proxycommand-passing-through-one-host-gateway-server/)
[reference 2](http://d.hatena.ne.jp/hi_igu/20110331/1301594082)
[refernece 3](https://linux.die.net/man/5/ssh_config)

# ~/.ssh/config

```
Host {nickname}
HostName (remotehost)
User {username}
ProxyCommand ssh {username}@{humidai} nc %h %p
IdentityFile
```

Host : Set nickname of my choice

HostName : Set the real remote server/host name

User : Set the real username for remote server/host

ProxyCommand ssh {username}@{humidai} nc %h %p :
Specifies the command to user to connect to server. In this example, I'm using nc command. Any occurrence of %h will be substituted by host name to connect %p by the port, and %r by the remote user name.

IdentityFile :
Specifies a file from which the user's RSA or DSA authentication identity is read. The default is ~/.ssh/identity for protocol version 1, and ~/.ssh/id and ~/.ssh/id_dsa protocol version 2.
