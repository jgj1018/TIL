[Book] Software architecture fundamental


**What is Software Architecture?**

What is Software Architecture?the highest level concept of the system in its environment. The architecture of a software system at a given point in time is its organization or structure of significant components interacting through interfaces, those components being composed of successively smaller components and interfaces.

he's basically saying that software architecture is a shared understanding between the people who built the system. In other words, you can't just take the structure of a software architecture system completely in isolation without understanding the motivations for why they chose a particular approach, a particular pattern, and the way that they put things together. Because you don't understand the trade-offs that they had to make to get to that final architectural decision.

So the point of this is that not only is architecture about shared understanding, it's also about broadcasting that understanding to a bunch of interested parties, all of which have their own priorities about what is important for this piece of software.

**Understanding the Expectations of an Architect**

One of those first core expectations of an architect is to define the architecture and design principles used to guide technology decisions through the enterprise.

the challenging part of a software architect is to form those architecture decisions and design principles that can guide others into making the right technology choices.

constantly analyze the technology and software environment and recommend solutions for improvement (…) An architecture that we define to maybe three or five years ago was perfect at that point. However, business grows, technology changes, things are always in flux. And the question is, is that architecture that we defined three or five years ago still valid today?

The third kind of expectation of an architect is to continually keep up with industry and technology trends.

The fourth expectation is to ensure compliance with the architecture.

And the fifth what are these, of course, is having a certain level of diversity in platforms technologies, tools frameworks. And again, as developers we have some level of breath in this, but as an architect, this is absolutely necessary, especially in today's world, where we start to have so much integration between different systems and subsystems and applications.

one of the hardest expectations is having a certain level of business domain expertise (…) vYou'll start to lose credibility. You'll have to be able to use the language that the business uses. And this necessarily requires you to have a certain level of domain expertise

The next expectation is even more challenging. And this expectation is to possess exceptional interpersonal skills, including teamwork, facilitation, negotiation.

this is a very challenging but incredibly important aspect of being a software architect. Perhaps though the final expectation of a software architect is perhaps the most complex. (…) most of the decisions you make as an architect will in fact be challenged. And if you need to make a decision to accomplish a certain thing, you want to drive that agenda through. Knowing the political climate of your enterprise, knowing how to navigate politics, knowing who you're going to probably offend or who's going to challenge you helps in terms of getting that justification, not only technical, but business justification. So this, in fact in my opinion, is about half of being a software architect.

knowing that more things exist is more valuable as an architect than knowing exactly how to implement something in a particular technology.

as the architect, (...) generally, you've got three main kind of responsibilities. The first is to identify the architectural characteristics and manage those. In other words, those ilities, the performance of characteristics like scalability, availability. And know about these aspects and identify those characteristics. As a matter of fact, we'll see how to do that in the identifying characteristics segment. The next thing is to actually identify which architecture patterns are best suited for this particular application. Is it microservices, maybe micro kernel? Maybe space-based is a better solution for this, or event-driven architecture. And we'll be looking at that, as well. But kind of the third piece is also identifying those core tenants of the architecture, those building blocks. So this is kind of what an architect does or is overly responsible for.

The more we start designing and developing the lower level aspects of that solution, the more we uncover issues and problems. And in fact, maybe that architecture decision was actually not correct, in which case there also needs to be that feedback loop back to the architect so that they know we don't see that this can work

This whole loop of communication is how to make architecture work.

I have also found a really effective way of balancing hands-on coding with software architecture in those situations where you're bouncing from team to team as an architect. What you can do is code reviews. (…) first, What better way to ensure compliance than to do code reviews? (…) Number two, you can also use the justification that you want to ensure code quality and look for mentoring opportunities with some junior developers.

**Identifying Architecture Characteristics**

So both the architect and a developer need to be concerned about the functionality of an application. However, the architect has an additional requirement or responsibility. And that is to be concerned about the other kinds of aspects, the architectural characteristics of the application-- scalability, reliability, performance

Most of the time, these characteristics that we need to identify as architects do not come from requirements or user stories or epics. You know where they come from? They come from the business.

You're the architect. You are in charge of always analyzing the technology environment and recommending solutions for improvement. Remember, that was the second expectation we had as a software architect.

