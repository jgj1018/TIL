[ref1](https://phpunit.de/manual/current/en/test-doubles.html)

# Test Doubles

- The createMock($type) method immediately returns a test double object for the specified type (interface or class). The creation of this test double is performed using best practice defaults (the __construct() and __clone() methods of the original class are not executed) and the arguments passed to a method of the test double will not be cloned.

- By default, all methods of the original class are replaced with a dummy implementation that just returns null (without calling the original method). Using the will($this->returnValue()) method, for instance, you can configure these dummy implementations to return a value when called.

# Stubs

- The practice of replacing an object with a test double that (optionally) returns configured return values is referred to as stubbing. You can use a stub to "replace a real component on which the SUT depends so that the test has a control point for the indirect inputs of the SUT. This allows the test to force the SUT down paths it might not otherwise execute".

- Consider there is a class like below.
```
<?php
use PHPUnit\Framework\TestCase;

class SomeClass
{
    public function doSomething()
    {
        // Do something.
    }
}
?>
```

- Stubbing a method call to return a fixed value
```
<?php
use PHPUnit\Framework\TestCase;

class StubTest extends TestCase
{
    public function testStub()
    {
        // Create a stub for the SomeClass class.
        $stub = $this->createMock(SomeClass::class);

        // Configure the stub.
        $stub->method('doSomething')
             ->willReturn('foo');

        // Calling $stub->doSomething() will now return
        // 'foo'.
        $this->assertEquals('foo', $stub->doSomething());
    }
}
?>
```

- When the stubbed method call should return a calculated value instead of a fixed one (see returnValue()) or an (unchanged) argument (see returnArgument()), you can use returnCallback() to have the stubbed method return the result of a callback function or method

```
<?php
use PHPUnit\Framework\TestCase;

class StubTest extends TestCase
{
    public function testReturnCallbackStub()
    {
        // Create a stub for the SomeClass class.
        $stub = $this->createMock(SomeClass::class);

        // Configure the stub.
        $stub->method('doSomething')
             ->will($this->returnCallback('str_rot13'));

        // $stub->doSomething($argument) returns str_rot13($argument)
        $this->assertEquals('fbzrguvat', $stub->doSomething('something'));
    }
}
?>
```

# Mock Objects

- The practice of replacing an object with a test double that verifies expectations, for instance asserting that a method has been called, is referred to as mocking.
- You can use a mock object "as an observation point that is used to verify the indirect outputs of the SUT as it is exercised. Typically, the mock object also includes the functionality of a test stub in that it must return values to the SUT if it hasn't already failed the tests but the emphasis is on the verification of the indirect outputs. Therefore, a mock object is a lot more than just a test stub plus assertions; it is used in a fundamentally different way"

- Testing that a method gets called once and with a specified argument

```
<?php
use PHPUnit\Framework\TestCase;

class SubjectTest extends TestCase
{
    public function testObserversAreUpdated()
    {
        // Create a mock for the Observer class,
        // only mock the update() method.
        $observer = $this->getMockBuilder(Observer::class)
                         ->setMethods(['update'])
                         ->getMock();

        // Set up the expectation for the update() method
        // to be called only once and with the string 'something'
        // as its parameter.
        $observer->expects($this->once())
                 ->method('update')
                 ->with($this->equalTo('something'));

        // Create a Subject object and attach the mocked
        // Observer object to it.
        $subject = new Subject('My subject');
        $subject->attach($observer);

        // Call the doSomething() method on the $subject object
        // which we expect to call the mocked Observer object's
        // update() method with the string 'something'.
        $subject->doSomething();
    }
}
?>
```

- Testing that a method gets called with a number of arguments constrained in different ways

```
<?php
use PHPUnit\Framework\TestCase;

class SubjectTest extends TestCase
{
    public function testErrorReported()
    {
        // Create a mock for the Observer class, mocking the
        // reportError() method
        $observer = $this->getMockBuilder(Observer::class)
                         ->setMethods(['reportError'])
                         ->getMock();

        $observer->expects($this->once())
                 ->method('reportError')
                 ->with(
                       $this->greaterThan(0),
                       $this->stringContains('Something'),
                       $this->anything()
                   );

        $subject = new Subject('My subject');
        $subject->attach($observer);

        // The doSomethingBad() method should report an error to the observer
        // via the reportError() method
        $subject->doSomethingBad();
    }
}
?>
```
- The withConsecutive() method can take any number of arrays of arguments, depending on the calls you want to test against. Each array is a list of constraints corresponding to the arguments of the method being mocked, like in with().


```
<?php
use PHPUnit\Framework\TestCase;

class FooTest extends TestCase
{
    public function testFunctionCalledTwoTimesWithSpecificArguments()
    {
        $mock = $this->getMockBuilder(stdClass::class)
                     ->setMethods(['set'])
                     ->getMock();

        $mock->expects($this->exactly(2))
             ->method('set')
             ->withConsecutive(
                 [$this->equalTo('foo'), $this->greaterThan(0)],
                 [$this->equalTo('bar'), $this->greaterThan(0)]
             );

        $mock->set('foo', 21);
        $mock->set('bar', 48);
    }
}
?>
```
