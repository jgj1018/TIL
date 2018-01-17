[reference1](https://kotlinlang.org/docs/reference/java-interop.html) 
[reference2](https://discuss.kotlinlang.org/t/how-to-use-cloneable/2364/3) 
[reference3](https://docs.oracle.com/javase/6/docs/api/java/lang/Object.html#clone%28%29) 
[reference4](https://www.pixelstech.net/article/1420629927-What-does-super-clone%28%29-do) 
[reference5](https://stackoverflow.com/questions/7579913/how-to-clone-a-java-object-with-the-clone-method/7580966#7580966)  

Clone and Cloneable in Kotlin is based on Java. To override clone(), your class needs to extend kotlin.Cloneable.

and non-primitive built-in classes are also mapped. one of them is kotlin.Cloneable.

`java.lang.Cloneable (mapped) kotlin.Cloneable!`


If I try to call clone() on a class that does not implement Cloneable, a CloneNotSupportedException is thrown. The Cloneable interface is there to help us recognize which classes are really cloneable and which are not.

in Object.java about clone method.

```
protected native Object clone() throws CloneNotSupportedException
```

this method performs a "shallow copy" of this object, not a"deep copy" operation.

```
open class TempA : Cloneable {
    val string = "123"
    val integer= 123
    val double = 1.23

    override public fun clone(): Any {
        return super.clone()
    }
}
```

super.clone() checks if the actual class implements Cloneable, and creates an instance of that actual class. The clone() method of Object (which will eventually be called when all superclasses obey the contract) makes a shallow copy and takes care of the correct runtime type of the new object. Note how no constructor is called in the entire process.
