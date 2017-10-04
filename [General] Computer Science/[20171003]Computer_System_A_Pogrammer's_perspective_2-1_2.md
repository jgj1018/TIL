# 2.1.2 Words

Every computer has a word size, indicating the nominal size of integer and pointer data. Since a virtual address is encoded by such a word, the most important system parameter determined by the word size is the maximum size of the virtual address space. That is, for a machine with a w-bit word size, the virtual addresses can range from 0 to 2w(square) - 1, giving the program access to at most 2w(square) bytes.


# 2.1.4 Addressing and Byte Ordering

In virtually all machines, a multi-byte object is stored as a contiguous sequence of bytes, with the address of the object given by the smallest address of the bytes used. For example, suppose a variable x of type int has address 0x100, that is, the value of the address expression &x is 0x100. Then the 4 bytes of x would be stored in memory locations 0x100, 0x101, 0x102, and 0x103.

For ordering the bytes representing an object, there are two common conventions. 
Some machines choose to store the object in memory ordered from least significant byt byte to most, while other machines store them from most to least.

(1) Big endian
(2) Little endian

Many recent microprocessors are bi-endian, meaning that they can be configured to operate as  either little- or big-endian machines.

For most application programmers, the byte orderings used by their machines are totally invisible; At times, however, byte ordering becomes an issue. The first is when binary data are communicated over a network between different machines. A common problem is for data produced by a little-endian machine to be sent to a big-endian machine, or vice versa. To avoid such problems, code written for networking applications mush follow established conventions for byte ordering to make sure the sending machine converts its internal representation to the network standard, while the receiving machine converts the network standard to its internal representation.


76p