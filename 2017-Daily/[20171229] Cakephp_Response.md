[ref1](https://book.cakephp.org/3.0/en/controllers/request-response.html#response)

# Response

Cake\Http\Response is the default response class in CakePHP. It encapsulates a number of features and functionality for generating HTTP responses in my application. It also assists in testing, as it can be mocked/stubbed allowing I to inspect headers that will be sent. Like Cake\Http\ServerRequest, Cake\Http\Response consolidates a number of methods previously found on Controller, RequestHandlerComponent and Dispatcher. The old methods are deprecated in favour of using Cake\Http\Response.

# Setting the Body

```
// Set a string into the body
$response = $response->withStringBody('My Body');

// If I want a json response
$response = $response->withType('application/json')
    ->withStringBody(json_encode(['Foo' => 'bar']));
```

To set the response body, use the withBody() method, which is provided by the Zend\Diactoros\MessageTrait:

```
$response = $response->withBody($stream);

// Prior to 3.4.0 - Set the body
$this->response->body('My Body');
```

Be sure that $stream is a Psr\Http\Message\StreamInterface object. See below on how to create a new stream.

# Setting the Character Set

```
$this->response = $this->response->withCharset('UTF-8');

// Prior to 3.4.0
$this->response->charset('UTF-8');
```

# Setting Headers

```
// Add/replace a header
$response = $response->withHeader('X-Extra', 'My header');

// Set multiple headers
$response = $response->withHeader('X-Extra', 'My header')
    ->withHeader('Location', 'http://example.com');

// Append a value to an existing header
$response = $response->withAddedHeader('Set-Cookie', 'remember_me=1');

// Prior to 3.4.0 - Set a header
$this->response->header('Location', 'http://example.com');
```

# Dealing with Content Types

I can control the Content-Type of my application’s responses with Cake\Http\Response::withType(). If my application needs to deal with content types that are not built into Response, I can map them with type() as well:

```
// Add a vCard type
$this->response->type(['vcf' => 'text/v-card']);

// Set the response Content-Type to vcard.
$this->response = $this->response->withType('vcf');

// Prior to 3.4.0
$this->response->type('vcf');
```

Usually, I’ll want to map additional content types in my controller’s beforeFilter() callback, so I can leverage the automatic view switching features of RequestHandlerComponent if I are using it.