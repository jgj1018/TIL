[reference 1](https://docs.docker.com/engine/userguide/storagedriver/imagesandcontainers/)
[reference 2](https://stackoverflow.com/questions/31222377/what-are-docker-image-layers)

# Image

- App binaries and dependencies.
- Images are made up of file sysytem changes and metadata. Metadata about the image data and how to run the image.
- An image is an ordered collection of root filesystem changes and the corresponding execution parameters for use within a container runtime.
- Not a complete OS, No kernel, kernel modules like drivers.
- Small as one file(my app binary) like a golang static binary.
- Big as a Ubuntu distro with apt, and Apache, PHP, and more installed.
- A container is just a single read/write layer of top of image.

# Layer

- a layer of image layer is a change on an image, or an intermediate image. Every command I specify in a Dockerfile causes the previous image to change, thus creating a new layer. I can think of it as staging changes on git.

- Each layer is uniquely identified and only stored once on a host. This saves storage space on host and transfer time on push/pull

- When I create a new container, I add a new writable payer on top of the underlying layers. When the container is deleted, the writable layer is also deleted. The underlying image remains unchanged.


- docker image history (docker history - old way)

: show layers of changes made in image. Every image starts from the very beginning with a blank layer known as scratch. 

- docker image inspect (docker inspect - old way)

: returns JSON metadata about the image.