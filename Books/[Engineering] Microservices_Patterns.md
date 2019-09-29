# Chapter 1. Escaping monolithic hell

## 1.1. THE SLOW MARCH TOWARD MONOLITHIC HELL

### 1.1.3. Living in monolithic hell

- Not only did this increase the growth rate of the code base, it also increased the management overhead.

- It’s too large for any developer to fully understand. As a result, fixing bugs and correctly implementing new features have become difficult and time consuming. Deadlines are missed.

- because it’s so large, the application takes a long time to start up. As a result, the edit-build-run-test loop takes a long time, which badly impacts productivity.

- Another reason it takes so long to get changes into production is that testing takes a long time. Because the code base is so complex and the impact of a change isn’t well understood

- the application lacks fault isolation, because all modules are running within the same process.

## 1.4. MICROSERVICE ARCHITECTURE TO THE RESCUE

- microservice architecture as a service-oriented architecture composed of loosely coupled elements that have bounded contexts.

### 1.4.1. Scale cube and microservices

- Z-axis scaling also runs multiple instances of the monolith application, but unlike X-axis scaling, each instance is responsible for only a subset of the data.

- X- and Z-axis scaling improve the application’s capacity and availability. But neither approach solves the problem of increasing development and application complexity. To solve those, you need to apply Y-axis scaling, or functional decomposition. 

- A service is a mini application that implements narrowly focused functionality

- The high-level definition of microservice architecture (microservices) is an architectural style that functionally decomposes an application into a set of services. Note that this definition doesn’t say anything about size. Instead, what matters is that each service has a focused, cohesive set of responsibilities.

### 1.4.2. Microservices as a form of modularity

- The microservice architecture uses services as the unit of modularity. A service has an API, which is an impermeable boundary that is difficult to violate.

### 1.4.3. Each service has its own database

- A key characteristic of the microservice architecture is that the services are loosely coupled and communicate only via APIs. One way to achieve loose coupling is by each service having its own datastore.

### 1.4.5. Comparing the microservice architecture and SOA

- Applications built using the microservice architecture tend to use lightweight, open source technologies. The services communicate via dumb pipes, such as message brokers or lightweight protocols like REST or gRPC.

- each service is usually considered to have its own domain model.

### 1.5.1. Benefits of the microservice architecture

- It enables the continuous delivery and deployment of large, complex applications.
- Services are small and easily maintained.
- Services are independently deployable.
- Services are independently scalable.
- The microservice architecture enables teams to be autonomous.
- It allows easy experimenting and adoption of new technologies.
- It has better fault isolation.

- It reduces the time to market, which enables the business to rapidly react to feedback from customers.

- Employee satisfaction is higher because more time is spent delivering valuable features instead of fighting fires.

- Each service in a microservice architecture can be scaled independently of other services using X-axis cloning and Z-axis partitioning

- because the services are small, rewriting them using better languages and technologies becomes practical.

### 1.5.2. Drawbacks of the microservice architecture

- Finding the right set of services is challenging.
- Distributed systems are complex, which makes development, testing, and deployment difficult.
- Deploying features that span multiple services requires careful coordination.
- Deciding when to adopt the microservice architecture is difficult.

- if you decompose a system incorrectly, you’ll build a distributed monolith

- Another issue with using the microservice architecture is that developers must deal with the additional complexity of creating a distributed system. Services must use an interprocess communication mechanism. This is more complex than a simple method call.

- Implementing use cases that span multiple services requires the use of unfamiliar techniques. Each service has its own database, which makes it a challenge to implement transactions and queries that span services. 

- Another challenge with using the microservice architecture is that deploying features that span multiple services requires careful coordination between the various development teams. You have to create a rollout plan that orders service deployments based on the dependencies between services.

## 1.6. THE MICROSERVICE ARCHITECTURE PATTERN LANGUAGE

- A good way to describe the various architectural and design options and improve decision making is to use a pattern language.

### 1.6.3. Overview of the Microservice architecture pattern language

- There are two decomposition patterns: Decompose by business capability, which organizes services around business capabilities, and Decompose by subdomain, which organizes services around domain-driven design (DDD) subdomains.

