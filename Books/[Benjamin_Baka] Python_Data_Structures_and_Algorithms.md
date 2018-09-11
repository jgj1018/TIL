#### variable scope 

* To resolve a namespace when a function is called, the Python interpreter first searches the local namespace (that is, the function itself) and if no match is found, it searches the global namespace. This global namespace is the module in which the function was defined. If the name is still not found, it searches the built-in namespace. Finally, if this fails then the interpreter raises a NameError exception

#### Overview of data types and objects

* Python contains 12 built-in data types. These include four numeric types (int, float, complex, bool), four sequence types (str, list, tuple, range), one mapping type (dict), and two set types.


* All data types in Python are objects. In fact, pretty much everything is an object in Python, including modules, classes, and functions, as well as literals such as strings and integers. Each object in Python has a `type`, a `value`, and an `identity`.


```python
    if a== b: ####a and b have the same value 
    if a is b: #### if a and b are the same object 
    if type(a) is type(b): #### a and b are the same type 
```

#### Strings

* Given that strings are immutable, a common question that arises is how we perform operations such inserting values. Rather than changing a string, we need to think of ways to build new string objects for the results we need. For example, if we wanted to insert a word into our greeting, we could assign a variable to the following:

```python
	greet[:5] + ' wonderful ' + greet[5:]
    'hello wonderful world'
```

#### Lists

* The following code prints out two lists representing the function composition of f1 and f2 calculated first using a for loop and then using a list comprehension. 

```python
def f1(x): return x*2
def f2(x): return x*4

lst = []
for i in range(16):
	lst.append(f1(f2(i)))
    
print(lst)

print([f1(x) for x in range(64) if x in [f2(j) for in range(16)]])

# first print output : [0,8,16,24,32,40,48,56,64,72,80,88,94,104,112,120]
# second print output : [0,8,16,24,32,40,48,56,64,72,80,88,94,104,112,120]
```


* List comprehensions can also be used to replicate the action of nested loops in a more compact form. For example, we multiply each of the elements contained within list1 with each other:

```python
list1 = [[1, 2, 3], [4, 5, 6]]
[i * j for i in list1[0] for j in list1[1]]

#### output : [4, 5, 6, 8, 10, 12, 12, 15, 18]
```

#### Functions as first class objects


* In Python, it is not only data types that are treated as objects. Both functions and classes are what are known as first class objects, allowing them to be manipulated in the same ways as built-in data types. By definition, first class objects are:

	- Created at runtime
	- Assigned as a variable or in a data structure
	- Passed as an argument to a function
	- Returned as the result of a function


- Functions can also be used as arguments for other functions. For example, we can define the following function:

```python
def greeting(language): 
if language== 'eng': 
         return 'hello world' 
   if language  == 'fr' 
         return 'Bonjour le monde' 
   else: return 'language not supported' 

def callf(f):
	lang='eng'
    return (f(lang))
    
callf(greeting)
# output : 'hello world'
```

#### Higher order functions

* Note that both map and filter perform the identical function as to what can be achieved by list comprehensions. There does not seem to be a great deal of difference in the performance characteristics apart from a slight performance advantage when using the in built functions map and filter without the lambda operator, compared to list comprehensions. Despite this, most style guides recommend the use of list comprehensions over built-in functions, possibly because they tend to be easier to read.


```python
words=str.split('The longest word in this sentence')
sorted(words, key=len)
#### ['in', 'The', 'word', 'this', 'longest', 'sentence']

sl = ['A', 'b', 'a', 'C', 'c']
sl.sort(key=str.lower)
# ['A', 'a', 'b', 'C', 'c']
sl.sort()
# ['A', 'C', 'a', 'b', 'c']
```


* Note the difference between the list.sort() method and the sorted built-in function. list.sort(), a method of the list object, sorts the existing instance of a list without copying it. This method changes the target object and returns None. It is an important convention in Python that functions or methods that change the object return None to make it clear that no new object was created and that the object itself was changed.On the other hand, the sorted built-in function returns a new list. It actually accepts any iterable object as an argument, but it will always return a list. Both list sort and sorted take two optional keyword arguments as key.


#### Recursive functions

* Technically, recursion is a special case of iteration known as tail iteration, and it is usually always possible to convert an iterative function to a recursive function and vice versa.

* In general, iteration is more efficient; however, recursive functions are often easier to understand and write. Recursive functions are also useful for manipulating recursive data structures such as linked lists and trees


#### Generators and co-routines


```python
def oddGen(n, m):
   	while n < m:
    	yield n
        n += 2
        
sum(oddGen(1,1000000)) 
```

* In the preceding example, the sum method loads each number into memory when it is needed for the calculation. This is achieved by the generator object repeatedly calling the __next__() special method. Generators never return a value other than None.


* We can also create a generator expression, which, apart from replacing square brackets with parentheses, uses the same syntax and carries out the same operation as list comprehensions. Generator expressions, however, do not create a list, they create a generator object. This object does not create the data, but rather creates that data on demand. This means that generator objects do not support sequence methods such as append() and insert(). You can, however, change a generator into a list using the list() function:


