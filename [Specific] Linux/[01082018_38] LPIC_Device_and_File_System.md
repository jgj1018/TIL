[ref1](https://www.centos.org/docs/5/html/5.1/Deployment_Guide/s1-lvm-intro-whatis.html)
[ref2](https://www.centos.org/docs/5/html/5.2/Deployment_Guide/s1-swap-what-is.html)


## LVM? 

LVM is a tool for logical volume management which includes allocating disks, striping, mirroring and resizing logical volumes. With LVM, a hard drive or set of hard drives is allocated to one or more physical volumes. LVM physical volumes can be placed on other block devices which might span two or more disks. The physical volumes are combined into logical volumes, with the exception of the /boot/ partition.

![FIGURE](https://www.centos.org/docs/5/html/5.1/Deployment_Guide/images/lvg.png)

The volume groups can be divided into logical volumes, which are assigned mount points, such as /home and / and file system types, such as ext2 or ext3. When "partitions" reach their full capacity, free space from the volume group can be added to the logical volume to increase the size of the partition. When a new hard drive is added to the system, it can be added to the volume group, and partitions that are logical volumes can be increased in size.

## SWAP space in Linux

Swap space in Linux is used when the amount of physical memory (RAM) is full. If the system needs more memory resources and the RAM is full, inactive pages in memory are moved to the swap space. While swap space can help machines with a small amount of RAM, it should not be considered a replacement for more RAM. Swap space is located on hard drives, which have a slower access time than physical memory.

Swap space can be a dedicated swap partition (recommended), a swap file, or a combination of swap partitions and swap files.

File systems and LVM2 volumes assigned as swap space cannot be in use when being modified. For example, no system processes can be assigned the swap space, as well as no amount of swap should be allocated and used by the kernel. Use the free and cat /proc/swaps commands to verify how much and where swap is in use.

