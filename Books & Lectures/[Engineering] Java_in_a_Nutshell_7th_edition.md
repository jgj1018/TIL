The JVM is a program that provides the runtime environment necessary for Java programs to execute. Java programs cannot run unless there is a JVM available for the appropriate hardware and OS platform we wish to execute on.

The purposes of JVM

* Comprise a container for application code to run inside

* Provide a secure and reliable execution environment as compared to C/C++

* Take memory management out of the hands of developers

* Provide a cross-platform execution environment

In addition to these four primary goals, there is another aspect of the JVM’s design that is not always recognized or discussed—it makes use of runtime information to self-manage.

The JVM uses the available runtime information to deliver higher performance than was possible from purely interpreted execution.

computer scientists would call bytecode a type of intermediate representation—a halfway house between source code and machine code. The whole aim of bytecode is to be a format that can be executed efficiently by the JVM’s interpreter.

In theoretical computer science terms, javac is most similar to the front half of a compiler—it creates the intermediate representation that can then be used later to produce (emit) machine code.

Fundamental to the design of the security model is that bytecode is heavily restricted in what it can express—there is no way, for example, to directly address memory

While the design is still theoretically robust, the implementation of the security architecture is another matter,

Java Compared to Python

* Java is statically typed; Python is dynamically typed.

* Java is multithreaded; Python only allows one thread to execute Python at once.

* Java has a JIT; the main implementation of Python does not.

* Java’s bytecode has extensive static checks; Python’s bytecode does not.