# Docker DNS

:(In user-defined networks) Docker daemon has a built-in DNS server that containers use by default. The exact details of how docker managers the DNS configurations inside the container can change from one Docker version to the next. So I have not assume the way the files such as /etc/hosts, /etc/resolv.conf are managed inside containers and leave the files alone and use docker options instead. 

- DNS default names
: Docker defaults the hostname to the container's name, but I can also set aliases.

: Bridge server does not have the DNS server built in it by default. I can use `--link`

- --link=CONTAINER_NAME:ALIAS

 :Add link to another container
 :but it's much easier to create a new network for my apps so that I don't have to do this everyytime.
 :Using this option as you `run` a container gives the embedded DNS an extra entry named `ALIAS` that points to the IP address of the container identified by `CONTAINER_NAME`. When using `--link` the embedded DNS will guarantee that localized lookup result only on that container where the `--link` is used. This lets processes inside the new container connect to container without having to know its name or IP.
