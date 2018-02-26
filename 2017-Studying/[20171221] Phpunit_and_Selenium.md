[ref1](https://phpunit.de/manual/3.7/en/selenium.html)
[ref2](https://github.com/facebook/php-webdriver)
[ref3](https://github.com/lmc-eu/steward)

Php-webdriver library is PHP language binding for Selenium WebDriver, which allows I to control web browsers from PHP. This library is compatible with Selenium server version 2.x and 3.x.

# php-webdriver Install

```
php composer.phar require facebook/webdriver
```

# php-webdriver Getting started

when I create a session, be sure to pass the url to where my server is running.

```
// This would be the url of the host running the server-standalone.jar
$host = 'http://localhost:4444/wd/hub'; // this is the default
```

Make sure to have latest Firefox and Geckodriver or Chrome and Chromdriver installed.

```
$driver = RemoteWebDriver::create($host, DesiredCapabilities::firefox());
$driver = RemoteWebDriver::create($host, DesiredCapabilities::chrome());
```


# lmc-eu/steward install

```
$ composer require lmc/steward
```

# lmc-eu/steward get started

To provide I the Steward functionality, my tests have to extend the Lmc\Steward\Test\AbstractTestCase class.

I must also configure PSR-4 autoloading so that my tests could be found by Steward. For the following example it is as easy as adding following to my composer.json:

```
   "autoload": {
        "psr-4": {
            "My\\": "tests/"
        }
    }
```

Don't forget to create the selenium-tests/tests/ directory and to run composer dump-autoload afterward.

Now the test itself (place it to selenium-tests/tests/ directory):

```
<?php
// selenium-tests/tests/TitlePageTest.php

namespace My; // Note the "My" namespace maps to the "tests" folder, as defined in the autoload part of `composer.json`.

use Facebook\WebDriver\WebDriverBy;
use Lmc\Steward\Test\AbstractTestCase;

class TitlePageTest extends AbstractTestCase
{
    public function testShouldContainSearchInput()
    {
        // Load the URL (will wait until page is loaded)
        $this->wd->get('http://www.w3.org/'); // $this->wd holds instance of \RemoteWebDriver

        // Do some assertion
        $this->assertContains('W3C', $this->wd->getTitle());

        // I can use $this->log(), $this->warn() or $this->debug() with sprintf-like syntax
        $this->log('Current page "%s" has title "%s"', $this->wd->getCurrentURL(), $this->wd->getTitle());

        // Make sure search input is present
        $searchInput = $this->wd->findElement(WebDriverBy::cssSelector('#search-form input'));
        // Or I can use syntax sugar provided by Steward (this is equivalent of previous line)
        $searchInput = $this->findByCss('#search-form input');

        // Assert title of the search input
        $this->assertEquals('Search', $searchInput->getAttribute('title'));
    }
}
```

Now I need to start Selenium server, which will listen and execute commands sent from my tests.

```
$ java -jar ./vendor/bin/selenium-server-standalone-3.4.0.jar # the version may differ
```

Having my Selenium server listening, let's launch my test! Use the run command:

```
./vendor/bin/steward run staging firefox
```