- understanding and diagnosing problems in a microservice architecture is much more complicated. A request can bounce around between multiple services before a response is finally returned to a client. Consequently, there isn’t one log file to examine.

-  it’s important to test that the different services work together while avoiding using complex, slow, and brittle end-to-end tests that test multiple services together.

## 1.7. BEYOND MICROSERVICES: PROCESS AND ORGANIZATION

- successful software development requires you to also have organization, and development and delivery processes.

- The rapid, frequent, and reliable delivery of large, complex applications requires a combination of DevOps, which includes continuous delivery/deployment, small, autonomous teams, and the microservice architecture.

### 1.7.1. Software development and delivery organization

- the team gets too large, it will become inefficient, due to the communication overhead. 

- The solution is to refactor a large single team into a team of teams

- In order to effectively deliver software when using the microservice architecture, you need to take into account Conway’s law: Organizations which design systems ... are constrained to produce designs which are copies of the communication structures of these organizations.

### 1.7.2. Software development and delivery process

- If you want to develop an application with the microservice architecture, it’s essential that you adopt agile development and deployment practices such as Scrum or Kanban. Better yet, you should practice continuous delivery/deployment, which is a part of DevOps.

- A key characteristic of continuous delivery is that software is always releasable. It relies on a high level of automation, including automated testing.

## SUMMARY

- The Monolithic architecture pattern structures the application as a single deployable unit.
- The Microservice architecture pattern decomposes a system into a set of independently deployable services, each with its own database.
- The monolithic architecture is a good choice for simple applications, but microservice architecture is usually a better choice for large, complex applications.
- The microservice architecture accelerates the velocity of software development by enabling small, autonomous teams to work in parallel.
- The microservice architecture isn’t a silver bullet—there are significant drawbacks, including complexity.
- The Microservice architecture pattern language is a collection of patterns that help you architect an application using the microservice architecture. It helps you decide whether to use the microservice architecture, and if you pick the microservice architecture, the pattern language helps you apply it effectively.
- You need more than just the microservice architecture to accelerate software delivery. Successful software development also requires DevOps and small, autonomous teams.
- Don’t forget about the human side of adopting microservices. You need to consider employees’ emotions in order to successfully transition to a microservice architecture.

# Chapter 2. Decomposition strategies

## 2.1. WHAT IS THE MICROSERVICE ARCHITECTURE EXACTLY?

- Traditionally, the goal of architecture has been scalability, reliability, and security. But today it’s important that the architecture also enables the rapid and safe delivery of software. You’ll learn that the microservice architecture is an architecture style that gives an application high maintainability, testability, and deployability.

### 2.1.1. What is software architecture and why does it matter?

- The software architecture of a computing system is the set of structures needed to reason about the system, which comprise software elements, relations among them, and properties of both.

- Logical view— The software elements that are created by developers. In object-oriented languages, these elements are classes and packages. The relations between them are the relationships between classes and packages, including inheritance, associations, and depends-on.
- Implementation view— The output of the build system. This view consists of modules, which represent packaged code, and components, which are executable or deployable units consisting of one or more modules. In Java, a module is a JAR file, and a component is typically a WAR file or an executable JAR file. The relations between them include dependency relationships between modules and composition relationships between components and modules.
- Process view— The components at runtime. Each element is a process, and the relations between processes represent interprocess communication.
- Deployment— How the processes are mapped to machines. The elements in this view consist of (physical or virtual) machines and the processes. The relations between machines represent networking. This view also describes the relationship between processes and machines.

- An application has two categories of requirements. The first category includes the functional requirements, which define what the application must do. They’re usually in the form of use cases or user stories. Architecture has very little to do with the functional requirements. You can implement functional requirements with almost any architecture, even a big ball of mud.

- Architecture is important because it enables an application to satisfy the second category of requirements: its quality of service requirements. 

- The quality of service requirements define the runtime qualities such as scalability and reliability. They also define development time qualities including maintainability, testability, and deployability. The architecture you choose for your application determines how well it meets these quality requirements.

### 2.1.2. Overview of architectural styles