Feasibility. In other words, we start getting crazy about availability, performance, scalability. And we worry about all these things to make these perfect architectures, when, in fact, is it even feasible within our time frame and budget?

We receive what we call "requirements," when, in fact, they're actually solutions by product owners or business users. So the key point is this. Always challenge a requirement if you start to see that it gets too difficult. Always ask the underlying, why?

We might have some sort of problem. And it's like, well, microservices would fit that completely. Or event-driven architecture. And what we do as architects is we jump onto these solutions before really understanding our requirements.

**Analyzing Architecture Tradeoffs**

I want to show you two basic techniques for analyzing trade-offs of architecture characteristics. The first of those is a technique called ATAM-- Architecture Tradeoff Analysis Method. And what this does is it takes in several input. First of all, the proposed architecture that you have, the business drivers, and then third are those quality attributes-- in other words, scalability, reliability, and the qualifications of what kind of scalability, what kind of availability that you derived from. You go through this process, and what kind of spits out from it is a validated and approved architecture.

But one of the things we fail to do in most cases is identify the risk areas of our application, and this actually happens during the ATAM process. And not only during ATAM we identify those risk areas, but we also find ways to mitigate those risk areas.

And finally is to get that stakeholder buy-in, and this is an extremely important aspect of ATAM, or I should say, any architecture trade-off process. But this is where every stakeholder agrees to and buys in. And when I say stakeholder, that even includes the development community because they also are stakeholders. It's anyone that has a vested interest in the outcome of that particular project.

there's another technique that you can use, and that is called CBAM-- Cost-Benefit Analysis Method. And this takes a different approach because we have our architecture, and what it takes in are all the business drivers into that architecture. And this produces basically all of those system quality attributes, what I've been calling architecture characteristics-- availability, scalability, reliability-- and qualifies those. Now, these are actually deemed benefits within the application. You might think of those requirements, but CBAM treats those as benefits. However, the architecture has a cost associated with it. And so what CBAM does is instead of trying to do trade-off analysis between various architecture characteristics, what it does is it varies those based on cost. And what it tries to do is maximize the difference between cost and benefit of these.

**Understanding Layered Architecture**

it's a little different in that design patterns are typically only are talking about collaboration from classes, and there's a very simple structure. You don't have a lot of different kinds of moving parts. Architectural patterns are different, because you'll have different component types within an architectural pattern. Composeability works differently here. And so while the intent is the same, which is capture the essence of the structure of how these things fit together, they're used slightly differently from design patterns.

one of the huge advantages of something like a layered architecture is an additional characteristic that's quite common in this architecture, which is that you make each of these layers closed.

The primary one being getting all the like things together. So separation of concerns is the key motivator for this architecture.

The other side effect of this architecture is almost a side effect of this architecture, but also useful, which is these layers of isolation. Because these layers typically are isolated from one another and typically communicate through well-defined interfaces

And by creating an open layer in a layered architecture, what you're doing is saying, if there is value to be had by sending this request to the services layer, then I should. But if I'm not actually adding value there, then I can bypass that and go directly from the business layer to the persistence layer. And this solves the architecture sinkhole anti-pattern

if I want to change the persistence layer, is that easier if I have an open layer or more difficult if I have an open layer? Turns out it's more difficult. Because now, if I want to swap out the persistence layer, I have to worry about breaking both the services and the business layer, because they are both coupled to that persistence layer

the more you're throwing away the real benefit of this architecture. And that's something you have to pay really close attention to as an architect.

if you have a layered architecture and you constantly cheat on the layers and couple everything together, you don't really have a layered architecture anymore. You have a stylized big ball of mud architecture.

Agility -

Deployment -

Testability +

Performance -

Scalability -

Simplicity +

Cost 1

**Understanding Microkernel Architecture (plug-in architecture)**

But the microkernel architecture basically consists of a course system with plug in components. And these plug-in components can be either point to point. In some cases they might be utilizing OSGI. But in most cases, these form modular, or I should say monolithic, architecture styles.

That core system formally is defined as the minimal functionality used to run the system.

the plug-in modules contain either additional functionality or, more specifically, the volatile areas of the code.

