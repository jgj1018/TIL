[ref1](https://book.cakephp.org/3.0/en/core-libraries/app.html)

The App class is responsible for resource location and path management.

`Cake\Core\App::classname($name, $type = '', $suffix = '')`

This method is used to resolve classnames throughout CakePHP. It resolves the short form names CakePHP uses and returns the fully resolved classname:

```
// Resolve a short classname with the namespace + suffix.
App::classname('Auth', 'Controller/Component', 'Component');
// Returns Cake\Controller\Component\AuthComponent

// Resolve a plugin name.
App::classname('DebugKit.Toolbar', 'Controller/Component', 'Component');
// Returns DebugKit\Controller\Component\ToolbarComponent

// Names with \ in them will be returned unaltered.
App::classname('App\Cache\ComboCache');
// Returns App\Cache\ComboCache
```

# Finding Paths to Namespaces

`Cake\Core\App::path(string $package, string $plugin = null)`

Used to get locations for paths based on conventions:

```
// Get the path to Controller/ in my application
App::path('Controller');
```
This can be done for all namespaces that are part of my application. I can also fetch paths for a plugin:

```
// Returns the component paths in DebugKit
App::path('Component', 'DebugKit');
```

App::path() will only return the default path, and will not be able to provide any information about additional paths the autoloader is configured for.

`static Cake\Core\App::core(string $package)`

Used for finding the path to a package inside CakePHP:

```
// Get the path to Cache engines.
App::core('Cache/Engine');
```