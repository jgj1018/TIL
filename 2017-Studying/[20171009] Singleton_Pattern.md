[reference1](https://blog.seotory.com/post/2016/03/java-singleton-pattern)
[reference2](https://www.tutorialspoint.com/design_pattern/singleton_pattern.htm)

# Singleton

The pattern involves a single class which is responsible to create an object while making sure that only single object gets created. This class provides a way to access its only object which can be accessed directly without need to instantiate the object of the class.


```
public class SingleObject {
	//create an object of SingleObject
	private static SingleObject instance = new SingleObject();
	
	//make the constructor private so that this class can't be instantiated.
	private SingleObject(){}
	
	//get the only object available.
	public static SingleObject getInstance(){
		return instance.
	}
}
```


by using static block, I can set the exception function. but this still has a problem that an instance is made when loading the class. it means it can use useless memory if the resource is big. 

```
//in the class
static {
	try {
		instance = new StaticBlockSingleTon();
	} catch (Exception e) {
		throw new RuntimeException("~~")
	}
}

```

To solve this problem with thread safe.

```
//in the class
public static synchronized ThreadSafeSingleTon getInstance() {
	if (instance == null)
		instance = new ThreadSafeSingleTon();
	return instance;
}

```


*initialization on demand holder idion
```
public class InitializationOnDemandHolderIdiom {
	
	private InitializationOnDemandHolderIdiom () {}
	private static class Singleton {
		private static final InitializationOnDemandHolderIdiom instance = new InitializationOnDemandHolderIdiom();
	}
	
	public static InitializationOnDemandHolderIdiom getInstance () {
		System.out.println("create instance");
		return Singleton.instance;
	}
}
```
