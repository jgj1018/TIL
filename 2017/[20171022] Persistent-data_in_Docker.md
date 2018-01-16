[reference1](https://docs.docker.com/engine/admin/volumes/)


what about databases? or unique data?

-> The data won't persist when that container is no longer running, it can be difficult to get the data out of the container if another process needs it.
-> A container's writable layer is tightly coupled to the host machine where the container is running. I can't easily move the data somwhere else.
-> Writing into a container's writable layer requires a storage driver to manage the filesystem. It provides a union filesystem, using the Linux kernel. This extra abstraction reduces performance. 

: Docker gives us features to ensure these "separation of concerns". Our unique data is still where it needs to be and was preserved for us while our container was recycled.


# Two ways: Volumes and Bind Mounts

:No matter which type of mount I choose to use, the data looks the same from within the container. It is exposed as either a directory or an individual file in the container's filesystem.

- Volumes
: It make special location outside of container union file system to store unique data. Volumes are stored in a part of the host file system which is managed by Docker(/var/lib/docker/volumes/ on Linux), Non-Docker processes should not modify this part of the filesystem. Volumes are the best way to persist data in Docker.This preserves it across container removals and allows us to attach it to whatever container we want. And container just sees it like a local file path.

- Bind Mounts
: Link container path to host path. It may be stored anywhere on the host system. They may even be inportant system files or directories. Non-Docker processes on the Docker host or a Docker container can modify them at any time. It is simply sharing or mounting a host directory or file into a container. It will look like a local file path or a directory path to the container. It won't actually know that it's coming from the host.

- One side effect of using bind mounts, for better or for worse, is that I can change the host filesystem via processes running in a container, including creating, modifying, or deleting important system files or directories. 