[reference1](http://blog.scoutapp.com/articles/2015/02/24/understanding-linuxs-cpu-stats)

# top command cpu status

There are 3 general states of my cpu.

- idle : means it has nothing to do
- Running a user space program : like a command shell, an email server or a compiler
- Running the kernel : servicing interrupts or managing resources.

these three meta states can be further subdivided by niceless lebel. Niceness is a way to tweak the prioirity level or those running with a nice prioirity.

when using `top` command.

The output from top is divided into two sections. The first few lines give a summary of the system resources 

```
%Cpu(s): 24.8 us,  0.5 sy,  0.0 ni, 73.6 id,  0.4 wa,  0.0 hi,  0.2 si,  0.0 st
```
- 24.8 us : this tells me that the processor is spending 24.8% of its time running user space processes. A user space program is any process that doesn't belong to the kernel. Shells, compilers, databases, web servers, and the programs associated with the desktop are all user space processes.

- 73.6 id : Skipping over a few of the other statistics, just for a moment, the id statistic tell us that the processor was idle just over 73% of the time during the last sampling period. 

- 0.5 sy :  This is the amount of time that the CPU spent running the kernel. All the processes and system resources are handled by the Linux kernel

- 0.0 ni :The ni stat shows how much time the CPU spent running user space processes that have been niced. On a system where no processes have been niced then the number will be 0.
 
- 0.4 wa : it is idle while waiting for an I/O operation to complete. The time the CPU spends in this state is shown by the wa statistic.

- 0.0 hi & 0.2 si : These two statistics show how much time the processor has spent servicing interrupts. hi is for hardware interrupts, and si is for software interrupts. Hardware interrupts are physical interrupts sent to the CPU from various peripherals like disks and network interfaces. Software interrupts come from processes running on the system. A hardware interrupt will actually cause the CPU to stop what it is doing and go handle the interrupt. A software interrupt doesn't occur at the CPU level, but rather at the kernel level.

- 0.0 st : This last number only applies to virtual machines. When Linux is running as a virtual machine on a hypervisor, the st (short for stolen) statistic shows how long the virtual CPU has spent waiting for the hypervisor to service another virtual CPU running on a different virtual machine.

