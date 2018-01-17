[reference1](https://www.tutorialspoint.com/design_pattern/factory_pattern.htm)

[reference2](https://alvinalexander.com/java/java-factory-pattern-example)

[reference3](https://www.sitepoint.com/understanding-the-factory-method-design-pattern/)

# Factory Pattern


- When I use it?

(1) A class can't anticipate the type of objects it needs to create beforehand.

 When I gave a set of component classes but won't know exactly which one I will need to instantiate until runtime, Factory pattern can be used to create different objects, without knowing beforehand what sort of objects it needs to create or how the object is created.

(2) A class requires its subclasses to specify the objects it creates.

(3) I want to localize the logic to instantiate a complex object.

- Factory parttern ?
 
We create object without exposing the creation logic to the client and refer to newly created object using a common interface. Super class in factory design pattern can be an interface, abstract class or a normal class.

- Example (1)

(1)-1 Factory Method

```
<?php
class ProductFactory
{
    public static function build($type) {
        // assumes the use of an autoloader
        $product = "Product_" . $type;
        if (class_exists($product)) {
            return new $product();
        }
        else {
            throw new Exception("Invalid product type given.");
        }
    } 
}
```

(1)-2 Use case

```
<?php
// build a new Product_Computer type
$myComputer = ProductFactory::build("Computer");
// build a new Product_Tablet type
$myTablet = ProductFactory::build("Tablet");
```


- Example (2) 

(2)-1 interface

```
public interface Shape {
   void draw();
}
```

(2)-2 concreate class 1

```
public class Rectangle implements Shape {

   @Override
   public void draw() {
      System.out.println("Inside Rectangle::draw() method.");
   }
}
```

(2)-3 concreate class 2

```
public class Square implements Shape {

   @Override
   public void draw() {
      System.out.println("Inside Square::draw() method.");
   }
}
```

(2)-4 Factory method class

```
public class ShapeFactory {
	
   //use getShape method to get object of type shape 
   public Shape getShape(String shapeType){
      if(shapeType == null){
         return null;
      }		

      if(shapeType.equalsIgnoreCase("RECTANGLE")){
         return new Rectangle();
         
      } else if(shapeType.equalsIgnoreCase("SQUARE")){
         return new Square();
      }
      
      return null;
   }
}
```