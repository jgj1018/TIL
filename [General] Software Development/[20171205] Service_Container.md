[ref1](https://jtreminio.com/2012/10/an-introduction-to-pimple-and-service-containers/)

# An introduction to Pimple and Service Containers

A service container is basically an array (or object) that contains other objects and sets default behaviors.

Using Pimple you can define several hundreds of objects, and then easily instantiate them using the container object.

# Simple Container

just an array

```
$container = array();
$container['dateTime'] = new DateTime();

//access to this object
$date = $container['dateTime'];
```
define several more!

```
$container = array();
$container['dateTimeOne'] = new DateTime();
$container['dateTimeTwo'] = new DateTime();
$container['dateTimeThree'] = new DateTime();
```

By simple defining the keys you’re actually instantiating the objects and putting them in memory. what if I'm defining a key to hold a much larger class?

The solution is anonymous functions. Each container key should actually be an anonymous function, rather than instantiating an object directly.


```
$container = array();

$container['dateTimeOne'] = function() {
    return new DateTime();
};

$container['dateTimeTwo'] = function() {
    return new DateTime();
};

$container['dateTimeThree'] = function() {
    return new DateTime();
};

$date = $container['dateTimeOne'];
```

Looks like $date is just a Closure and not the DateTime object we were expecting! The answer to this issue is Pimple.

```
$container = new Pimple();

$container['dateTimeOne'] = function() {
    return new DateTime();
};

$container['dateTimeTwo'] = function() {
    return new DateTime();
};

$container['dateTimeThree'] = function() {
    return new DateTime();
};

``` 

I still have 5 closures, but can now instantiate an object on demand – just as if I was using the new keyword – and I no longer have 5 DateTime objects just sitting in memory

It’s basically just a wrapper around the new keyword? Well, not exactly. each container key is a full function in its own right, meaning that you can do much more than simply return new DateTime();. When access a database using PDO, you must first instantiate a PDO object. You can do all of the setup within the container:


```
$container = new Pimple();

$container['db'] = function() {
    $host = 'localhost';
    $dbName = 'wordpress';
    $user = 'root';
    $pass = '';

    return new \PDO("mysql:host={$host};dbname={$dbName}", $user, $pass);
};
```

All a service container boils down to is returning objects that have been instantiated and configured with pre-determined options.