I don't need to worry about any infiltration, which is why it's so necessary with this architecture pattern to make sure that you don't have any interdependency between the plug-in components.

there's two concepts that I need to really discuss that add some complexity to this architecture or this style. And the first of those is a registry. In other words, this core system here does have to have some sort of registry. And this is something that could be as simple as a little hash map or a map, or it could be as complex is a product. But essentially, as we start plugging in components, that registry is updated in terms of the knowledge that that component, or I should say the plug-in component exists and maybe also its location, (…) The other thing is, of course, contracts. And so every plug-n does need its own contract.

If we have a plug-in module coming in that's written from a third party or another team, it might have a different contract than what we're actually looking at in that particular case or accepting. And so in that particular case, what I would do is I would move that plug-in component aside and I would add an adapter in place to actually transform that contract to the standard contract in the core system, thereby minimizing changes in that area of the application. And that's in the spirit of really minimizing those changes to the core system with this architecture pattern.

A contract is really behavior, input, and output.

Agility +

Deployment +

Testability +

Performance -

Scalability -

Simplicity +

Cost 1

deployability is much more than just the ease of deployment. It also includes that risk of deployment, and with the microkernel architecture, what we try to do is keep that deployment, keep that change, that volatility, in those plug-in modules, which are much easier to test and a lower risk to deploy.

**Understanding Event-Driven Architecture**

we'll talk about two flavors of event-driven architecture, a broker topology and a mediator topology. Both of these share some common elements. They both have events and message queues as the plumbing for these systems

one of the huge advantages of an event-driven architecture is you could do things in parallel.

Let's talk about a couple of challenges that come up when you have an architecture like this. And one of them is error handling.

Error handling is harder, and evolution is easier

you build things where the parallelism is more important than the coordination headaches that come up.

We still have initiating events here that kick things off, and we still have event queues here. But we have a different architectural component available here as well, in this case, called an event mediator. And all requests go into this mediator, which in turn, will post messages to other message queues, which are then, in turn, wired to event processors to actually make stuff happen.

One of the key things, regardless of how you've implemented this mediator, is that all messages should go through the mediator, because that's where the business process is defined in this architecture

So one of the things the mediator does here is coordinate the calls to these other event processors to make sure transactionally that something happened or didn't happen.

This is Command Query Responsibility Separation, where the update only handles updates, and the queries only handle queries, which means that you don't have to worry about anyone updating your stuff while you're doing a query on it. And it separates those two functionalities, which potentially may simplify both sides of this equation, because you don't have to worry about one thing versus the other.

you have to also introduce a group of people who manage that mediator. This is traditionally integration architects. And once you have got an architecture that's built wholly around this mediator, those enterprise architects become a bottleneck in your organization because of Conway's Law. Conway's Law pretty much insists that this group of people will become a bottleneck in your organization, because now, every business process has to go through this group of people, which is also a kind of an odd way of partitioning up the functionality of your architecture

Agility +

Deployment +

Testability - (highly asynchronous systems)

Performance +

Scalability +

Simplicity -

Cost 3

**Understanding Pipeline Architecture (pipes and filters architecture)**

The pipeline architecture is also known as the pipes and filters architecture style, and really consists of two main core components, the filters and pipes.

The first are pipes. Now pipes in the pipeline architecture are usually uni-directional only.

Usually point-to-point (single deployment)

Payload can be any type (text, bytes, object, etc.)

these filters are self-contained and independent components from other filters. Like the micro kernel architecture with the plugin components that were standalone, these filters are standalone from each other. In other words, these filters are doing something with the data, and then sending it along to another filter.

Unusually designed to perform a single specific task.

Four filter types (producer, consumer, transformer, and tester)

Producer - starting, outbound only

Transformer - input, processing, output

Tester - input, discard or pass-thru

Consumer - ending point, inbound only

the pipeline architecture as you'll notice here is that it's highly evolutionary. Because again, these are usually single deployment units. In other words monolithic applications, but we've been able to split up that functionality into separate components, standalone components from each other

Pipeline vs event-driven

Synchronous data filtering vs asynchronous event processing

Always unidirectional vs can be request/reply

