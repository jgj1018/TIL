[ref1](https://book.cakephp.org/3.0/en/controllers/request-response.html#request-parameters)

# Request

By default the request is assigned to $this->request, and is available in Controllers, Cells, Views and Helpers. You can also access it in Components using the controller reference.

- Request Parameters

```
// Passed arguments
$passedArgs = $this->request->getParam('pass');
```

- Query String
```
// URL is /posts/index?page=1&sort=title
$page = $this->request->getQuery('page');
```

- Request body data

```
// An input with a name attribute equal to 'MyModel[title]' is accessible at
$title = $this->request->getData('MyModel.title');
```

- Environment Variables (from $_SERVER and $_ENV)

ServerRequest::env() is a wrapper for env() global function and acts as a getter/setter for enviromnent variables without having to modify globals $_SERVER and $_ENV:

```
// Get the host
$host = $this->request->env('HTTP_HOST');

// Set a value, generally helpful in testing.
$this->request->env('REQUEST_METHOD', 'POST');
```

- Path Information

The request object also provides useful information about the paths in your application. The base and webroot attributes are useful for generating URLs, and determining whether or not your application is in a subdirectory. The attributes you can use are:

```
// Assume the current request URL is /subdir/articles/edit/1?page=1

// Holds /subdir/articles/edit/1?page=1
$here = $request->getRequestTarget();

// Holds /subdir
$base = $request->getAttribute('base');

// Holds /subdir/
$base = $request->getAttribute('webroot');

// Prior to 3.4.0
$webroot = $request->webroot;
$base = $request->base;
$here = $request->here();
```