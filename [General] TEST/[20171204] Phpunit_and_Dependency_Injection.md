[ref1](https://jtreminio.com/2013/03/unit-testing-tutorial-part-4-mock-objects-stub-methods-dependency-injection/)
[ref2](http://fabien.potencier.org/what-is-dependency-injection.html)

# Why DI(Dependency Injection) is needed for Mock

- "Dependency Injection is where components are given their dependencies through their constructors, methods, or directly into fields."

Consider there is a class Payment.

```
<?php

namespace phpUnitTutorial;

class Payment
{
    const API_ID = 123456;
    const TRANS_KEY = 'TRANSACTION KEY';

    public function processPayment(array $paymentDetails)
    {
        $transaction = new \AuthorizeNetAIM(self::API_ID, self::TRANS_KEY);
        $transaction->amount = $paymentDetails['amount'];
        $transaction->card_num = $paymentDetails['card_num'];
        $transaction->exp_date = $paymentDetails['exp_date'];

        $response = $transaction->authorizeAndCapture();

        if ($response->approved) {
            return $this->savePayment($response->transaction_id);
        } else {
            throw new \Exception($response->error_message);
        }
    }

    public function savePayment($transactionId)
    {
        // Logic for saving transaction ID to database or anywhere else would go in here
        return true;
    }
}
```

The two most obvious outcomes are:

- $response->approved is true, which triggers the call to ::savePayment() which returns true, and
- $response->approved is false, which then throws \Exception().

Now that we have the required parameter and its keys set up, instantiate the object, pass in the array and set our expected result - a return value of true:

```
<?php

namespace phpUnitTutorial\Test;

use phpUnitTutorial\Payment;

class PaymentTest extends \PHPUnit_Framework_TestCase
{
    public function testProcessPaymentReturnsTrueOnSuccessfulPayment()
    {
        $paymentDetails = array(
            'amount'   => 123.99,
            'card_num' => '4111-1111-1111-1111',
            'exp_date' => '03/2013',
        );

        $payment = new Payment();
        $result = $payment->processPayment($paymentDetails);

        $this->assertTrue($result);
    }
}
```

But failed.

we should get valid Authorize.net credentials and plug them in to our test! While that would certainly solve the issue, another quickly takes its place:

If I dive into the \AuthorizeNetAIM class, I will notice the complexity quickly grows - the methods call other methods, which call even more. Eventually there is even a cURL call that is what actually contacts Authorize.net's servers.

What happens if the Authorize.net servers are unavailable when I are writing and/or running my tests?

- Use Mock

There is still a minor issue, however: how do we actually get out mocked object into the code we are testing? The code that instantiates the Authorize.net object is pretty concrete and leaves no room for interpretation, right?

- DEPENDING ON DEPENDENCY INJECTION

Instead of using the new keyword in my methods, pass in the object in parameters.

```
public function processPayment(\AuthorizeNetAIM $transaction, array $paymentDetails)
{
    $transaction->amount = $paymentDetails['amount'];
    $transaction->card_num = $paymentDetails['card_num'];
    $transaction->exp_date = $paymentDetails['exp_date'];

    $response = $transaction->authorizeAndCapture();

    if ($response->approved) {
        return $this->savePayment($response->transaction_id);
    }

    throw new \Exception($response->error_message);
}
```

I'm moving the responsibility of object creation out of the Payment class and into whatever class calls it. If you want more information on dependency injection

- Why dependency Injection?

We want to replace a dependency in your code with a fake (mock) object. How exactly do you do that if your code is very explicit on the object it is creating?

I can't!


Dependency Injection is not restricted to constructor injection:

- Constructor Injection:
```
    class User
    {
      function __construct($storage)
      {
        $this->storage = $storage;
      }

      // ...
    }

```

- Setter Injection:
```
    class User
    {
      function setSessionStorage($storage)
      {
        $this->storage = $storage;
      }

      // ...
    }
```

- Property Injection:
```
    class User
    {
      public $sessionStorage;
    }

    $user->sessionStorage = $storage;
```

As a rule of thumb, constructor injection is best for required dependencies, like in our example, and setter injection is best for optional dependencies, like a cache object for instance.