### 3. Networking

```
ip address add 192.168.1.202/24 dev enp0s3
```

```
/etc/sysconfig/network-scripts/ifcfg-enp0s3

1   IPADDR=192.168.10.19
2   BOOTPROTO=static
3   NETMASK=255.255.255.0
4   TYPE=Ethernet
```

-  We’ll have to set the parameter ONBOOT=yes, so that the network interface gets activated every time the system boots. This way, we have assigned a static IP address to the server, but it is more convenient to use a network utility. In CentOS 6 we used system-config-network, but this command is not available in CentOS 7. Instead, we must use nmtui

- Sometimes we have to know the open ports that can be accessed through the network. It could happen that a service is listening in a port in the local machine, but a firewall or a filter of some kind exists between the server and the client. In this case, obviously, there would be no communication between the two computers. To prove whether a port is accessible or not, we can use nmap.


### 4. DNS

- Today, DNS service is a critical part of IT infrastructure, as many other services depend on it to work properly. Unfortunately, this characteristic makes it an interesting target for hackers too. In order to minimize the risks of an attack, a lot of attention must be paid when configuring the service.


- a DNS server translates names into IP addresses. But it can do this through different approaches.

- Cache only server. In this case, the server doesn’t hold any information about the associated name–IP addresses, so it has to query another server. But once it gets an answer, it keeps it in the cache, so that when another client performs the same query, it can respond quickly, without forwarding the request to another server.

- Master server. This is a server that holds a copy of the names and IP addresses of the computers belonging to the domain in what is called a zone. A master server has the authority to change an IP associated with a certain name, as well as to add or delete new registers.

- Slave server. This type of server holds a copy of the zone too, but it is a read-only one. A slave server has all the information it needs to answer queries about the domain, but it cannot change, add, or delete any register.