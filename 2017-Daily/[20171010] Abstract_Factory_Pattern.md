


[references 1]()



# Abstract Factory - a creational pattern.

[references 1](https://dzone.com/articles/design-patterns-abstract-factory)
: Provides an interface for creating families of related or dependent objects without specifying their concreate classes.

One of the main benefits of this pattern is that the client is totally decoupled from the concreate products. The pattern is best utilised when my system has to create multiple families of products or I want to provide a library of products without exposing the implementation details.


[references 2](https://stackoverflow.com/questions/5739611/differences-between-abstract-factory-pattern-and-factory-method)
- Difference between factory method and abstract factory

: Fatory method is a single method, and an abstract factory is an object. factory method is just a method, it can be overridden in a subclass, hence the only thing that could change the return value would be a subclass. On the other hand, Abstract factory is an object that has multiple factory methods on it. It is saying that there is an object A, who wants to make a Foo object. Instead of making the Foo object itself(with a factory method), it's going to get a different object(the abstract factory) to create the Foo object.


[references 3](http://www.oodesign.com/abstract-factory-pattern.html)

[[http://www.oodesign.com/images/creational/abstract-factory-pattern.png]]
```
abstract class AbstractProductA{
	public abstract void operationA1();
	public abstract void operationA2();
}

class ProductA1 extends AbstractProductA{
	ProductA1(String arg){
		System.out.println("Hello "+arg);
	} // Implement the code here
	public void operationA1() { };
	public void operationA2() { };
}

class ProductA2 extends AbstractProductA{
	ProductA2(String arg){
		System.out.println("Hello "+arg);
	} // Implement the code here
	public void operationA1() { };
	public void operationA2() { };
}

abstract class AbstractProductB{
	//public abstract void operationB1();
	//public abstract void operationB2();
}

class ProductB1 extends AbstractProductB{
	ProductB1(String arg){
		System.out.println("Hello "+arg);
	} // Implement the code here
}

class ProductB2 extends AbstractProductB{
	ProductB2(String arg){
		System.out.println("Hello "+arg);
	} // Implement the code here
}

abstract class AbstractFactory{
	abstract AbstractProductA createProductA();
	abstract AbstractProductB createProductB();
}

class ConcreteFactory1 extends AbstractFactory{
	AbstractProductA createProductA(){
		return new ProductA1("ProductA1");
	}
	AbstractProductB createProductB(){
		return new ProductB1("ProductB1");
	}
}

class ConcreteFactory2 extends AbstractFactory{
	AbstractProductA createProductA(){
		return new ProductA2("ProductA2");
	}
	AbstractProductB createProductB(){
		return new ProductB2("ProductB2");
	}
}

//Factory creator - an indirect way of instantiating the factories
class FactoryMaker{
	private static AbstractFactory pf=null;
	static AbstractFactory getFactory(String choice){
		if(choice.equals("a")){
			pf=new ConcreteFactory1();
		}else if(choice.equals("b")){
				pf=new ConcreteFactory2();
			} return pf;
	}
}

// Client
public class Client{
	public static void main(String args[]){
		AbstractFactory pf=FactoryMaker.getFactory("a");
		AbstractProductA product=pf.createProductA();
		//more function calls on product
	}
}
```