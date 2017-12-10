[ref1](https://sourcemaking.com/design_patterns/command)
[ref2](https://www.journaldev.com/1624/command-design-pattern)
[ref3](https://code.tutsplus.com/tutorials/design-patterns-the-command-pattern--cms-22942)
[ref4](https://www.codeproject.com/Articles/15207/Design-Patterns-Command-Pattern)

# Command pattern

In command pattern, the request is send to the invoker and invoker pass it to the encapsulated command object. Command object passes the request to the appropriate method of Receiver to perform the specific action. The client program create the receiver object and then attach it to the Command. Then it creates the invoker object and attach the command object to perform an action.

`
The command pattern is a behavioral design pattern in which an object is used to represent and encapsulate all the information needed to call a method at a later time. This information includes the method name, the object that owns the method and values for the method parameters.
`

The Command pattern has three main components: the Invoker, the Command, and the Receiver. The invoker component acts as a link between the commands and the receiver, and houses the receiver and the individual commands as they are sent. The command is an object that encapsulates a request to the receiver. The receiver is the component that is acted upon by each request.

![UML](https://www.codeproject.com/KB/books/DesignPatterns/1.jpg)


```
// Receiver
class radioControl {
    public function turnOn() {
        // Turning On Radio
        echo "Turning On Radio";
    }
    public function turnOff() {
        // Turning Off Radio
        echo "Turning Off Radio";
    }
}
 
// Command
interface radioCommand {
    public function execute();
}
 
class turnOnRadio implements radioCommand {
    private $radioControl;
    public function __construct(radioControl $radioControl) {
        $this->radioControl = $radioControl;
    }
    public function execute() {
        $this->radioControl->turnOn ();
    }
}
 
class turnOffRadio implements radioCommand {
    private $radioControl;
    public function __construct(radioControl $radioControl) {
        $this->radioControl = $radioControl;
    }
    public function execute() {
        $this->radioControl->turnOff ();
    }
}
 
 
// Client
$in = 'turnOffRadio';
 
// Invoker
if (class_exists ( $in )) {
    $command = new $in ( new radioControl () );
} else {
    throw new Exception ( '..Command Not Found..' );
}
 
$command->execute ();
```