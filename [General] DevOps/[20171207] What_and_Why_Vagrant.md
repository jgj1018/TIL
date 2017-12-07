[ref1](https://www.slashroot.in/what-vagrant-and-how-does-it-work)
[ref2](https://www.vagrantup.com/intro/index.html)

# What and Why Vagrant

Most of the times, the development work carried out by developers are on either Mac or Windows. Most of the times it's a combination of both(If I am working in a development team, some of them might be using a Mac, and some of them Windows). And the applications developed will be running on Linux servers in production.

Majority of the times, it’s not the installation of application components that’s difficult, it's the configuration part that creates the trouble.

What about keeping the application dependency configuration and environment completely in perfect sync with other developers working in the project.

These are the problems, that vagrant is trying to solve. Vagrant will let developers work on the same exact mirror configuration that is running in production environment. Vagrant achieves all of this by using virtualization.

`
Virtualization is nothing but a method to create a vitual hardware, with required resources allocated, to run another operating system on top of it. To make it much more simple, consider virutalization as a method to run an operating system on top of another operating system, by slicing up the hardware.
`

Once I or someone else creates a single Vagrantfile, I just need to vagrant up and everything is installed and configured for me to work. 
If I am an operations engineer or DevOps engineer, Vagrant gives me a disposable environment and consistent workflow for developing and testing infrastructure management scripts. I can quickly test things like shell scripts, Chef cookbooks, Puppet modules, and more using local virtualization such as VirtualBox or VMware.