- An important benefit of the hexagonal architectural style is that it decouples the business logic from the presentation and data access logic in the adapters. The business logic doesn’t depend on either the presentation logic or the data access logic. Because of this decoupling, it’s much easier to test the business logic in isolation. 

### 2.1.3. The microservice architecture is an architectural style

-  Monolithic architecture is an architectural style that structures the implementation view as a single component: a single executable or WAR file.

- The microservice architecture is also an architectural style. It structures the implementation view as a set of multiple components: executables or WAR files. The components are services, and the connectors are the communication protocols that enable those services to collaborate. Each service has its own logical view architecture, which is typically a hexagonal architecture.

- A service is a standalone, independently deployable software component that implements some useful functionality.

- A service’s API encapsulates its internal implementation. Unlike in a monolith, a developer can’t write code that bypasses its API. As a result, the microservice architecture enforces the application’s modularity.

- An essential requirement, however, is that a service has an API and is independently deployable.

- The requirement for services to be loosely coupled and to collaborate only via APIs prohibits services from communicating via a database. 

-  Keeping the data private enables a developer to change their service’s database schema without having to spend time coordinating with developers working on other services.

-  On the surface, it looks like a good way to reduce code duplication in your services. But you need to ensure that you don’t accidentally introduce coupling between your services.

- You should strive to use libraries for functionality that’s unlikely to change. 

- A much better goal is to define a well-designed service to be a service capable of being developed by a small team with minimal lead time and with minimal collaboration with other teams. 

- if you constantly need to change a service because of changes to other services or if it’s triggering changes in other services, that’s a sign that it’s not loosely coupled. You might even have built a distributed monolith.

## 2.2. DEFINING AN APPLICATION’S MICROSERVICE ARCHITECTURE

-  defining an architecture is more art than science.

- It’s important to remember, though, that it’s not a process you can follow mechanically. It’s likely to be iterative and involve a lot of creativity.

- An application exists to handle requests, so the first step in defining its architecture is to distill the application’s requirements into the key requests.

- The system operations become the architectural scenarios that illustrate how the services collaborate.

- The second step in the process is to determine the decomposition into services. There are several strategies to choose from. One strategy, which has its origins in the discipline of business architecture, is to define services corresponding to business capabilities. Another strategy is to organize services around domain-driven design subdomains. The end result is services that are organized around business concepts rather than technical concepts.

- There are several obstacles to decomposition. The first is network latency. 

- Another obstacle to decomposition is that synchronous communication between services reduces availability.

- The third obstacle is the requirement to maintain data consistency across services.

- The fourth and final obstacle to decomposition is so-called god classes, which are used throughout an application. 

### 2.2.1. Identifying the system operations

- There are two types of system operations:

- Commands— System operations that create, update, and delete data
- Queries— System operations that read (query) data

- A command has a specification that defines its parameters, return value, and behavior in terms of the domain model classes. The behavior specification consists of preconditions that must be true when the operation is invoked, and post-conditions that are true after the operation is invoked.

- The high-level domain model and the system operations capture what the application does. They help drive the definition of the application’s architecture.

- Once the system operations have been defined, the next step is to identify the application’s services.

- an architecture consisting of services that are primarily organized around business rather than technical concepts.

### 2.2.2. Defining services by applying the Decompose by business capability pattern

- business capability is something that a business does in order to generate value. The set of capabilities for a given business depends on the kind of business. 

- An organization’s business capabilities capture what an organization’s business is. They’re generally stable, as opposed to how an organization conducts its business, which changes over time, sometimes dramatically

- Deposit check business capability has remained stable, but the manner in which it’s done has drastically changed.

- An organization’s business capabilities are identified by analyzing the organization’s purpose, structure, and business processes. Each business capability can be thought of as a service

- A key benefit of organizing services around capabilities is that because they’re stable, the resulting architecture will also be relatively stable. The individual components of the architecture may evolve as the how aspect of the business changes, but the architecture remains unchanged.

### 2.2.3. Defining services by applying the Decompose by sub-domain pattern

- DDD (...) is an approach for building complex software applications that is centered on the development of an object-oriented domain model. 

- DDD has two concepts that are incredibly useful when applying the microservice architecture: subdomains and bounded contexts.

