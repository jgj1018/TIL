[ref1](https://kotlinlang.org/docs/reference/collections.html)
[ref2](https://dzone.com/articles/kotlin-collections)
[ref3](https://medium.com/@napperley/kotlin-tutorial-5-basic-collections-3f114996692b)

# Collections: List, Set, Map

- Kotlin distinguishes between mutable and immutable collections (lists, sets, maps, etc).

- Immutability is favoured because it ensures that a program is less error prone due to its state remaining consistent, which leads to more predicable behaviour and easier software testing.

```
// Create a mutable list (MutableList).
val fruit = mutableListOf("Banana", "Kiwifruit", "Mango", "Apple")
// Add a element to the list.
fruit.add("Pear")
fruit
// Change an element in the list.
fruit[1] = "Orange"
fruit
// Remove a existing element from the list.
fruit.removeAt(2)
fruit

// Create a immutable list (List).
val fruit = listOf("Banana", "Kiwifruit", "Mango", "Apple")
```

The Kotlin List<out T> type is an interface that provides read-only operations like size, get and so on.
We can see basic usage of the list and set types below:

```
val numbers: MutableList<Int> = mutableListOf(1, 2, 3)
val readOnlyView: List<Int> = numbers
println(numbers)        // prints "[1, 2, 3]"
numbers.add(4)
println(readOnlyView)   // prints "[1, 2, 3, 4]"
readOnlyView.clear()    // -> does not compile

val strings = hashSetOf("a", "b", "c", "c")
assert(strings.size == 3)
```

Kotlin does not have dedicated syntax constructs for creating lists or sets. Use methods from the standard library, such as listOf(), mutableListOf(), setOf(), mutableSetOf().

Note that the readOnlyView variable points to the same list and changes as the underlying list changes. If the only references that exist to a list are of the read-only variety, we can consider the collection fully immutable. A simple way to create such a collection is like this:

```
val items = listOf(1, 2, 3)
```

Currently, the listOf method is implemented using an array list, but in future more memory-efficient fully immutable collection types could be returned that exploit the fact that they know they can't change.

Note that the read-only types are covariant. That means, I can take a List<Rectangle> and assign it to List<Shape> assuming Rectangle inherits from Shape. This wouldn't be allowed with the mutable collection types because it would allow for failures at runtime.