[ref](https://book.cakephp.org/3.0/en/views/helpers.html)

# Helpers

Helpers are the component-like classes for the presentation layer of my application. They contain presentational logic that is shared between many views, elements, or layouts. 

# Configuring Helpers

I load helpers in CakePHP by declaring them in a view class. An AppView class comes with every CakePHP application and is the ideal place to load helpers:

```
class AppView extends View
{
    public function initialize()
    {
        parent::initialize();
        $this->loadHelper('Html');
        $this->loadHelper('Form');
        $this->loadHelper('Flash');
    }
}
```

I can use the current action name to conditionally load helpers:

```
class AppView extends View
{
    public function initialize()
    {
        parent::initialize();
        if ($this->request->getParam('action') === 'index') {
            $this->loadHelper('ListPage');
        }
    }
}
```

I can also use my controller’s beforeRender method to load helpers:

```
class ArticlesController extends AppController
{
    public function beforeRender(Event $event)
    {
        parent::beforeRender($event);
        $this->viewBuilder()->helpers(['MyHelper']);
    }
}
```

# Using Helpers

Once I’ve configured which helpers I want to use in my controller, each helper is exposed as a public property in the view. For example, if I were using the HtmlHelper I would be able to access it by doing the following:

```
echo $this->Html->css('styles');
```

# Creating Helpers

- Helper class files should be put in src/View/Helper. For example: src/View/Helper/LinkHelper.php
- Helper classes should be suffixed with Helper. For example: LinkHelper.
- When referencing helper class names I should omit the Helper suffix. For example: $this->loadHelper('Link');.

# Including Other Helpers

I may wish to use some functionality already existing in another helper. To do so, I can specify helpers I wish to use with a $helpers array, formatted just as I would in a controller:

```
/* src/View/Helper/LinkHelper.php (using other helpers) */

namespace App\View\Helper;

use Cake\View\Helper;

class LinkHelper extends Helper
{
    public $helpers = ['Html'];

    public function makeEdit($title, $url)
    {
        // Use the HTML helper to output
        // Formatted data:

        $link = $this->Html->link($title, $url, ['class' => 'edit']);

        return '<div class="editOuter">' . $link . '</div>';
    }
}
```