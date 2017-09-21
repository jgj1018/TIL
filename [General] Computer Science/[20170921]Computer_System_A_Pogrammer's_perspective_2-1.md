#Part1: Program Structure and Execution

- 2 Representing and Manipulating information

The different mathematical properties of interger vs floating-point arithmetic stem from the difference in how they handle the finiteness of their representations -integer representations can encode a comparatively small range of values, but do so precisely, while floating-point representations can encode a wide range of values, but only approximately.

This understanding is critical to writing programs that work correctly over the full range of numeric values and that are portable across different combinations of machne, operating system, and compiler.

A number of computer security vulnerabilities have arisen due to some of the subtleties of computer arithmetic.

- 2.1 Information Storage

Rather than accessing individual bits in memory, most computers use blocks of eight bits, or bytes, as a smallest addressable unit of memory. A machine-level program views memory as a very large array of bytes, referred to as virtual memory. Every byte of memory is identified by a unique number, known as its address, and the set of all possible addresses is known as the virtual address space. this virtual address space is just a conceptual image presented to the machine-level program. The actual implementation uses a combination of random-access memory, disk storage, special hardware, and operating system software to provide the program with what appears to be a monolithic byte array.

The value of a pointer in C-Whether it points to an integer, a structure, or some other program object-is the virtual address of the first byte of some block of storage.

The C compiler also associates type information with each pointer, so that it can henerate different machine-level code to access the value stored at the location designated by the pointer depending on the type of that value. Although the C compiler maintains this type information, the actual machine-level program it generates has no information about data types. It simply treats each program object as a block of bytes, and the program itself as a sequence of bytes.

