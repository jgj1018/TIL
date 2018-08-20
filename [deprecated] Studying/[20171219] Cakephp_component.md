[ref1](https://book.cakephp.org/3.0/en/controllers/components.html)

Components are packages of logic that are shared between controllers. I should consider creating your own component to contain the functionality. Creating components keeps controller code clean and allows you to reuse code between different controllers.

Like helpers, components implement a config() method that is used to get and set any configuration data for a component:

```
// Read config data.
$this->Auth->config('loginAction');

// Set config
$this->Csrf->config('cookieName', 'token');
```

As with helpers, components will automatically merge their $_defaultConfig property with constructor configuration to create the $_config property which is accessible with config().

# Loading Components on the Fly

I might not need all of your components available on every controller action. In situations like this you can load a component at runtime using the loadComponent() method in your controller:

```
// In a controller action
$this->loadComponent('OneTimer');
$time = $this->OneTimer->getTime();
```

`Keep in mind that components loaded on the fly will not have missed callbacks called. If you rely on the beforeFilter or startup callbacks being called, you may need to call them manually depending on when you load your component.`

# Creating a Component 

```
namespace App\Controller\Component;

use Cake\Controller\Component;

class MathComponent extends Component
{
    public function doComplexOperation($amount1, $amount2)
    {
        return $amount1 + $amount2;
    }
}
```

When including Components in a Controller you can also declare a set of parameters that will be passed on to the Component’s constructor. These parameters can then be handled by the Component:

```
// In your controller.
public function initialize()
{
    parent::initialize();
    $this->loadComponent('Math', [
        'precision' => 2,
        'randomGenerator' => 'srand'
    ]);
    $this->loadComponent('Csrf');
}

```

The above would pass the array containing precision and randomGenerator to MathComponent::initialize() in the $config parameter.

# Accessing a Component’s Controller

From within a Component you can access the current controller through the registry:

```
$controller = $this->_registry->getController();
```

You can access the controller in any callback method from the event object:

```
$controller = $event->getSubject();
```

# Component Callbacks

Components also offer a few request life-cycle callbacks that allow them to augment the request cycle.

- beforeFilter(Event $event) : Is called before the controller’s beforeFilter method, but after the controller’s initialize() method.
- startup(Event $event) : Is called after the controller’s beforeFilter method but before the controller executes the current action handler.
- beforeRender(Event $event) : Is called after the controller executes the requested action’s logic, but before the controller renders views and layout.
- shutdown(Event $event) : Is called before output is sent to the browser.
- beforeRedirect(Event $event, $url, Response $response) : Is invoked when the controller’s redirect method is called but before any further action. If this method returns false the controller will not continue on to redirect the request. The $url, and $response parameters allow you to inspect and modify the location or any other headers in the response.