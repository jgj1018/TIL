- [reference1](https://sourcemaking.com/design_patterns/flyweight)
- [reference2](https://www.journaldev.com/1562/flyweight-design-pattern-java)
- [reference3](https://refactoring.guru/design-patterns/flyweight)


Flyweight is a structural design pattern that lets me fit more objects into the available amount of RAM by sharing common parts of object state among multiple objects, instead of keeping it in each object.

Flyweight design pattern is used when I need to create a lot of Objects of a class. Since every object consumes memory space that can be crucial for low memory devices, such as mobile devices or embedded systems, flyweight design pattern can be applied to reduce the load on memory by sharing objects.

# Intrinsic and Extrinsic state 

To apply flyweight pattern, I need to divide Object property into intrinsic and extrinsic properties. Intrinsic properties make the Object unique whereas extrinsic properties are set by client code and used to perform different operations. the idea being that the memory it takes to store the extrinsic state need not be duplicated for every object.

```
public interface Flyweight<S> {
    public int operation(S extrinsicState);
}

public class ConcreteFlyweight implements Flyweight<Integer> {
    private Integer intrinsicState;

    public ConcreteFlyweight(Integer intrinsicState) {
        this.intrinsicState = intrinsicState;
    }

    public int operation(Integer extrinsicState) {
        return intrinsicState * extrinsicState;
    }
}

public class FlyweightFactory {
    private Map<Integer, ConcreteFlyweight> flyweights = new HashMap<Integer, ConcreteFlyweight>();

    public ConcreteFlyweight get(Integer key) {
        ConcreteFlyweight flyweight = flyweights.get(key);

        if (flyweight == null) {
            flyweight = new ConcreteFlyweight(key);
            flyweights.put(key, flyweight);
        }

        return flyweight;
    }
}
```
# another Example

![UML](https://refactoring.guru/images/patterns/diagrams/flyweight/example.png)

In this example, the Flyweight pattern helps to render a million trees on a canvas. Pattern extracts repeating intrinsic state from a main Tree class and puts it into a flyweight class TreeType. Now instead of storing the same data in multiple objects, it will be kept in several flyweight objects and linked to appropriate Tree objects. The client code works with trees through a flyweight factory, which encapsulates the logic of reusing existing tree types in new tree objects.
 
```
// The Flyweight class contains only a portion of state that describes a tree.
// These field store values that hardly unique for each particular tree. You
// won't find here tree coordinates, however textures and colors shared between
// multiple are here. And since this data is usually BIG, you'd waste a lot of
// memory by keeping it in each tree object. That's why we extract texture,
// colors and other data to a separate flyweight class that can be referenced
// from all those similar trees.
class TreeType is
    field name
    field color
    field texture
    constructor Tree(name, color, texture) { ... }
    method draw(canvas, x, y) is
        Create a bitmap from type, color and texture.
        Draw bitmap on canvas at X and Y.

// Flyweight factory decides whether to re-use existing flyweight or create a
// new object.
class TreeFactory is
    static field treeTypes: collection of tree types
    static method getTreeType(name, color, texture) is
        type = treeTypes.find(name, color, texture)
        if (type == null)
            type = new TreeType(name, color, texture)
            treeTypes.add(type)
        return type

// Context object contains extrinsic part of tree state. Application can create
// billions of these since they are pretty thin: just two integer coordinates
// and one reference.
class Tree is
    field x,y
    field type: TreeType
    constructor Tree(x, y, type) { ... }
    method draw(canvas) is
        type.draw(canvas, this.x, this.y)

// Tree and Forest classes are Flyweight's clients. You might merge them
// together if you don't plan to develop a Tree class any further.
class Forest is
    field trees: collection of Trees

    method plantTree(x, y, name, color, texture) is
        type = TreeFactory.getTreeType(name, color, texture)
        tree = new Tree(x, y, type);
        trees.add(tree)

    method draw(canvas) is
        foreach tree in trees
            tree.draw(canvas)
```

# Immutability

Since the same flyweight objects will be used in different contexts, I have to make sure that their state can not be modified. Flyweights should receive their intrinsic state only through constructor's parameters. They should not expose setters or public fields.

# etc

For applying flyweight pattern, we need to create a Flyweight factory that returns the shared objects.

- Whereas Flyweight shows how to make lots of little objects, Facade shows how to make a single object represent an entire subsystem.

- Flyweight explains when and how State objects can be shared.

- Flyweight looks almost like Singleton in cases where it's possible to reduce everything to just one flyweight object. But remember, there are two fundamental differences between these patterns:

(1) Singleton object can be mutable. Flyweight objects are immutable. 
(2) There should be only one Singleton instance, whereas Flyweight class can have multiple instances with a different intrinsic state. 
