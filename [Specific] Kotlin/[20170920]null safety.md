
#Null Safety

Kotlin's type system is aimed to eliminate NullPointerException's from our code. By default, Kotlin assumes that value can't be null.

```
var a: String = "value"
a = null // compilation error
```

When we want to nullable reference, we need to put a question mark to the type definition.

```
var b: String? = "value"
b = null 
```

but, b is not safe variable. so the compiler reports an error

```
var l = b.length // error: variable 'b' can be null
```

- Soultions

(1) Checking for null in condtions

```
val l = if (b != null) b.length else -1
```

(2) Safe calls

```
b?.length
```
This returns b.length if b is not null, and null otherwise. Safe calls are useful in chains.

(3) The !! Operator

```
val l = b!!.length
```
This will return a non-null value of b( String in our example ) or throw an NPE if b is null. 



[reference](https://kotlinlang.org/docs/reference/null-safety.html)