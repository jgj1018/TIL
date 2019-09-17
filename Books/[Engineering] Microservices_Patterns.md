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