```python
lst1 = [1, 2, 3, 4]
gen1 = (10**i for i in lst1)
for x in gen1: print(x)
# 10
# 100
# 1000
# 10000
```

#### Special methods

* Apart from the following exception, special method, are generally called by the Python interpreter rather than the programmer; for example, when we use the + operator, we are actually invoking a call to __add__().


* It is strongly advised not to use the double underscore syntax for your own objects because of potential current or future conflicts with Python's own special methods.

#### Comparison and Arithmetic operators

* For collection objects, these operators compare the number of elements and the equivalence operator == b returns True if each collection object is structurally equivalent, and the value of each element is identical.
 
#### Representation error

```python
import fractions
fractions.Fraction(3,4)
# Fraction(3, 4)
fractions.Fraction(0.5)
# Fraction(1, 2)
fractions.Fraction(".25")
# Fraction(1, 4)
```

#### Sequences

* String, tuple, and range objects are immutable. (...) Note that for the immutable types, any operation will only return a value rather than actually change the value.



#### Tuples

* It is important to remember to use a trailing comma when creating a tuple with one element, for example:

```python
t = ('a',) 
```

* An important use of tuples is to allow us to assign more than one variable at a time by placing a tuple on the left-hand side of an assignment, for example:

```python
l=['one', 'two']
x, y = l
```

* We can actually use this multiple assignment to swap values in a tuple, for example:


```python
x,y = y,x
```

* A ValueError will be thrown if the number of values on each side of the assignment are not the same.

#### Dictionaries

* Dictionaries themselves are mutable; however, their index keys must be immutable.

* In contrast to the list object, when the in operator is applied to dictionaries, it uses a hashing algorithm and this has the effect of the increase in time for each lookup almost independent of the size of the dictionary. This makes dictionaries extremely useful as a way to work with large amounts of indexed data.

#### Sorting dictionaries

* The sorted() method has two optional arguments that are of interest: key and reverse. The key argument has nothing to do with the dictionary keys, but rather is a way of passing a function to the sort algorithm to determine the sort order. For example, in the following code, we use the __getitem__ special method to sort the dictionary keys according to the dictionary values:


```python
sorted(list(d))
# ['five', 'four', 'one', 'two', 'three', 'two']

sorted(list(d.values))
# [1, 2, 3, 4, 5, 6]

sorted(list(d), key = d.__getitem__)
# ['one', 'two', 'three', 'four', 'five', 'six']
```

* since dictionaries do not have a method to return a key by using its value, the equivalent of the list.index method for lists, using the optional key argument to do this is a little tricky. An alternative approach is to use a list comprehension, as the following example demonstrates:

```python
[value for (key, value) in sorted(d.items())]
#[5, 4, 1, 6, 3, 2]
```

* The sorted() method also has an optional reverse argument, and unsurprisingly, this does exactly what it says, reverses the order of the sorted list, for example:

```python
sorted(list(d), key=d.__getitem__, reverse=True)
['six', 'five', 'four', 'three', 'two', 'one']
```


* We can, of course, define our own custom method that we can use as the key argument to the sorted method. For example, here we define a function that simply returns the last letter of a string:

```python
d2 ={'one':'uno' , 'two':'deux', 'three':'trois', 'four': 'quatre', 'five': 'cinq', 'six':'six'}

def corder(string):
	return(string[len(string - 1])
    
sorted(d2.values(), key=corder)
#['quatre', 'uno', 'cinq', 'trois', 'deux', 'six']
```

#### Dictionaries for text analysis.

```python
filtered = {key:value for key, value in items if value < 20 and value > 15}
```

* Note the use of the dictionary comprehension used to construct the filtered dictionary.

#### Sets

```python
s1= {'ab', 3, 4, (5,6)}
s2= {'ab', 7, (7,6)}

s1 - s2 # same as s1.difference(s2)
# {(5, 6), 3, 4}

s1.intersection(s2)
# {'ab'}

s1.union(s2)
# {3, 4, 'ab', 7, (5,6), (7,6)}
```

* Notice that the set object does not care that its members are not all of the same type, as long as they are all immutable. If you try to use a mutable object such as a list or dictionaries in a set, you will receive an unhashable type error. Hashable types all have a hash value that does not change throughout the lifetime of the instance. All built-in immutable types are hashable. All built-in mutable types are not hashable, so they cannot be used as elements of sets or keys to dictionaries.


* Notice also in the preceding code that when we print out the union of s1 and s2, there is only one element with the value 'ab'. This is a natural property of sets in that they do not include duplicates.

#### Immutable sets

* since normal sets are mutable and therefore not hashable, they cannot be used as members of other sets. The frozenset, on the other hand, is immutable and therefore able to be used as a member of a set


#### Deques

* Double-ended queues, or deques (usually pronounced decks), are list-like objects that support thread-safe, memory-efficient appends. Deques are mutable and support some of the operations of lists, such as indexing. Deques can be assigned by index, for example, dq[1] = z; however, we cannot directly slice deques. For example, dq[1:2] results in a TypeError (we will look at a way to return a slice from a deque as a list shortly).


