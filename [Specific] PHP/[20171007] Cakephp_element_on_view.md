# Element

reusable parts are called Elements in Cakephp. An element is basically a mini-view that can be included in other views in layouts, and even within other elements. 

folder: src/Template/Element
file name extension: .ctp
on view : echo $this->element('{element file name}');

- Passing variables into an Element

```
echo $this->element('{element name}', [
	"{variable name}" => {variable value}
]);
```

it works like Controller::set(). so {variable name} can be used in the element ctp file as a variable.



 