Simple single purpose filters vs complex multi-purpose processors.

Monolithic architecture vs distributed architecture.

Agility +

Deployment -

Testability +

Performance -

Scalability -

Simplicity +

Cost 1

you start to realize that many of the things that we use, whether they be languages, frameworks, tools, or products are, in fact, implemented on the underpinnings as this pipeline architecture another really powerful way of doing monolithic architectures but in a modular fashion.

**Understanding Space-Based Architecture**

vIt's actually getting rid of the database so that we can horizontally scale for hundreds of thousands to maybe even a million users, and that's exactly this architecture style. So let's take a look at this architecture.

this is the actual deployment unit, whether it be on-prem or whether it be cloud-based. And this processing unit actually contains your application-- that's what those modules are there.

that processing unit can be anywhere from your entire application to one small single purpose piece of that application.

Messaging grid : manages input requests and sessions

Data grid: manages data replication between processing units.

Processing grid: manages distributed request processing.

Deployment manager: manages dynamic processing unit deployment

Now I did mention that there is no database involved with this. Well, in truth, there usually is. However, that database is usually an asynchronous front loaded database through caching that's off to the side

Usually it's front loaded by a cache so that it can be stored and then forwarded to do the update on the database.

Now the reason why that's kind of necessary in this architecture style is because if all of the processing units went down.

So what we're trying to do is achieve high levels of scalability and elasticity, with avoiding the bottlenecks of the database, and that's exactly the premise and spirit of this architecture style.

there's something in space-based architecture we have to be worried about, and that's called data collisions

So you can start to see with this architecture, whether it's cloud-based or whether it's on prem, you will be asked, as an architect, how many instances can we have of each of these processing units up running in production.

It’s all about variable scalability.

Good for application that have variable load or inconsistent peak times.

Not a good fit for traditional large-scale relational database systems.

Agility +

Deployment +

Testability -

Performance +

Scalability +

Simplicity - (very complex)

Cost 4

**Understanding Microservices Architecture**

protocol-aware heterogeneous interoperability

What protocol-aware heterogeneous interoperability means is that protocol aware means the caller needs to know the protocol of the thing that it's calling.

Heterogeneous here means that disparate systems can communicate with one another. So as long as we agree on that protocol, then you could call from a dot NET system into a Java system or a Ruby system into a PHP system, as long as we agree on how we're going to integrate. And then interoperability, of course, is the ability for one thing to call other stuff.

It relies on a tremendous background of other capabilities that you have to have to be successful in this architectural style. One of the image tropes that we use for microservices is the common sign you see at carnivals, that you must be this tall before you start doing microservices. And this tall is really all these continuous delivery Agile engineering practices, things like machine provisioning, things like service discovery, things like really aggressive testing

part of the super power of this architecture is extremely decoupled deployment

communication is always point-to-point in this architecture, because while you see the diagrams of microservices typically utilizing this API layer, that is purely optional in this architecture

the idea of a service template is it is the substrate on which you build your service, so you extend from the service template and build whatever functionality you want in your service

one of the mantras you hear in this world is duplication is preferable to coupling

One of the pieces of advice that we give people when they're migrating to microservices is as soon as you utter the phrase, oh, we're going to need a distributed transaction here, you take one big step backwards. And that's the right level of granularity for your service, because while you may be forced into distributed transaction because of the extreme scale or something like that, it's a really, really hard problem to solve. And while distributed transactions are hard, distributed rollbacks are even harder

so that's the real purpose of microservices, is trying to find, what are the natural partitions of functionality within your system? What are the natural seams within your architecture and your business process? And that becomes the place you try to find how to partition things into service boundaries

Transactions are going to be one of the key things that you look at to try to determine how you stitch these things together, because you don't want to try to do transactions across microservices.

so one of the really common compromises in microservices is say, well, we really want that level of isolation, but it's extremely difficult or it's just not practical or pragmatic to do. And so it's not uncommon to stitch a few of these together at the data level like this, realizing that you have increased the coupling, which is generally frowned on here

