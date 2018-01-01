[ref1](https://www.digitalocean.com/community/tutorials/understanding-systemd-units-and-unit-files)
[ref2](http://searchdatacenter.techtarget.com/definition/boot-loader-boot-manager)
[ref3](http://www.linfo.org/mbr.html)
[ref4](http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html)

# Systemd Unit

In systemd, a unit refers to any resource that the system knows how to operate on and manage. This is the primary object that the systemd tools know how to deal with. These resources are defined using configuration files called unit files.

Units in some ways can be said to similar to services or jobs in other init systems. However, a unit has a much broader definition, as these can be used to abstract services, network resources, devices, filesystem mounts, and isolated resource pools.

- service : A service unit describes how to manage a service or application on the server. This will include how to start or stop the service, under which circumstances it should be automatically started, and the dependency and ordering information for related software.

- device : A unit that describes a device that has been designated as needing systemd management by udev or the sysfs filesystem. Not all devices will have .device files. Some scenarios where .device units may be necessary are for ordering, mounting, and accessing the devices.

- mount : This unit defines a mountpoint on the system to be managed by systemd. These are named after the mount path, with slashes changed to dashes. Entries within /etc/fstab can have units created automatically.

- swap : This unit describes swap space on the system. The name of these units must reflect the device or file path of the space.

- target : A target unit is used to provide synchronization points for other units when booting up or changing states. 

# Boot loader

A boot loader, also called a boot manager, is a small program that places the operating system (OS) of a computer into memory. When a computer is powered-up or restarted, the basic input/output system (BIOS) performs some initial tests, and then transfers control to the master boot record (MBR) where the boot loader resides.

# MBR (Master Boot Record)

	
The master boot record (MBR) is a small program that is executed when a computer is booting (i.e., starting up) in order to find the operating system and load it into memory.

During the first stage of the boot process, the BIOS (basic input output system) searches for the MBR and then loads it into memory, after which the MBR takes over. The BIOS is a small program that usually resides in a flash memory chip. Flash memory is a type of memory that retains its contents even in the absence of a power supply.

The BIOS will search for an MBR in any of several devices or media, such as the hard disk drive (HDD), floppy disk, CDROM and USB (universal serial bus) key drive, with the search sequence depending on how the BIOS has been configured. The BIOS loads the first MBR that it locates, which is usually the one on the HDD. The BIOS looks for the MBR on the HDD in a standard location, which is the first sector and the first head in the first cylinder (designated as cylinder 0, head 0, sector 1). This is commonly referred to as the boot sector.


# shard library 

Shared libraries are libraries that are loaded by programs when they start. When a shared library is installed properly, all programs that start afterwards automatically use the new shared library.

# ldd

ldd - print shared library dependencies. ldd prints the shared libraries required by each program or shared library specified on the command lin
