# Chapter 1

* To express a tuple of length one as a literal, a comma must be placed after the element, but within the parentheses. For example, (17,) is a one-element tuple. The reason for this requirement is that, without the trailing comma, the expression (17) is viewed as a simple parenthesized numeric expression.


* Python carefully extends the semantics of `//` and `%` to cases where one or both operands are negative. For the sake of notation, let us assume that variables n and m represent respectively the dividend and divisor of a quotient n/m, and that `q = n // m` and `r = n % m`. Python guarantees that `q * m + r` will equal n. (...) Python further guarantees that 0 <= r < m. As a consequence, we find that `-27 // 4` evaluates to -7 and `-27 % 4` evaluates to 1, as `(-7)*4 +1 = -27`. When the divisor is negative, Python guarantees that m < r <= 0. As an example, `27 // -4 is -7` and `27 % -4` is -1, satisfying the identity `27 = (-7) * (-4) + (-1)`


* Python also supports the use of negative indices, which denote a distance from the end of the sequence; index -1 denotes the last element. index =2 the second to last.


* This example demonstrates the subtle difference between the list semantics for the syntax beta += foo versus beta = beta + foo.

```Python
alpha = [1, 2, 3]
beta = alpha                       # an alias for alpha
beta += [4, 5]                     # extends the original list with two more elements
beta = beta + [6, 7]               # reassigns beta to a new list [1, 2, 3, 4, 5, 6, 7]
print(alpha)                       # will be [1, 2, 3, 4, 5]
```

*  handling the exceptional case requires slightly more time when using a try-except structure than with a standard conditional statement. For this reason, the try-except clause is best used when there is reason to believe that the exceptional case is relatively unlikely, or when it is prohibitively expensive to proactively evaluate a condition to avoid the exception.



* An iterator is an object that manages an iteration through a series of values. If variable, i, identifies an iterator object, then each call to the built-in function, next(i), produces a subsequent element from the underlying series, with a StopIteration exception raised to indicate that there are no further elements.


* An iterable is an object, obj, that produces an iterator via the syntax iter(obj).


* the built-in function, divmod(a, b), returns the pair of values (a // b, a % b) associated with an integer division. Although the caller can consider the return value to be a single tuple, it is possible to write.

```Python
quotient, remainder = divmod(a, b)
```

* When using a simultaneous assignment, all of the expressions are evaluated on the right-hand side before any of the assignments are made to the left-hand variables. This is significant, as it provides a convenient means for swapping the values associated with two variables. With this command, j will be assigned to the old value of k, and k will be assigned to the old value of j. 

```Python
j, k = k, j
```

* fibonacci example

```Python
def fibonacci():
 a, b = 0, 1
 while True:
  yield a
  a, b = b, a+b
```

* first-class objects are instances of a type that can be assigned to an identifier, passed as a parameter, or returned by a function. In Python, functions and classes are also treated as first-class objects. 


```Python
scream = print  # assign name ‘scream’ to the function denoted as ‘print’
scream(‘Hello’) # call that function
```