We talked about allowing compromises to start creeping into that architecture, and that it really harms the reason you built that architecture to begin with. If you put all the time and effort into building this extremely decoupled set of services, in a microservice architecture, and then you bind them all together at the coupling point in the database, you're not getting a lot of the advantages of having all those microservices. But you're taking all the complexity of having all those microservices. So be careful of the ways you choose to compromise on an architectural style, because you may be building a bigger problem for yourself then choosing a different architectural style and not compromising, and actually building something that works better.

Events in this world can be either point-to-point synchronous or asynchronous. But it is really common to do asynchronous communication here between services. This is just like what we did in the event-driven architecture world. The difference here, though, is that we don't have event processors here. We have services. And those services encapsulate more code than event processors and are a little more designed around a bounded context.

Reporting techniques

Eventual consistency patterns

Performance tuning.

Reactive architecture patterns.

One of the really nice things about this architecture is because each one of these services is completely operationally isolated from all the others. So normally, when you try to ascertain architectural characteristics, like scalability or performance or auditability, you have to apply that to the entire architecture, because they're all coupled together in one way or the other. But notice, that's what we don't have in this architecture, is a lot of coupling between services. And so one of the benefits of this architectural style is if one of my services needs really ridiculously high scale, I can put the elastic scale and the scalability and all the facilities around resiliency, around just that service.

Agility +

Deployment +

Testability +

Performance - (so much latency)

Scalability +

Simplicity - (very complex)

Cost 3

**Understanding Service-Oriented Architecture**

The first of these is that service-oriented architecture really plays within the enterprise scope. Now microservices can play within enterprise or application scope, but service-oriented architecture really only plays in the enterprise scope.

one business service can be implemented by one-to-many enterprise services. And unlike microservices, there's nothing in SOA that says anything about the granularity or purpose of these services. So with microservices we have fine-grained single purpose services. But here, with service-oriented architecture, these could be as fine-grained as a couple of classes.

as you can see in summarizing this overall service taxonomy that there is a formal taxonomy. But more importantly, did you notice that each of these classification of services, which is fairly formal, are all owned by different teams-- business services owned by users, shared services teams owning the enterprise services, application teams owning the application services, and usually infrastructure teams owning those infrastructure services? A lot of coordination required within a service-oriented architecture kind of ecosystem,

And the very first of those is the fact of shared resources. And this was one of the first things that service-oriented architecture actually tried to solve.

Based on that messaging middleware, that ESP that sits kind of central to this whole architecture style is protocol transformation that allows me, in the middle there, as you can see, to make a service call in Java using AMQP, which is RabbitMQ messaging, to go all the way into C++ service using ATMI, and I don't have to care about what protocol that is. This is a very powerful concept of service-oriented architecture, as you can see, that supplies that heterogeneous integration across the enterprise to heterogeneous and disparate systems

one of the other capabilities that I just absolutely love with SOA, and that's this whole concept of contract decoupling. So contract decoupling is also solving a problem that we've had forever in our industry, and that is the tail constantly wags the dog. (…) the issue of IT driving the business.

Agility - (many stakeholders)

Deployment -

Testability - (low completeness)

Performance - (many layers)

Scalability +

Simplicity -

Cost 4

**Understanding Service-Based Architecture**

all sharing the same database context.

with service-based architecture, what we're really doing is taking portions of the application. We're finding seams through major sections of your application and splitting those up into separately deployed units. And so instead of having several hundred to several thousand services in service-based architecture, we have anywhere from maybe a half a dozen to a dozen.

Some people actually call these mesoservices, which is kind of interesting because meso is Latin for middle. So it's not quite as big as a monolith, but it's bigger than a microservice.

As a matter of fact, what we do have an opportunity for with service-based architecture, as you can see here, is to start to form these bounded contexts, even within service-based architecture

the fact that DevOps operational tools are not required for service-based architecture. They're nice to have. And as we start adding that level of automation, you can see what's happening. Slowly, over time, we're actually evolving the microservices ecosystem from an operational standpoint, that DevOps operational automation

what I want to do now is actually convince you that service-based architecture is absolutely the right way to move to microservices.

Jumping straight into microservices with the complexity of that architecture style with the DevOps environment and the operational tools and the organizational change and the complexity and the database splitting up is all a lot to handle.

