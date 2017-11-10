[reference1](https://getcomposer.org/doc/01-basic-usage.md)
[reference2](http://phpenthusiast.com/blog/how-to-autoload-with-composer)
[reference3](https://stackoverflow.com/questions/12818690/using-composers-autoload)

For libraries that specify autoload information, Composer generates a vendor/autoload.php file. You can simply include this file and start using the classes that those libraries provide without any extra work:

Autoloading allows us to use PHP classes without the need to require() or include() them and is considered a hallmark of modern-day programming.

(1) Put the classes that we want to autoload in a dedicated directory.

(2)  Give the classes a namespace. We must give all the classes in the src/ directory the same namespace. 

example)

```
<?php
namespace Acme;

class Page {
    public function __construct()
    {
        echo "hello, i am a page.";
    }
}
```

(3) Point the namespace to the src/ directory in the composer.json file. I can even add your own code to the autoloader by adding an autoload field to composer.json.  We point the directory that holds the classes to the namespace in the composer.json file. For example, this is how we specify in the composer.json file that we gave the namespace Acme to the classes in the src/ directory:

```
{
  "autoload": {
    "psr-4": {
      "Acme\\":"src/"
    }
  }
}
```

(4) Update the Composer autoloader:

```
composer dumpautoload -o
```

(5) Import the namespace to your scripts.

```
<?php 
require "vendor/autoload.php";

use Acme\Db;
use Acme\User;
use Acme\Page;
 
$page1 = new Page();
```