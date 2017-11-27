[reference1](http://www.amibugshare.com/pict/help.html)

# Pairwise and Higher-Order Generation

By default, PICT generates a pairwise, or order two, suite of test cases–all pairs covered. You can set the order to a value larger than two using the option /o:. For example, if you specify /o:3, the resultant test cases will cover all triplets of values,  producing a larger number of tests than the pairwise option, but potentially giving the test suite more coverage. The maximum order for a simple model is equal to the number of parameters, which will result in an exhaustive, all possible combinations, test suite. Following the same principle, specifying /o:1 will produce a test suite that covers all values only once (combinations of 1).

# Negative Testing

In addition to testing valid combinations, referred to as “positive testing,” you usually need to test using values outside the allowable range to make sure the program handles errors properly. Each “negative testing” test case should have only one invalid value because most applications take some failure action when they detect the first error. For this reason, a problem known as input masking can occur with negative testing. one invalid input prevents another invalid input from being tested.
 
Consider the following function which takes two arguments:

```
float SumSquareRoots( float a, float b )
{
      if ( a < 0 ) throw error;           // [1]
      if ( b < 0 ) throw error;           // [2]
     
      return ( sqrt( a ) + sqrt( b ));
};
```

Although the function can be called with any values for numbers a and b, it only makes sense to do the calculation on non-negative numbers. For that reason the function performs verifications [1] and [2] on the arguments. Now, assume a test ( a= -1, b = -1 ) was used to test a negative case. Here, a = -1 actually masks b = -1 because check [2] never gets executed and the failure if check [2] didn’t exist would go untested.
 
To prevent input masking, it is important that two invalid values (of two different parameters) are not used in the same test case. Prefixing any value with “~” (tilde) marks it invalid. Option /n: allows you to specify a different prefix.

Trivial model for SumSquareRoots
```
A: ~-1, 0, 1, 2
B: ~-1, 0, 1, 2
```

In this example, PICT guarantees that all possible pairs of valid values will be covered and all possible combinations of any invalid value will be paired with all positive values at least once.

```
A       B
2       0
2       2
0       0
0       1
1       0
2       1
0       2
1       2
1       1
~-1     2
1       ~-1
0       ~-1
~-1     1
2       ~-1
~-1     0
```

- PICT does not include the prefix as part of a value during comparisons. In constraints, use the value without the prefix. A valid constraint (although artificial in this example) would be: if [A] = -1 then [B] = 0. Also the prefix does not affect the type of a value. For example, both parameters in the above example are numeric despite having the non-numeric char  “~” in some of the values. The prefix will appear in the output.
- If a value has multiple names, prefixing only the first name will make the value negative.


# Weighting

Using weights, you can force PICT to prefer certain values. A weight can be any positive integer. PICT uses weight “1” if you don’t specify a different weight explicitly:

Let’s focus on primary partitions formatted with NTFS
```
Type:           Primary (10), Logical, Single, Span, Stripe, Mirror, RAID-5
Format method:  quick, slow
File system:    FAT, FAT32, NTFS (10)
```

Important note: Weight values have no absolute meaning. For example, when a parameter is defined like this:

```
File system:    FAT, FAT32, NTFS (10)
```

This does not mean that NTFS will appear in the output ten times more often than FAT or FAT32. Moreover, you cannot be sure that the weights you specified will be honored at all because PICT must handle two potentially contradictory requirements:
- To cover all combinations in the smallest number of test cases.
- To choose values according to their weights.
 
(1) will always take precedence over (2) and weights will only be honored when the choice of a value is not determined by a need to satisfy (1). More specifically, during the test case creation, PICT evaluates candidate values and it always chooses one that covers most of the still unused combinations. Sometimes there is a tie among candidate values and no one choice is better than any other. In those cases, PICT uses weights to make the final choice. You can use weights to attempt to shift the bias towards some values, but PICT decides whether or not to honor that request, and to what extent, using several factors, not just the weights alone.