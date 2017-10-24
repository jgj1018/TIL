[reference1](https://phpunit.de/manual/current/en/appendixes.annotations.html)

# phpunit Annotations

@author 

This one is an alias for the @group annotation, and allows to filter tests based on their authors.

@after

This one can be used to specify methods that should be called after each test method in a test case class.
when static method will be called, use @afterClass.

@before

This one can be used to specify methods that should be called before each test method in a test case class.
when static method will be called, use @beforeClass

@covers

This one can be used in the test code to specify which method(s) a test method wants to test.

```
/**
 * @covers BankAccount::getBalance
 */
public function testBalanceIsInitiallyZero()
{
    $this->assertEquals(0, $this->ba->getBalance());
}
```

refer to the reference link for the details.

@dataProvider

A test method can accept arbitrary arguments. These arguments are to be provided by a data provider method. The data provider method to be used is specified using this annotation.

@depends

Phpunit support the declaration of expicit dependencies between test methods. Such dependencies do not difine the order in which the test methods are to be executed but they allow the returning of an instance of the test fixture by a producer and passing it to the dependent consumers.

```
    public function testEmpty()
    {
        $stack = [];
        $this->assertEmpty($stack);

        return $stack;
    }

    /**
     * @depends testEmpty
     */
    public function testPush(array $stack)
    {
        array_push($stack, 'foo');
        $this->assertEquals('foo', $stack[count($stack)-1]);
        $this->assertNotEmpty($stack);

        return $stack;
    }
```

@group

A test can be tagged as belonging to one or more groups using the @group annotation like this.

```
    /**
     * @group regresssion
     * @group bug2204
     */
    public function testSomethingElse()
    {
    }
```

@small

It is an alias for @group small, a small test will fail if it takes longer than 1 second to execute. The timeout is configurable via the timeoutForSmallTests attribute in the XML configuration file.

@test

As an alternative to prefixing my test method named with test, I can use the @test annotation in a method's DocBlock to mark it as a test method.

@uses

This one specifies code which will be executed by a test, but is not intended to be covered by the test. This annotation is especially useful in strict coverage mode where unintentinally covered code will cause a test to fail.