- A subdomain is a part of the domain, DDD’s term for the application’s problem space. Subdomains are identified using the same approach as identifying business capabilities: analyze the business and identify the different areas of expertise. The end result is very likely to be subdomains that are similar to the business capabilities.

- DDD calls the scope of a domain model a bounded context. A bounded context includes the code artifacts that implement the model. When using the microservice architecture, each bounded context is a service or possibly a set of services

### 2.2.4. Decomposition guidelines

- object-oriented design (...) The first principle is the Single Responsibility Principle (SRP), for defining the responsibilities of a class. The second principle is the Common Closure Principle (CCP), for organizing classes into packages.

- A class should have only one reason to change.

- The classes in a package should be closed together against the same kinds of changes. A change that affects a package affects all the classes in that package.

- The idea is that if two classes change in lockstep because of the same underlying reason, then they belong in the same package.

- The goal is that when that business rule changes, developers only need to change code in a small number of packages (ideally only one). Adhering to the CCP significantly improves the maintainability of an application.

- CCP is the antidote to the distributed monolith anti-pattern.

### 2.2.5. Obstacles to decomposing an application into services

- Network latency is an ever-present concern in a distributed system. 

- Another problem is how to implement interservice communication in a way that doesn’t reduce availability.

- you must use a very different approach to transaction management, a saga. A saga is a sequence of local transactions that are coordinated using messaging.

- in a microservice architecture, even though each service’s database is consistent, you can’t obtain a globally consistent view of the data.

- One solution is to package the Order class into a library and create a central Order database. (...) The trouble with this approach is that it violates one of the key principles of the microservice architecture and results in undesirable, tight coupling

- A much better approach is to apply DDD and treat each service as a separate subdomain with its own domain model.

### 2.2.6. Defining service APIs

- A service API operation exists for one of two reasons: some operations correspond to system operations. They are invoked by external clients and perhaps by other services. The other operations exist to support collaboration between services. These operations are only invoked by other services.

- The starting point for defining the service APIs is to map each system operation to a service. After that, we decide whether a service needs to collaborate with others to implement a system operation. If collaboration is required, we then determine what APIs those other services must provide in order to support the collaboration.

## SUMMARY

- Architecture determines your application’s -ilities, including maintainability, testability, and deployability, which directly impact development velocity.
- The microservice architecture is an architecture style that gives an application high maintainability, testability, and deployability.
Services in a microservice architecture are organized around business concerns—business capabilities or subdomains—rather than technical concerns.
- There are two patterns for decomposition:
- Decompose by business capability, which has its origins in business architecture
- Decompose by subdomain, based on concepts from domain-driven design
- You can eliminate god classes, which cause tangled dependencies that prevent decomposition, by applying DDD and defining a separate domain model for each service.

# Chapter 3. Interprocess communication in a microservice architecture

- I favor an architecture consisting of loosely coupled services that communicate with one another using asynchronous messaging. Synchronous protocols such as REST are used mostly to communicate with other applications.

## 3.1. OVERVIEW OF INTERPROCESS COMMUNICATION IN A MICROSERVICE ARCHITECTURE

### 3.1.1. Interaction styles

- Request/response— A service client makes a request to a service and waits for a response. The client expects the response to arrive in a timely fashion. It might event block while waiting. This is an interaction style that generally results in services being tightly coupled.
- Asynchronous request/response— A service client sends a request to a service, which replies asynchronously. The client doesn’t block while waiting, because the service might not send the response for a long time.
- One-way notifications— A service client sends a request to a service, but no reply is expected or sent.

- The following are the different types of one-to-many interactions:
- Publish/subscribe— A client publishes a notification message, which is consumed by zero or more interested services.
- Publish/async responses— A client publishes a request message and then waits for a certain amount of time for responses from interested services.

### 3.1.2. Defining APIs in a microservice architecture

- APIs or interfaces are central to software development. An application is comprised of modules. Each module has an interface that defines the set of operations that module’s clients can invoke. A well-designed interface exposes useful functionality while hiding the implementation. It enables the implementation to change without impacting clients.

