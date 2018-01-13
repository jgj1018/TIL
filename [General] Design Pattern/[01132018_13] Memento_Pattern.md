[ref1](https://sourcemaking.com/design_patterns/memento)
[ref2](https://sourcemaking.com/design_patterns/memento/php)
[ref3](https://en.wikipedia.org/wiki/Memento_pattern)


##Intro

Without violating encapsulation, capture and externalize an object's internal state so that 
the object can be returned to this state later. Need to restore an object back to its previous state (e.g. "undo" or "rollback" operations).

#UML1

- Originator - the object that knows how to save itself.
- Caretaker - the object that knows why and when the Originator needs to save and restore itself.
- Memento - the lock box that is written and read by the Originator, and shepherded by the Caretaker.

![UML](https://sourcemaking.com/files/v2/content/patterns/Memento.svg)

#UML2

![UML2](https://upload.wikimedia.org/wikipedia/commons/3/38/W3sDesign_Memento_Design_Pattern_UML.jpg)

In the above UML class diagram, the Caretaker class refers to the Originator class for saving (createMemento()) and restoring (restore(memento)) originator's internal state.
The Originator class implements
(1) createMemento() by creating and returning a Memento object that stores originator's current internal state and
(2) restore(memento) by restoring state from the passed in Memento object.

The UML sequence diagram shows the run-time interactions:
(1) Saving originator's internal state: The Caretaker object calls createMemento() on the Originator object, which creates a Memento object, saves its current internal state (setState()), and returns the Memento to the Caretaker.
(2) Restoring originator's internal state: The Caretaker calls restore(memento) on the Originator object and specifies the Memento object that stores the state that should be restored. The Originator gets the state (getState()) from the Memento to set its own state.


## Example

In this example, the BookMark class is the "Memento", and holds the state of the BookReader class. The BookReader class would be the "Originator" in this example, as it had the original state. Client holds the BookMark object, and so is the "Caretaker".

```
<?php

class BookReader {    
    private $title;   
    private $page;    
    function __construct($title_in, $page_in) {
      $this->setPage($page_in);
      $this->setTitle($title_in);
    }  
    public function getPage() {
      return $this->page;
    }      
    public function setPage($page_in) {
      $this->page = $page_in;
    }
    public function getTitle() {
      return $this->title;
    }      
    public function setTitle($title_in) {
      $this->title = $title_in;
    }
}

class BookMark {    
    private $title;    
    private $page;    
    function __construct(BookReader $bookReader) {
      $this->setPage($bookReader);
      $this->setTitle($bookReader);      
    }  
    public function getPage(BookReader $bookReader) {
      $bookReader->setPage($this->page);
    }  
    public function setPage(BookReader $bookReader) {
      $this->page = $bookReader->getPage();
    }    
    public function getTitle(BookReader $bookReader) {
      $bookReader->setTitle($this->title);
    }      
    public function setTitle(BookReader $bookReader) {
      $this->title = $bookReader->getTitle();
    }    
}

  // Client

  writeln('BEGIN TESTING MEMENTO PATTERN');
  writeln('');
 
  $bookReader = new BookReader('Core PHP Programming, Third Edition','103');
  $bookMark = new BookMark($bookReader);
 
  writeln('(at beginning) bookReader title: '.$bookReader->getTitle());
  writeln('(at beginning) bookReader page: '.$bookReader->getPage());
 
  $bookReader->setPage("104");
  $bookMark->setPage($bookReader);
  writeln('(one page later) bookReader page: '.$bookReader->getPage());  

  $bookReader->setPage('2005');  //oops! a typo
  writeln('(after typo) bookReader page: '.$bookReader->getPage());    
 
  $bookMark->getPage($bookReader);
  writeln('(back to one page later) bookReader page: '.$bookReader->getPage());    
  writeln('');

  writeln('END TESTING MEMENTO PATTERN');

  function writeln($line_in) {
    echo $line_in."<br/>";
  }

?> 
```