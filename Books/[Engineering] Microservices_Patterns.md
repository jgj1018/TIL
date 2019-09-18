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