# Lambda return with label


To exit a lambda, use a `label`. A bare `return` is forbidden inside a lambda, because a lambda can not make the enclosing function return:
Such returns (located in a lambda, but exiting the enclosing function) are called `non-local returns`. 


```
fun hasZeros(ints: List<Int>): Boolean {
 ints.forEach {
  if (it == 0) return true
 }
 return false
}

```



```
fun foo() {
 ints.forEach lit@ {
  if (it == 0) return@lit
   print(it)
 }
}


```
it returns only from the lambda expression. Oftentimes it is more convenient to use implicits labels: such a label has the same name as the function to which the lambda is passed.

```
fun foo() {
 ints.forEach {
    if (it == 0) return@forEach
    print(it)
 }
}

```

Alternatively, I can replace the lambda expression with an anonymous function. A return statement in an anonymous function will return from the anonymous function itself.


- Label (2)
 
Any expression in Kotlin may be marked with a `label`. Labels have the form of an identifier followed by the @ sign. 

```
loop@ for (i in 1..100) {
 for (j in 1..100) {
   if (...) break@loop
 }
}

```

A break qualified with a label jumps to the execution point right after the loop marked with that label. A `continue` proceeds to the next iteration of that loop.




[reference 1](https://kotlinlang.org/docs/reference/returns.html)
[reference 2](https://kotlinlang.org/docs/reference/inline-functions.html)