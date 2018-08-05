# variable scope 

* To resolve a namespace when a function is called, the Python interpreter first searches the local namespace (that is, the function itself) and if no match is found, it searches the global namespace. This global namespace is the module in which the function was defined. If the name is still not found, it searches the built-in namespace. Finally, if this fails then the interpreter raises a NameError exception

# Overview of data types and objects

* Python contains 12 built-in data types. These include four numeric types (int, float, complex, bool), four sequence types (str, list, tuple, range), one mapping type (dict), and two set types.


* All data types in Python are objects. In fact, pretty much everything is an object in Python, including modules, classes, and functions, as well as literals such as strings and integers. Each object in Python has a `type`, a `value`, and an `identity`.


```python
    if a== b: #a and b have the same value 
    if a is b: # if a and b are the same object 
    if type(a) is type(b): # a and b are the same type 
```

# Strings

* Given that strings are immutable, a common question that arises is how we perform operations such inserting values. Rather than changing a string, we need to think of ways to build new string objects for the results we need. For example, if we wanted to insert a word into our greeting, we could assign a variable to the following:

```python
	greet[:5] + ' wonderful ' + greet[5:]
    'hello wonderful world'
```

# Lists

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

# output : [4, 5, 6, 8, 10, 12, 12, 15, 18]
```

# Functions as first class objects


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

# Higher order functions

* Note that both map and filter perform the identical function as to what can be achieved by list comprehensions. There does not seem to be a great deal of difference in the performance characteristics apart from a slight performance advantage when using the in built functions map and filter without the lambda operator, compared to list comprehensions. Despite this, most style guides recommend the use of list comprehensions over built-in functions, possibly because they tend to be easier to read.


```python
words=str.split('The longest word in this sentence')
sorted(words, key=len)
# ['in', 'The', 'word', 'this', 'longest', 'sentence']

sl = ['A', 'b', 'a', 'C', 'c']
sl.sort(key=str.lower)
# ['A', 'a', 'b', 'C', 'c']
sl.sort()
# ['A', 'C', 'a', 'b', 'c']
```


* Note the difference between the list.sort() method and the sorted built-in function. list.sort(), a method of the list object, sorts the existing instance of a list without copying it. This method changes the target object and returns None. It is an important convention in Python that functions or methods that change the object return None to make it clear that no new object was created and that the object itself was changed.On the other hand, the sorted built-in function returns a new list. It actually accepts any iterable object as an argument, but it will always return a list. Both list sort and sorted take two optional keyword arguments as key.


# Recursive functions

* Technically, recursion is a special case of iteration known as tail iteration, and it is usually always possible to convert an iterative function to a recursive function and vice versa.

* In general, iteration is more efficient; however, recursive functions are often easier to understand and write. Recursive functions are also useful for manipulating recursive data structures such as linked lists and trees