- Regardless of which IPC mechanism you choose, it’s important to precisely define a service’s API using some kind of interface definition language (IDL) (...) Only after iterating on the API definition do you then implement the service. 

- The nature of the API definition depends on which IPC mechanism you’re using

- In a microservices-based application, changing a service’s API is a lot more difficult. A service’s clients are other services, which are often developed by other teams. The clients may even be other applications outside of the organization.

### 3.1.3. Evolving APIs

- MAJOR— When you make an incompatible change to the API
- MINOR— When you make backward-compatible enhancements to the API
- PATCH— When you make a backward-compatible bug fix

### 3.1.4. Message formats

- The first category is text-based formats such as JSON and XML. An advantage of these formats is that not only are they human readable, they’re self describing.

## 3.2. COMMUNICATING USING THE SYNCHRONOUS REMOTE PROCEDURE INVOCATION PATTERN

### 3.2.1. Using REST

- A key concept in REST is a resource, which typically represents a single business object.

-  a common problem when designing a REST API is how to enable the client to retrieve multiple related objects in a single request. 

- One solution to this problem is for an API to allow the client to retrieve related resources when it gets a resource. 

- it’s often insufficient for more complex scenarios. It’s also potentially time consuming to implement. This has led to the increasing popularity of alternative API technologies such as GraphQL

- A downside of using a text-based messages format is that the messages tend to be verbose, (...) Another drawback is the overhead of parsing text, especially when messages are large.

- It only supports the request/response style of communication.

- Reduced availability. Because the client and service communicate directly without an intermediary to buffer messages, they must both be running for the duration of the exchange.

- Clients must know the locations (URLs) of the service instances(s).

- Fetching multiple resources in a single request is challenging.

- It’s sometimes difficult to map multiple update operations to HTTP verbs.

### 3.2.2. Using gRPC

- As mentioned in the preceding section, one challenge with using REST is that because HTTP only provides a limited number of verbs, it’s not always straightforward to design a REST API that supports multiple update operations

### 3.2.3. Handling partial failure using the Circuit breaker pattern

- Network timeouts+ Using timeouts ensures that resources are never tied up indefinitely.

- Limiting the number of outstanding requests from a client to a service— Impose an upper bound on the number of outstanding requests that a client can make to a particular service.

- Circuit breaker pattern— Track the number of successful and failed requests, and if the error rate exceeds some threshold, trip the circuit breaker so that further attempts fail immediately. A large number of requests failing suggests that the service is unavailable and that sending more requests is pointless. After a timeout period, the client should try again, and, if successful, close the circuit breaker.

-  If the Delivery Service is unavailable, the API gateway should return either a cached version of its data or omit it from the response. 

### 3.2.4. Using service discovery

- Service discovery is conceptually quite simple: its key component is a service registry, which is a database of the network locations of an application’s service instances.

- The service discovery mechanism updates the service registry when service instances start and stop. When a client invokes a service, the service discovery mechanism queries the service registry to obtain a list of available service instances and routes the request to one of them.

- One drawback of application-level service discovery is that you need a service discovery library for every language

- Another drawback of application-level service discovery is that you’re responsible for setting up and managing the service registry, which is a distraction. As a result, it’s usually better to use a service discovery mechanism that’s provided by the deployment infrastructure.

- The deployment platform gives each service a DNS name, a virtual IP (VIP) address, and a DNS name that resolves to the VIP address. A service client makes a request to the DNS name/VIP, and the deployment platform automatically routes the request to one of the available service instances.

- service registration, service discovery, and request routing are entirely handled by the deployment platform.

## 3.3. COMMUNICATING USING THE ASYNCHRONOUS MESSAGING PATTERN

### 3.3.1. Overview of messaging

- A publish-subscribe channel delivers each message to all of the attached consumers. Services use publish-subscribe channels for the one-to-many interaction styles described earlier. For example, an event message is usually sent over a publish-subscribe channel.

### 3.3.2. Implementing the interaction styles using messaging

- Messaging is inherently asynchronous, so only provides asynchronous request/response. But a client could block until a reply is received.

-  the Delivery Service publishes Delivery events to a Delivery channel. A service that’s interested in a particular domain object’s events only has to subscribe to the appropriate channel.

