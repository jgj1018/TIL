[reference1](https://kotlinlang.org/docs/reference/classes.html)
[reference2](https://kotlinlang.org/docs/reference/object-declarations.html)

# Open vs Abstract and Interface


- When I make a class without either of the two keywords, I can't inherit from it at all.

- open keyword allows me to create child classes of this parent class. I can also still just create objects from this normal(open) class. on the other hands, abstract classes can't be instantiated to any objects.

- open keyword allows inheritance of classes, whereas the abstract keyword bisically requires it. without child classes, there is no use for an abstract parent class. it goes sames on properties like method.

```
abstract fun practice() // have to be overrided.
open fun practices() // allowed to be overrided. 
```

# Object and Companion

Kotlin doesn't have static methods. If I declare a companion object inside a class, I can call its members with the same syntax as calling static methods in Java, using only the class name as a qualifier.

```
class MyClass {
	companion object Factory {
		fun create(): Myclass = Myclass()
	}
}

val instance = Myclass.create()
```

The name of the companion object can be omitted, in which case the name Companion will be used.

```
class MyClass {
	companion object {
	}
}

val x = MyClass.Companion
```