Moving to service-based architecture first allows you to find those portions of the application that should be microservices, that should have that level of automation, the agility, the testability, the scalability, the deployability, the fault-tolerant aspects, while other portions of the application are just fine as a macroservice.

Agility +

Deployment +

Testability +

Performance -

Scalability +

Simplicity -

Cost 2

Serverless Architectures

Understanding LMAX

Because one of the things they realized, that one of the secrets to high performance in this kind of environment is keeping the footprint of the Java code and the bytecode very, very small. In fact, if you can keep the bytecode so small that it stays in the CPU's cache, that you never have to swap out any CPU stuff and you can get really, really high performance.

we've bumped into the other secret to super high performance in Java, never let the garbage collector run. And so they pre-allocated all the memory for the circular queue on startup, and then never had to reallocate any memory, and therefore the garbage collector never needed to run, so you never get garbage collector pauses which, of course, is the enemy of really, really fast transaction throughput speed

Because as architects, we so often focus on trade-offs, it's a little bit of a luxury to not have to worry about trade-offs and focus just maximally on one key thing, particularly when they had really good success like they did.

**Identifying and Creating Components**

Components

Building block of the application.

Well defined set of operations

Well defined role and responsibility

When we identify components, these really translate in those kind of architecture styles-- let's say we're using object oriented, either C# or Java. They really point to the package structure. So when we create a package structure, what we're effectively doing is creating a component, a building block of the application. Now, in some cases, though, the components scope within microservices because of the fine-grained nature. This is kind of one exception, here, in this rule is that the component generally does become the service itself.

Identify initial core components

(Cycle) Assign user stories to components

(Cycle) Analyze roles and responsibility statements.

(Cycle) Analyze non-functional aspect

(Cycle) refactor components as needed

Once we get a user story that doesn't really match up with anything or that we start to have double responsibility, that's when we create a new component.

Component coupling: the extent to which components know about each other.

Afferent coupling (static)

The degree to which other components are dependent on the target component.

Efferent coupling (static)

The degree to which the target component is dependent on other components.

Temporal coupling (non-static)

Components are coupled due to non-static or timing dependencies.

(Tight <-> loose)

Pathological coupling.

One component relies on the inner workings of another component

External coupling

Multiple components share an externally imposed protocol or data format

Ex) rest protocol between components.

Control coupling

One component passes information to another component on what to do.

Data coupling

The degree to which components are bound to a shared data context

generally, you will always be adding additional components to decouple your overall system.

Component cohesion

The degree and manner to which the operations of a component are related to one another.

what we want to achieve in all of our architectures is loose coupling and strong cohesion

like coupling, to form strong cohesion, generally, you will also add more components

My advice to you is this. As an architect, don't be overly reactive. In other words, when you start looking at coupling and cohesion, you want to start identifying these potential areas. For example, notify customer doesn't really have much to do with getting, updating, and deleting customers. But for right now, let's keep it in.

One of the first things teams usually do on greenfields is get together and say, OK, let's create all of our package structures. Well, in effect, that is really creating an architecture. So as an architect, you do want to pay attention to the number of packages being created in your applications. Because those, essentially, are components

**Documenting Software Architecture**

there's a really well known diagramming technique called 4+1 that was developed a few years ago that built four different views of architecture-- a logical view, a process view, a physical view, and a development view. And the goal here was try to slice a perspective through architecture that benefited one particular audience or set of constituents.

C4

System context : the system plus users and system dependencies.

-> business view

Containers: The overall shape of the architecture and technology choices.

-> operational view

Components: Components and their interactions within a container

-> developer view

Classes (of Code): Component implementation details.

-> developer view

Rules for documentation

1, useful now

2, As little as possible

3, Always accurate

4, Don’t try to capture the entirety of software architecture in a single diagram; create dimensional views instead.

Not all decisions made up front.

We will keep a collection of records for “architecturally significant” decisions: those that affect the structure, non-functional characteristics, dependencies, interfaces, or construction techniques.

ADR(Architecture Decision Records)

Title: short noun phrase

Context: forces at play

Decision: response to forces

Status: proposed, accepted, superseded.

Consequences: context after decision is applied.