- A client publishes a message that specifies a reply channel header to a publish-subscribe channel. A consumer writes a reply message containing a correlation id to the reply channel. The client gathers the responses by using the correlation id to match the reply messages with the request.

### 3.3.4. Using a message broker

- The brokerless architecture has some benefits:
- Allows lighter network traffic and better latency, because messages go directly from the sender to the receiver, instead of having to go from the sender to the message broker and from there to the receiver
- Eliminates the possibility of the message broker being a performance bottleneck or a single point of failure
- Features less operational complexity, because there is no message broker to set up and maintain

- significant drawbacks:
- Services need to know about each other’s locations and must therefore use one of the discovery mechanisms
- It offers reduced availability, because both the sender and receiver of a message must be available while the message is being exchanged.
- Implementing mechanisms, such as guaranteed delivery, is more challenging.

- An important benefit of using a message broker is that the sender doesn’t need to know the network location of the consumer. Another benefit is that a message broker buffers messages until the consumer is able to process them.

- Each broker makes different trade-offs. For example, a very low-latency broker might not preserve ordering, make no guarantees to deliver messages, and only store messages in memory. A messaging broker that guarantees delivery and reliably stores messages on disk will probably have higher latency

-  many advantages to using broker-based messaging:
- Loose coupling— A client makes a request by simply sending a message to the appropriate channel. The client is completely unaware of the service instances. It doesn’t need to use a discovery mechanism to determine the location of a service instance.
- Message buffering— The message broker buffers messages until they can be processed. 

-  some downsides to using messaging:
- Potential performance bottleneck— There is a risk that the message broker could be a performance bottleneck. Fortunately, many modern message brokers are designed to be highly scalable.
- Potential single point of failure— It’s essential that the message broker is highly available—otherwise, system reliability will be impacted. Fortunately, most modern brokers have been designed to be highly available.

### 3.3.5. Competing receivers and message ordering

- One challenge is how to scale out message receivers while preserving message ordering.
- A common solution, used by modern message brokers like Apache Kafka and AWS Kinesis, is to use sharded (partitioned) channels.

### 3.3.6. Handling duplicate messages

- Another challenge you must tackle when using messaging is dealing with duplicate messages. A message broker should ideally deliver each message only once, but guaranteeing exactly-once messaging is usually too costly. Instead, most message brokers promise to deliver a message at least once.

- Ideally, you should use a message broker that preserves ordering when redelivering messages. 

- Another option is for a message handler to record message ids in an application table instead of a dedicated table. This approach is particularly useful when using a NoSQL database that has a limited transaction model

- A simple solution is for a message consumer to track the messages that it has processed using the message id and discard any duplicates.

### 3.3.7. Transactional messaging

- A service often needs to publish messages as part of a transaction that updates the database. 

- A straightforward way to reliably publish messages is to apply the Transactional outbox pattern. This pattern uses a database table as a temporary message queue. (...) a service that sends messages has an OUTBOX database table. 

- The downside is that frequently polling the database can be expensive.

- A sophisticated solution is for MessageRelay to tail the database transaction log (also called the commit log).

- The Transaction Log Miner reads the transaction log entries. It converts each relevant log entry corresponding to an inserted message into a message and publishes that message to the message broker.

- Debezium: An open source project that publishes database changes to the Apache Kafka message broker.

- The challenge is that implementing it requires some development effort. Alternatively, you could use an open source framework such as Debezium that publishes changes made by an application to MySQL, Postgres, or MongoDB to Apache Kafka

## 3.4. USING ASYNCHRONOUS MESSAGING TO IMPROVE AVAILABILITY

### 3.4.1. Synchronous communication reduces availability

- If you want to maximize availability, you must minimize the amount of synchronous communication.

### 3.4.2. Eliminating synchronous interaction

-  there are ways to handle synchronous requests without making synchronous requests.

- Such an architecture would be extremely resilient, because the message broker buffers messages until they can be consumed. The problem, however, is that services often have an external API that uses a synchronous protocol such as REST, so it must respond to requests immediately.

