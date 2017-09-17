#recap

- --network bridge

Default Docker virtual network, which is NAT'ed behind the host IP

- --network host

It gains performance by skipping virtual networks but sacrifices security of container modeldock

- --network none

removes eth0 and only leaves you with localhost interface in container

#network command

A bridge network resides on a single host runnig an instance of Dokcer Engine. 
 
- docker network create {network name}
  : it creates a bridge network for you(user-defined network) if the option --driver is not given then the network will be created as a **bridge** network. Else the specified drive will be used. 

- docker network connect {network name} {container name} 
  : connects the given container to the specified network

- docker network disconnect {network name} {container name} 
  : Disconnects the given container to the specified network.

- docker container run -d --name {container name} --network {network name} nginx
  : add containers to a network

#further information

While I can disconnect a container from a network, I can't remove the builtin **bridge** network named **bridge**. Networks are natural ways to isolate containers from other containers or other networks.  


