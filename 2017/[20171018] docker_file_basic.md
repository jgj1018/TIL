
[reference1](https://docs.docker.com/engine/reference/builder/)

# Build command 

Docker can build images automatically by reading the instructions from a Dockerfile. 

It's best to start with an empty directory as context and keep my Dockerfile in that directory. I use -f flag with `docker build` to point to a Dockerfile anywhere in my file system.

```
docker build -f /path/to/a/Dockerfile .
```

I can specify a repository and tag at which to save the new image if the build succeeds.

```
docker build shykes/myapp .
```

# Format 

- FROM  

:this instruction specifies the Base image from which I'm building 

- ENV
 
```
ENV <key> <value>
ENV <key>=<value>
```
:It's a way to set environment variables. It's preferred way to inject key/value is they work everywhere, on every OS and config.

The second form allows for multiple variables to be set at one time. For example

```
ENV myName="John Doe" myDog=Rex\ The\ Dog \
    myCat=fluffy

(is equal with)

ENV myName John Doe
ENV myDog Rex The Dog
ENV myCat fluffy
```


- RUN
 
It has two forms.

```
RUN <Command>
RUN ["executable", "param1", "param2"]

```
: It will execute any commands in a new layer on top of the current image and commit the results. The resulting committed image will be used for the next step in the Dockerfile.

```
RUN /bin/bash -c 'source $HOME/.bashrc; \
echo $HOME'

(is equal with)

RUN /bin/bash -c 'source $HOME/.bashrc; echo $HOME'
```

In the shell form, Backslash continue a single RUN instruction onto the next line.

- EXPOSE 

```
EXPOSE <port> [<port>/<protocol>...]
```
:This instruction informs Docker that the container listens on the specified network port at runtime. I can specify whether the port listens on TCP or UDP, and the default is TCP if the protocol is not specified. It doesn't actually publish the port. It functions as a type of documentation between the person who builds the image and the person who runs the container, about which ports are intended to be published. To actually publish the port when running the container, use the -p flag on `docker run
`. 