The real trick to documenting software architecture is finding just the right level of detail to capture the essence of the analysis and the decision process, but not so much prose.

**Presenting Software Architecture**

**Analyzing Architecture: Macro Detection**

Structural decay symptoms.

1, complex and error-prone deployments.

2, hard for new people to learn code base.

3, code changes take longer than expected.

General structural decay indicators

1, Static coupling.

2, Temporal coupling.

3, component size

Microservice:

(1) code dependencies between services (shared libraries)

More code we start sharing between these from even a runtime or a compile time perspective means that we're starting to break that bounded context. And this is a form of structural decay. The more libraries you share, the less the architecture will actually work. You won't achieve high levels of agility, testability, deployability, or even scalability, availability-- basically any of the features of which you're using micros services for.

(2) Too much inter-service communication

If that service in the middle there fails, who's impacted? Pretty much all the services or a whole handful of them. And so we start to lose that fault tolerant aspect

(3) too many aggregation requests

(4) database coupling

Microkernel architecture

(1) Plug-in dependencies : The minute one plug-in depends on another plug-in for its functionality, this is a very large aspect of structural decay. The architecture simply will become one big ball of mud.

(2) volatility in core system.

(3) High complexity in core system.

what we're trying to do is take that cyclomatic complexity and move it out to these plug-in modules or the plug-ins. And so the point is if we start having that high level of complexity that means we're not leveraging this pattern

N-tiered layered

(1) Static cross-domain dependencies.

the key point is we want to try to minimize these static cross-domain dependencies. Every time we have a cross-domain dependency, this is within the layered architecture affecting those layers of isolation and also that ability to have that separation of concerns.

(2) Shared infrastructure components.

Service-based

(1) inter-service communication.

if you do have this it's a pretty good indicator within the service-based architecture that I haven't found the right appropriate level of seams or the right seams between that application or between those services.

(2) temporal component coupling

**Analyzing Architecture: Micro Detection**

1, cyclomatic complexity

- Provides a numeric value representing the complexity of a function or method.
- a cyclomatic complexity level of 3 to me is fairly meaningless. What we're going to be looking for, though, is the trend. Does it increase? Does it decrease? Does it stay the same? So let's take a look at some other kinds of core metrics that allow us to find some structural decay.
- Core metrics
- Number of classes per package
- Number of lines of source code per package
- Percent comments (range: 8-20)
- Max complexity (1+ num_paths thru method; range: 2-8%)
- Average complexity (range: 2.0 - 4.0)

Chidamber & Kemerer metrics.

- DIT (depth of inheritance tree)
- WMC (weighted methods/class; sum of CC)
- CE (efferent coupling count)
- CA (afferent coupling count)

If we take component size and map it to what impact does component size have on our architecture from these structural aspects, the answer is all of them. The larger the component, the less modular our architecture is. The larger the component, less maintainable, less testable, less available. So all of these aspects of our architecture, all these structural aspects basically are impacted by the component size.

Complexity -> maintainability, testability, reliability.

Coupling impacts everything. (…) The larger the component, generally, the higher level of coupling that we'll have. But coupling is absolutely a death knell in any architecture. That tight coupling produces testability issues, availability issues. You can see every one of these aspects

Inheritance depth -> modularity, maintainability, testability, deployment, reliability, migration(evolutionary)

the higher that death of inheritance tree, the harder it's going to be to find those seams, to find that level of modularity and break apart that monolith.

Percent comments - maintainability, testability, reliability

what we don't want to do as an architect is to be too reactive with these metrics.

the best way to do that that I have found is to analyze the trends.

**Understanding Architectural Continuous Delivery**

one of the things that continuous delivery taught us is that architecture's abstract until it's operationalized

the first new perspective that continuous delivery has brought to architecture is that you can't treat operations as this separate thing. This is part of architecture now, particularly for modern architectures. They assume that you have good control of operations and can do automatic machine provisioning and automated deployments. And so we have a much broader perspective on things now

before the continuous delivery world and before the DevOps revolution, architects mostly held purview over the engineering group, and very often siloed away from other roles like DBAs and operations. But because CD has forced us to consider all these things you can't really do continuous delivery if you can't get your data and DBAs into a continuous feedback loop.