- One way to minimize synchronous requests during request processing is to replicate data. (...) Consumer Service and Restaurant Service publish events whenever their data changes. Order Service subscribes to those events and updates its replica.

- Another way to eliminate synchronous communication during request processing is for a service to handle a request as follows:
- Validate the request using only the data available locally.
- Update its database, including inserting messages into the OUTBOX table.
- Return a response to its client.

- It creates the order and returns immediately before validating the order and authorizing the consumer’s credit card. Consequently, in order for the client to know whether the order was successfully created, either it must periodically poll or Order Service must send it a notification message. As complex as it sounds, in many situations this is the preferred approach—especially because it also addresses the distributed transaction management issues


## SUMMARY

- The microservice architecture is a distributed architecture, so interprocess communication plays a key role.
- It’s essential to carefully manage the evolution of a service’s API. Backward-compatible changes are the easiest to make because they don’t impact clients. If you make a breaking change to a service’s API, it will typically need to support both the old and new versions until its clients have been upgraded.
- There are numerous IPC technologies, each with different trade-offs. One key design decision is to choose either a synchronous remote procedure invocation pattern or the asynchronous Messaging pattern. Synchronous remote procedure invocation-based protocols, such as REST, are the easiest to use. But services should ideally communicate using asynchronous messaging in order to increase availability.
- In order to prevent failures from cascading through a system, a service client that uses a synchronous protocol must be designed to handle partial failures, which are when the invoked service is either down or exhibiting high latency. In particular, it must use timeouts when making requests, limit the number of outstanding requests, and use the Circuit breaker pattern to avoid making calls to a failing service.
- An architecture that uses synchronous protocols must include a service discovery mechanism in order for clients to determine the network location of a service instance. The simplest approach is to use the service discovery mechanism implemented by the deployment platform: the Server-side discovery and 3rd party registration patterns. But an alternative approach is to implement service discovery at the application level: the Client-side discovery and Self registration patterns. It’s more work, but it does handle the scenario where services are running on multiple deployment platforms.
- A good way to design a messaging-based architecture is to use the messages and channels model, which abstracts the details of the underlying messaging system. You can then map that design to a specific messaging infrastructure, which is typically message broker–based.
- One key challenge when using messaging is atomically updating the database and publishing a message. A good solution is to use the Transactional outbox pattern and first write the message to the database as part of the database transaction. A separate process then retrieves the message from the database using either the Polling publisher pattern or the Transaction log tailing pattern and publishes it to the message broker.


# Chapter 4. Managing transactions with sagas

- Instead of an ACID transactions, an operation that spans services must use what’s known as a saga, a message-driven sequence of local transactions, to maintain data consistency. One challenge with sagas is that they are ACD (Atomicity, Consistency, Durability). They lack the isolation feature of traditional ACID transactions. 

## 4.1. TRANSACTION MANAGEMENT IN A MICROSERVICE ARCHITECTURE

### 4.1.2. The trouble with distributed transactions

- Another problem with distributed transactions is that they are a form of synchronous IPC, which reduces availability. In order for a distributed transaction to commit, all the participating services must be available

- There is even Eric Brewer’s CAP theorem, which states that a system can only have two of the following three properties: consistency, availability, and partition tolerance (...) Today, architects prefer to have a system that’s available rather than one that’s consistent.

### 4.1.3. Using the Saga pattern to maintain data consistency

- Sagas are mechanisms to maintain data consistency in a microservice architecture (...) A saga is a sequence of local transactions.

- The system operation initiates the first step of the saga. The completion of a local transaction triggers the execution of the next local transaction. (...) An important benefit of asynchronous messaging is that it ensures that all the steps of a saga are executed, even if one or more of the saga’s participants is temporarily unavailable.

- if the recipient of a message is temporarily unavailable, the message broker buffers the message until it can be delivered.

- It’s important to note that not all steps need compensating transactions. Read-only steps don’t need compensating transactions. 

## 4.2. COORDINATING SAGAS

- If any local transaction fails, the saga must execute the compensating transactions in reverse order. 

### 4.2.1. Choreography-based sagas

- Choreography-based sagas have several benefits:
- Simplicity— Services publish events when they create, update, or delete business objects.
- Loose coupling— The participants subscribe to events and don’t have direct knowledge of each other.