* The major advantage of deques over lists is that inserting items at the beginning of a deque is much faster than inserting items at the beginning of a list, although inserting items at the end of a deque is very slightly slower than the equivalent operation on a list.


* We can use the rotate(n) method to move and rotate all items of n steps to the right for positive values of the integer n, or left for negative values of n the left, using positive integers as the argument,

```python
from collections import deque
dq = deque('abcd')
#deque(['a', 'b', 'c', 'd'])
dq.rotate(2)
#deque(['c', 'd', 'a', 'b'])
dq.rotate(-2)
#deque(['a', 'b', 'c', 'd'])

```

* A useful feature of deques is that they support a maxlen optional parameter that restricts the size of the deque. This makes it ideally suited to a data structure known as a circular buffer. This is a fixed-size structure that is effectively connected end to end and they are typically used for buffering data streams. The following is a basic example:

```python
dq2 = deque([], maxlen=3)
for i in range(6):
	dq2.append(i)
    print(dq2)
    
#deque([0] , maxlen=3)
#deque([0, 1] , maxlen=3)
#deque([0, 1, 2] , maxlen=3)
#deque([1, 2, 3] , maxlen=3)
#deque([2, 3, 4] , maxlen=3)
#deque([3, 4, 5] , maxlen=3)
```

#### Counter objects

* Counter is a subclass of a dictionary where each dictionary key is a hashable object and the associated value is an integer count of that object

```python
from collections import Counter
ct = Counter()
ct.update('abcd')
# Counter({'a': 2, 'b': 1, 'c': 1})
ct.update({'a':3})
# Counter({'a': 5, 'b': 1, 'c': 1})
```

* The most notable difference between counter objects and dictionaries is that counter objects return a zero count for missing items rather than raising a key error


#### Ordered dictionaries

* The important thing about ordered dictionaries is that they remember the insertion order, so when we iterate over them, they return values in the order they were inserted. (...) with an OrderedDict, the insertion order is also considered An equality test between two OrderedDicts with the same keys and values but a different insertion order will return False:


#### defaultdict

* with an OrderedDict, the insertion order is also considered An equality test between two OrderedDicts with the same keys and values but a different insertion order will return False:


#### Arrays

* The array module defines a datatype array that is similar to the list datatype except for the constraint that their contents must be of a single type of the underlying representation, as is determined by the machine architecture or underlying C implementation.


* Using arrays, as opposed to lists, is a much more efficient way of storing data that is all of the same type. In the following example, we have created an integer array of the digits from 0 to 1 million minus 1, and an identical list. Storing 1 million integers in an integer array requires around 45% of the memory of an equivalent list:


```python
import array
ba = array.array('i', range(10**6))
bl = list(range(10**6))
import sys
100 * sys.getsizeof(ba) / sys.getsizeof(bl)
45.46534532014713
```

* It should be noted that when performing operations on arrays that create lists, such as list comprehensions, the memory efficiency gains of using an array in the first place will be negated. When we need to create a new data object, a solution is to use a generator expression to perform the operation.


#### Recursion and backtracking

* At the core of a recursive function are two types of cases: base cases, which tell the recursion when to terminate, and recursive cases that call the function they are in. A simple problem that naturally lends itself to a recursive solution is calculating factorials. The recursive factorial algorithm defines two cases: the base case when n is zero, and the recursive case when n is greater than zero. A typical implementation is the following:

```python
def factorial(n):
	f = 0
	if n==0:
    	return 1
        f= n*factorial(n-1)
    print(f)
    return(f)
    
factorial(4)
```

* This code prints out the digits 1, 2, 4, 24. To calculate 4 requires four recursive calls plus the initial parent call. On each recursion, a copy of the methods variables is stored in memory. Once the method returns it is removed from memory.


* Recursive calls are stored in memory, whereas iterations are not. This creates a trade off between processor cycles and memory usage, so choosing which one to use may depend on whether the task is processor or memory intensive.

Recursion|Iteration
---|---
Terminates when a base case is reached|Terminates when a defined condition is met
Each recursive call requires space in memory|Each iteration is not stored in memory
An infinite recursion results in a stack overflow error|An infinite iteration will run while the hardware is powered
Some problems are naturally better suited to recursive solutions|Iterative solutions may not always be obvious


#### Backtracking

* Backtracking is a form of recursion that is particularly useful for types of problems such as traversing tree structures, where we are presented with a number of options at each node, from which we must choose one. Subsequently we are presented with a different set of options, and depending on the series of choices made either a goal state or a dead end is reached. If it is the latter, we must backtrack to a previous node and traverse a different branch. Backtracking is a divide and conquer method for exhaustive search. Importantly backtracking prunes branches that cannot give a result.An example of back tracking is given in the following example. Here, we have used a recursive approach to generating all the possible permutations of a given string, s, of a given length n:

```
def bitStr(n,s):
	if n == 1: return s
    return [digit + bits for digit in bitStr(1,s) for bits in bitStr(n-1, s)]
```

#### Runtime analysis

* Worst case analysis. Make no assumptions on the input data.
* Ignore or suppress constant factors and lower order terms. At large inputs higher order terms dominate.
* Focus on problems with large input sizes.