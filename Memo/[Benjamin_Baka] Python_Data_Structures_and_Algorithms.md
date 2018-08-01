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