- And there are some drawbacks:
- More difficult to understand— Unlike with orchestration, there isn’t a single place in the code that defines the saga. Instead, choreography distributes the implementation of the saga among the services. Consequently, it’s sometimes difficult for a developer to understand how a given saga works.
- Cyclic dependencies between the services— The saga participants subscribe to each other’s events, which often creates cyclic dependencies. For example, if you carefully examine figure 4.4, you’ll see that there are cyclic dependencies, such as Order Service → Accounting Service → Order - Service. Although this isn’t necessarily a problem, cyclic dependencies are considered a design smell.
- Risk of tight coupling— Each saga participant needs to subscribe to all events that affect them. For example, Accounting Service must subscribe to all events that cause the consumer’s credit card to be charged or refunded. As a result, there’s a risk that it would need to be updated in lockstep with the order lifecycle implemented by Order Service.
- Choreography can work well for simple sagas, but because of these drawbacks it’s often better for more complex sagas to use orchestration.

### 4.2.2. Orchestration-based sagas

- Orchestration-based sagas have several benefits:
- Simpler dependencies— One benefit of orchestration is that it doesn’t introduce cyclic dependencies. 
- Less coupling— Each service implements an API that is invoked by the orchestrator, so it does not need to know about the events published by the saga participants.
- Improves separation of concerns and simplifies the business logic— The saga coordination logic is localized in the saga orchestrator. The domain objects are simpler and have no knowledge of the sagas that they participate in. 

- Orchestration also has a drawback: the risk of centralizing too much business logic in the orchestrator. (...) you can avoid this problem by designing orchestrators that are solely responsible for sequencing and don’t contain any other business logic.I recommend using orchestration for all but the simplest sagas.

## 4.3. HANDLING THE LACK OF ISOLATION

- The challenge with using sagas is that they lack the isolation property of ACID transactions. That’s because the updates made by each of a saga’s local transactions are immediately visible to other sagas once that transaction commits (...) But in practice, it’s common for developers to accept reduced isolation in return for higher performance.

### 4.3.2. Countermeasures for handling the lack of isolation

- Semantic lock— An application-level lock.
- Commutative updates— Design update operations to be executable in any order.
- Pessimistic view— Reorder the steps of a saga to minimize business risk.
- Reread value— Prevent dirty writes by rereading data to verify that it’s unchanged before overwriting it.
- Version file— Record the updates to a record so that they can be reordered.
- By value— Use each request’s business risk to dynamically select the concurrency mechanism.


- a saga consists of three types of transactions:
- Compensatable transactions— Transactions that can potentially be rolled back using a compensating transaction.
- Pivot transaction— The go/no-go point in a saga. If the pivot transaction commits, the saga will run until completion. A pivot transaction can be a transaction that’s neither compensatable nor retriable. Alternatively, it can be the last compensatable transaction or the first retriable transaction.
- Retriable transactions— Transactions that follow the pivot transaction and are guaranteed to succeed.

## SUMMARY

- Some system operations need to update data scattered across multiple services. Traditional, XA/2PC-based distributed transactions aren’t a good fit for modern applications. A better approach is to use the Saga pattern. A saga is sequence of local transactions that are coordinated using messaging. Each local transaction updates data in a single service. Because each local transaction commits its changes, if a saga must roll back due to the violation of a business rule, it must execute compensating transactions to explicitly undo changes.

- You can use either choreography or orchestration to coordinate the steps of a saga. In a choreography-based saga, a local transaction publishes events that trigger other participants to execute local transactions. In an orchestration-based saga, a centralized saga orchestrator sends command messages to participants telling them to execute local transactions. You can simplify development and testing by modeling saga orchestrators as state machines. Simple sagas can use choreography, but orchestration is usually a better approach for complex sagas.

- Designing saga-based business logic can be challenging because, unlike ACID transactions, sagas aren’t isolated from one another. You must often use countermeasures, which are design strategies that prevent concurrency anomalies caused by the ACD transaction model. An application may even need to use locking in order to simplify the business logic, even though that risks deadlocks.