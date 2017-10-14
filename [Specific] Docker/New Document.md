# Image

- App binaries and dependencies.
- Metadata about the image data and how to run the image.
- An image is an ordered collection of root filesystem changes and the corresponding execution parameters for use within a container runtime.
- Not a complete OS, No kernel, kernel modules like drivers.
- Small as one file(my app binary) like a golang static binary.
- Big as a Ubuntu distro with apt, and Apache, PHP, and more installed.