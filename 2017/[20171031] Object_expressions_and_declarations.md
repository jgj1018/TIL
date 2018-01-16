# Object Expressions and Declarations

Object Expressions and Declarations are different each other. 

- Object expressions

Object expression is an object of a slight modification of some class, without explicitly declaring a new subclass of it. It is like a anonymous inner classes in Java.

```
fun foo() {
    val adHoc = object {
        var x: Int = 0
        var y: Int = 0
    }
    print(adHoc.x + adHoc.y)
}
```

One thing have to be noted that the anonymous objects can be used as types only in local and private decalarations. it can't be used as a return type of a public function or the type of a public property. It cause errors.

```
class C {
    // Private function, so the return type is the anonymous object type
    private fun foo() = object {
        val x: String = "x"
    }

    // Public function, so the return type is Any
    fun publicFoo() = object {
        val x: String = "x"
    }

    fun bar() {
        val x1 = foo().x        // Works
        val x2 = publicFoo().x  // ERROR: Unresolved reference 'x'
    }
}
```

- Object declarations

It is like static in Java. It always has a name following the object keyword. Just like a variable declaration. It can't be used on the right hands side of an assignment statement.

```
object DataProviderManager {
    fun registerDataProvider(provider: DataProvider) {
        // ...
    }

    val allDataProviders: Collection<DataProvider>
        get() = // ...
}
```

It can't be local(i.e. be nested directly inside a function) but they can be nested into other object declarations or non-inner classes.

- Companion objects 
: An object declaration inside a class can be marked with the companion keyword 

```
class MyClass {
    companion object Factory {
        fun create(): MyClass = MyClass()
    }
}
```

The name of the companion object can be omitted, in which case the name `Companion` will be used.

```
class MyClass {
    companion object {
    }
}

val x = MyClass.Companion
```