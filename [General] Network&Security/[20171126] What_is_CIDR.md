[reference1](http://searchnetworking.techtarget.com/definition/subnet)
[reference2](http://searchnetworking.techtarget.com/definition/subnet-mask)
[reference3](https://en.wikipedia.org/wiki/Supernetwork)
[reference4](http://searchnetworking.techtarget.com/definition/CIDR)

# What is subnet and subnet mask?

A subnet (short for "subnetwork") is an identifiably separate part of an organization's network. Typically, a subnet may represent all the machines at one geographic location, in one building, or on the same local area network (LAN). Having an organization's network divided into subnets allows it to be connected to the Internet with a single shared network address.

Some portion of the IP address represents the network number or address and some portion represents the local machine address (also known as the host number or address). IP addresses can be one of several classes, each determining how many bits represent the network number and how many represent the host number. The most common class used by large organizations (Class B) allows 16 bits for the network number and 16 for the host number.

A subnet mask is a 32- or 128-bit number that segments an existing IP address in a TCP/IP network and divides that address into discrete network and host addresses.

# What is supernet

A supernetwork, or supernet, is an Internet Protocol (IP) network that is formed, for routing purposes, from the combination of two or more networks (or subnets) into a larger network. The new routing prefix for the combined network represents the constituent networks in a single routing table entry. The process of forming a supernet is called supernetting, prefix aggregation, route aggregation, or route summarization.Supernetting requires the use of routing protocols that support Classless Inter-Domain Routing (CIDR)

# what is cidr

CIDR (Classless Inter-Domain Routing, sometimes called supernetting) is a way to allow more flexible allocation of Internet Protocol (IP) addresses than was possible with the original system of IP address classes. As a result, the number of available Internet addresses was greatly increased, which along with widespread use of network address translation (NAT), has significantly extended the useful life of IPv4.
To illustrate the problems with the class system, consider that one of the most commonly used classes was Class B. An organization that needed more than 254 host machines would often get a Class B license, even though it would have far fewer than 65,534 hosts. This resulted in most of the block of addresses allocated going unused. 
CIDR reduced the problem of wasted address space by providing a new and more flexible way to specify network addresses in routers. CIDR lets one routing table entry represent an aggregation of networks that exist in the forward path that don't need to be specified on that particular gateway. This is much like how the public telephone system uses area codes to channel calls toward a certain part of the network. This aggregation of networks in a single address is sometimes referred to as a supernet.
Using CIDR, each IP address has a network prefix that identifies either one or several network gateways. The length of the network prefix in IPv4 CIDR is also specified as part of the IP address and varies depending on the number of bits needed, rather than any arbitrary class assignment structure.

```
192.30.250.00/18
```

The "192.30.250.0" is the network address itself and the "18" says that the first 18 bits are the network part of the address, leaving the last 14 bits for specific host addresses.
