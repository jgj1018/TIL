[ref1](http://whatis.techtarget.com/definition/IRQ-interrupt-request)
[ref2](https://www.lifewire.com/what-is-pci-2640242)
[ref3](https://linux.die.net/lkmpg/x40.html)

# device information

/proc/cpuinfo
/proc/interrupts : IRQ infomation
/proc/ioports
/proc/meminfo
/proc/bus/usb/*
/proc/bus/pci/* :pci device information

# IRQ Interrupt request

An IRQ (interrupt request) value is an assigned location where the computer can expect a particular device to interrupt it when the device sends the computer signals about its operation. For example, when a printer has finished printing, it sends an interrupt signal to the computer. 


# PCI Peripheral Componenet Interconnect

PCI is an abbreviation for Peripheral Component Interconnect, which is a term used to describe a common connection interface for attaching computer peripherals to a PC's motherboard, or main circuit board. It is also called a PCI bus. A bus is a term for a path between the components of a computer.

# lspci

lspci is a utility for displaying information about PCI buses in the system and devices connected to them.

- -v Be verbose and display detailed information about all devices.

#lsmod 

lsmod is a trivial program which nicely formats the contents of the /proc/modules, showing what kernel modules are currently loaded.

# Kernal Module?

What exactly is a kernel module? Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality of the kernel without the need to reboot the system. For example, one type of module is the device driver, which allows the kernel to access hardware connected to the system. Without modules, we would have to build monolithic kernels and add new functionality directly into the kernel image. Besides having larger kernels, this has the disadvantage of requiring us to rebuild and reboot the kernel every time we want new functionality.

# modprobe

modprobe intelligently adds or removes a module from the Linux kernel