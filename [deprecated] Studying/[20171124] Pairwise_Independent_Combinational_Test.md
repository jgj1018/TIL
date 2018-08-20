[refernece1](http://www.softwaretestinghelp.com/what-is-pairwise-testing/) 
[reference2](http://www.amibugshare.com/pict/help.html)

# Why pairwise testing?

Pairwise Testing is a test design technique that delivers hundred percent test coverage.

The output of a software application depends on many factors e.g. input parameters, state variables and environment configurations. Techniques like boundary value analysis and equivalence partitioning can be useful to identify the possible values for individual factors. But it is impractical to test all possible combinations of values for all those factors. So instead a subset of combinations is generated to satisfy all factors.

# PICT (pairwise independent combinational testing)

PICT generates test cases and test configurations. With PICT, I can generate tests that are more effective than manually generated tests and in a fraction of the time required by hands-on test case design.

PICT runs as a command line tool. Prepare a model file detailing the parameters of the interface (or set of configurations, or data) I want to test. PICT generates a compact set of parameter value choices that represent the test cases I should use to get comprehensive combinatorial coverage of my parameters.

# Running PICT

- Upload your model to the PICT web interface.
- Select your options
:Order of operations
:Randomize generation, N - seed
:Case-sensitive model evaluation
:Show model statistics
:Generate log file not implemented
- Upload your seeding rows
- Select output method

- Model Section 

at least one, and at most.
```
parameter definitions
 
[sub-model definitions]
 
[constraint definitions]
```
Model sections should always be specified in the order shown above and cannot overlap. The parameters definition section comes first, followed by the optional sub-model and constraints sections, if I use them. Sections do not require any special separators between them. Empty lines can appear anywhere.

```
<ParamName> : <Value1>, <Value2>, <Value3>, ...
```

- Example
 
```
Type:          Primary, Logical, Single, Span, Stripe, Mirror, RAID-5
Size:          10, 100, 500, 1000, 5000, 10000, 40000
Format method: quick, slow
File system:   FAT, FAT32, NTFS
Cluster size:  512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
Compression:   on, off
```

# Sub-Model

Sub-models allow you to bundle certain parameters into groups that get their own combinatory orders. This can be useful if combinations of certain parameters need to be tested more thoroughly or must be combined in separation from the other parameters in the model. The sub-model definition has the following format:

```
{<ParamName1>, <ParamName2>, <ParamName3>, ... } @ <Order>
```

- Example 

```
PLATFORM:  x86, ia64, amd64
CPUS:      Single, Dual, Quad
RAM:       128MB, 1GB, 4GB, 64GB
HDD:       SCSI, IDE
OS:        NT4, Win2K, WinXP, Win2K3
IE:        4.0, 5.0, 5.5, 6.0
APP:       SQLServer, Exchange, Office
 
{ PLATFORM, CPUS, RAM, HDD } @ 3
{ OS, IE } @ 2
```


- You can define as many sub-models as you want; any parameter can belong to any number of sub-models. Model hierarchy can be just one level deep.
- The combinatory order of a sub-model cannot exceed the number of its parameters. In the example above, an order of the first sub-model can be any value between one and four.
- If you do not specify the order for a sub-model, PICT uses the default order or the order specified by /o option.

# More Options 

- Constrant


Constraints allow you to specify limitations on the domain. 

```
IF [File system] = "FAT"   THEN [Size] <= 4096;
IF [File system] = "FAT32" THEN [Size] <= 32000;
```

- Conditional Constraints 

A term [parameter] relation value is an atomic part of a predicate. The following relations can be used: =, <>, >, >=, <, <=, and LIKE. LIKE is a wildcard-matching operator (* - any character, ? – one character).
 
```
[Size] < 10000
[Compression] = "OFF"
[File system] like "FAT*"

IF [Cluster size] in {512, 1024, 2048} THEN [Compression] = "Off";
IF [File system] in {"FAT", "FAT32"}   THEN [Compression] = "Off";

IF [File system] <> "NTFS" OR
 ( [File system] =  "NTFS" AND [Cluster size] > 4096 )
THEN [Compression] = "Off";
 
IF NOT ( [File system] = "NTFS" OR
       ( [File system] = "NTFS" AND NOT [Cluster size] <= 4096 ))
THEN [Compression] = "Off";
```

Parameters can be compared to other parameters, as in this example:

```
#
# Machine 1
#
OS_1:   Win2000, WinXP
SKU_1:  Professional, Server, Datacenter, WinPowered
LANG_1: EN, DE
 
#
# Machine 2
#
OS_2:   Win2000, WinXP
SKU_2:  Professional, Server, Datecenter
LANG_2: EN, DE
 
IF [LANG_1] = [LANG_2]
THEN [OS_1] <> [OS_2] AND [SKU_1] <> [SKU_2];
```