[ref1](http://www.tldp.org/LDP/tlk/kernel/processes.html)

Linux can manage the processes in the system, each process is represented by a task_struct data structure. The task vector is an array of pointers to every task_struct data structure in the system. As processes are created, a new task_struct is allocated from system memory and added into the task vector. To make it easy to find, the current, running, process is pointed to by the current pointer.

## State

- Running : The process is either running (it is the current process in the system) or it is ready to run (it is waiting to be assigned to one of the system's CPUs).
- Waiting : The process is waiting for an event or for a resource. Linux differentiates between two types of waiting process; interruptible and uninterruptible. 
- Stopped : The process has been stopped, usually by receiving a signal
- Zombie : This is a halted process which, for some reason, still has a task_struct data structure in the task vector. It is what it sounds like, a dead process.

## Identifier?

Every process in the system has a process identifier. The process identifier is not an index into the task vector, it is simply a number. Each process also has User and group identifiers, these are used to control this processes access to the files and devices in the system.

## Scheduling

All processes run partially in user mode and partially in system mode. How these modes are supported by the underlying hardware differs but generally there is a secure mechanism for getting from user mode into system mode and back again. User mode has far less privileges than system mode. Each time a process makes a system call it swaps from user mode to system mode and continues executing. At this point the kernel is executing on behalf of the process. In Linux, processes do not preempt the current, running process, they cannot stop it from running so that they can run. Each process decides to relinquish the CPU that it is running on when it has to wait for some system event.

Processes are always making system calls and so may often need to wait. Even so, if a process executes until it waits then it still might use a disproportionate amount of CPU time and so Linux uses pre-emptive scheduling. In this scheme, each process is allowed to run for a small amount of time, 200ms, and, when this time has expired another process is selected to run and the original process is made to wait for a little while until it can run again. This small amount of time is known as a time-slice.

It is the scheduler that must select the most deserving process to run out of all of the runnable processes in the system.

- Policy

This is the scheduling policy that will be applied to this process. There are two types of Linux process, normal and real time. Real time processes have a higher priority than all of the other processes. If there is a real time process ready to run, it will always run first. Real time processes may have two types of policy, round robin and first in first out. In round robin scheduling, each runnable real time process is run in turn and in first in, first out scheduling each runnable process is run in the order that it is in on the run queue and that order is never changed.