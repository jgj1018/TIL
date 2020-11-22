
# 1. What Is Domain-Driven Design?


## The Challenges of Creating Software for Complex Problem Domains

- One of the main reasons software becomes complex and difficult to manage is due to the mixing of domain complexities with technical complexities.

- Code without a binding to an analysis model that the business understands will degrade over time and is therefore more likely to result in an architecture that resembles the BBoM pattern.

- Ultimately the BBoM is bad news for you as a developer because it’s a messy bug-prone code base that you hate dealing with. And it’s bad news for the business because it reduces their capability to rapidly deliver business value

-  coding is the easy part of development. Outside of non-functional requirements creating and keeping a useful software model of the domain that can fulfill business-use cases is the difficult part. However, the more you invest in understanding your business domain the better equipped you will be when you are trying to model it in software to solve its inherent business problems.

## How the Patterns of Domain-Driven Design Manage Complexity

- Development teams and domain experts use analysis patterns and knowledge crunching to distill large problem domains into more manageable subdomains. This distillation reveals the core sub domain—the reason the software is being written.

- This clarity on where to focus effort can also empower teams to look for open source off-the-shelf solutions for some of the less important parts of a system

- Models sit within a bounded context, which defines the applicability of the model and ensures that its integrity is retained. Larger models can be split into smaller models and defined within separate bounded contexts where ambiguity in terminology exists or where multiple teams are a working in order to further reduce complexity.

- Areas of low complexity or that are unlikely to be invested in can be built without the need for perfect code quality; working software is good enough. Sometimes feedback and first-to-market are core to the success of a product

## The Practices and Principles of Domain-Driven Design

- A breakthrough in the analysis model results in a change to the code model. A refactoring in the code model that reveals deeper insight is again reflected in the analysis model and mental models of the business

- the single most important facet of DDD is the creation of the UL. Without a shared language, collaboration between the business and development teams to solve problems would not be effective.

- DDD is still no silver bullet and requires dedication and constant knowledge crunching to produce software that is maintainable for years and not just months. New business cases may break a previously useful model, or may necessitate changes to make new or existing concepts more explicit

## Popular Misconceptions of Domain-Driven Design

- DDD is less about software design patterns and more about problem solving through collaboration.

- DDD is not code centric; its purpose is not to make elegant code. Software is merely an artifact of DDD.

## The Salient Points

- Domain-Driven Design (DDD) is a development philosophy that is designed to manage the creation and maintenance of software written for complex problem domains.
- DDD is a collection of patterns, principles, and practices, which can be applied to software design to manage complexity.
- DDD has two types of patterns. Strategic patterns shape the solution, while tactical patterns are used to implement a rich domain model. Strategic patterns can be useful for any application but tactical patterns are only useful if your model is sufficiently rich in domain logic.
- Distillation of large problem domains into subdomains can reveal the core domain—the area of most value. Not all parts of a system will be well designed; teams must invest more time in the core subdomain(s) of a product.
- An abstract model is created for each subdomain to manage domain problems.
- A ubiquitous language is used to bind the analysis model to the code model in order for the development team and domain experts to collaborate on the design of a model. Learning and creating a language to communicate about the problem domain is the process of DDD. Code is the artifact.
- In order to retain the integrity of a model, it is defined within a bounded context. The model is isolated from infra
structure concerns of the application to separate technical complexities from business complexities.
- Where there is ambiguity in terminology for a model or multiple teams at work the model can be split and defined in smaller bounded contexts.
- DDD does not dictate any specific architectural style for development, it only ensures that the model is kept isolated from technical complexities so that it can focus on domain logic concerns.
- DDD values a focus on the core domain, collaboration, and exploration with domain experts, experimentation to produce a more useful model, and an understanding of the various contexts in play in a complex problem domain.
- DDD is not a patterns language, it is a collaboration philosophy focused on delivery, with communication playing a central role.
- DDD is a language- and domain-centric approach to software development.

# 2. Distilling the Problem Domain

- Continuous experimentation and exploration in the design of a model is where the power of DDD is realized. Only through collaboration and a shared understanding of the problem domain can you effectively design a model to solve the challenges of the business that will be supple enough to adapt as new requirements surface.

 ## Knowledge Crunching and Collaboration

- Knowledge crunching is the art of distilling relevant information from the problem domain in order to build a useful model that can fulfill the needs of business use cases.

- An output of knowledge crunching and an artifact of the shared understanding is a common Ubiquitous Language (UL)

- This language must be made explicit and be used when describing the domain model and problem domain. The language should also be used in the code implementation of the model, with the same terms and concepts used as class names, properties, and method names.

- If you can’t speak to your business users in simple terms about complex concepts in the problem domain, you are not ready to start developing software within it.

- Knowledge crunching is an ongoing process; teams should continually be working toward a simple view of the problem domain that focuses only on the relevant pieces to aid the creation of a useful model. 

- it is important for the technical team and the business experts to understand that the model is never done; it is only useful for the problems at hand.

## Gaining Domain Insight with Domain Experts

- A problem space gives you a set of requirements, inputs, and expected outputs—this is usually provided from your stakeholders. A solution space contains a model that can meet the needs of the requirements—this is where domain experts can help.

## Patterns for Effective Knowledge Crunching

- Start with the areas of the problem domain that keep the business up at night—the areas that will make a difference to the business and that are core for the application to be a success. For example, asking the domain experts which parts of the current system are hard to use, or which manual processes stop them from doing more creative, value-adding work.

- Naming is important when modeling a domain. However, premature naming can be a problem when you discover through further knowledge crunching that concepts turn out to be different from what you first understood them to be. (...) When you feel you have really understood a part of the model, you will be in a better place to give it a sensible and meaningful name.

- Much like DDD, BDD does not focus on the technical aspects of an application. Where it differs is that BDD focuses on the software behavior, how the system should behave, whereas DDD focuses on the domain mo

- business users will love the fact that you are writing and creating before their eyes. Starting to code will help focus analysis sessions.

- Remember: Only create a code model of what is relevant and within the specific context to solve a given problem; you can’t effectively model the entire domain. Think small and model around rules; then build up. Most important, remember that you are writing throw-away code. Don’t stop at the first useful model, and don’t get too attached to your first good idea.

- You won’t get a useful model on the first attempt; you might not even get one on the second or third attempts. Don’t be afraid of experimentation. Get used to ripping up designs and starting over.

- Be wary of customers asking for enhancements to existing software, because they will often give you requirements that are based on the constraints of the current systems rather than what they really desire. 

- You are the enabler. Don’t blindly follow the user’s requirements. Business users may not be able to write effective features or effectively express goals. You must share and understand the underlying vision and be aware of what the business is trying to achieve so you can create real business value.

## Look For Existing Models

- Event Storming is a workshop activity that is designed to quickly build an understanding of a problem domain in a fun and engaging way for the business and development teams

- The problem domain is explored by starting with a domain event; i.e., events that occur within the problem domain that the business cares about. A Post-it note representing the domain event is added to the drawing surface and then attention is given to the trigger of that event. An event could be caused by a user action that is captured and added to the surface as a command. An external system or another event could be the originator of the event; these are also added to the canvas. This activity continues until there are no more questions. The team can then start to build a model around the decision points that are made about events and when they, in turn, produce new events.

- One of the best ways to learn about a company’s business model is to visualize it using a Business Model Canvas. (...) Understanding the nine building blocks of a business model tells you what is important to the business.

- Customer Segments—the different types of customers a business targets. Examples include niche markets, mass markets, and business-to-business (b2b).
- Value Propositions—the products or services a business offers to its customers. Examples include physical goods and cloud hosting.
- Channels—how the business delivers its products or services to customers. Examples include physical shipping and a website.
- Customer Relationships—the types of relationships the business has with each customer segment. Examples include direct personal assistance and automated electronic help facilities.
- Revenue Streams—the different ways the business makes money. Examples include advertising revenue and recurring subscription fees.
- Key Resources—a business’s most important assets. Examples include intellectual property and important employees.
- Key Activities—the activities fundamental to making the business work. Examples include developing software and analyzing data.
- Key Partnerships—a list of the business’s most significant partners. Examples include suppliers and consultants.
- Cost Structure—the costs that the business incurs. Examples include salaries, software subscriptions, and inventory.

- Significant scenarios that help demonstrate the model should be captured in documentation. Key scenarios will form the reference scenarios, which will demonstrate how the model solves key problems within the problem domain. Business scenarios will change less often than the model so it is useful to have a collection of important ones as a reference for whenever you are changing the model. However, don’t try and capture every design decision and every model; some ideas should be left at the drawing board.

## The Salient Points

- Knowledge crunching is the art of processing domain information to identify the relevant pieces that can be used to build a useful model.
- Knowledge is obtained by developers collaborating with domain experts. Collaboration helps to fill any knowledge gaps and fosters a shared understanding.
- A shared understanding is enabled through a shared language known as the ubiquitous language (UL).
- Knowledge crunching is an ongoing process; collaboration and engagement with the business should not be constrained to the start of a project. Deep insights and breakthroughs only happen after living with the problem through many development iterations.
- Knowledge is gained around whiteboards, water coolers, brainstorming, and prototyping in a collaborative manner, with all members of the team at any time of the project.
- Domain experts are the subject matter experts of the organization. They are anyone who can offer insight into the problem domain (users, product owners, business analysts, other technical teams).
- Your stakeholders will give you the requirements of your application but they may not be best placed to answer detailed questions of the domain. Utilize domain experts when modeling core or complex areas of the problem domain.
- Engage with your domain experts on the most important parts of a system. Don’t simply read out a list of requirements and ask them to comment on each item.
P- lan to change your model; don’t get too attached as a breakthrough in knowledge crunching may render it obsolete.
- When working with domain experts focus on the most important parts of the problem domain; put most effort into the areas that will make the application a success.
- Drive knowledge crunching around the most important uses case of the system. Ask the domain experts to walk through concrete scenarios of system use cases to help fill knowledge gaps.
- Ask powerful questions and learn the intent of the business. Don’t simply implement a set of requirements but actively engage with the business; work with them, not for them.
- Visualize your learning with sketches and event storming techniques. Visualizing a problem domain can increase collaboration with the business experts and make knowledge-crunching sessions fun.
- Use BDD to focus on the behavior of the application and focus domains experts and stakeholders around concrete scenarios. BDD is a great catalyst for conversations with the domain experts and stakeholders. It has a template language to capture behavior in a standard and actionable way.
- Experiment in code to prove the usefulness of the model and to give feedback on the compromises that a model needs to make for technical reasons.
- Look at existing processes and models in the industry to avoid trying to reinvent the wheel and to speed up the gaining of domain knowledge.
- Find out what you don’t know, identify the team’s knowledge gaps early then activate deliberate discovery. Eliminate unknown unknowns and increase domain knowledge early.
- Leverage Eric Evans’ Model Exploration Whirlpool when you need guidance on how to explore models. The activities in the whirlpool are particularly helpful when you are having communication breakdowns, overly complex designs, or when the team is entering an area of the problem domain of which they don’t have much knowledge.


# 3. Focusing on the Core Domain

- During knowledge crunching with domain experts, it’s important to reduce the noise of what’s unimportant to enable you to focus on what is important. Model-Driven Design is hard and should only be reserved to the areas of your systems that are vital to its success.

## Why Decompose a Problem Domain?

- In order to understand the most valuable areas of a problem domain we need to distill it to reveal what is core. By breaking up the large problem domain we can more effectively resource the different areas to ensure the most talented developers are working in the areas of most importance to the business rather than the areas that may be more technically challenging or that utilize new frameworks of infrastructure.

- DDD is all about reducing complexity; a single monothlic model would increase complexity. Instead you should break the problem domain down so that you are able to create smaller models in the solution space.

## How to Capture the Essence of the Problem

- To know where to focus effort you need to understand what makes the application worth designing in the first place. You need to understand the business strategy and why the existence of the software you are creating will enable it. It is worth asking why the custom software is being written rather than opting for a commercial off-the-shelf product. How will building an application make a difference to the business? How does it fit within the strategy of the company? Why is it being built in-house rather than being outsourced? Does part of the software give the business a competitive edge?

- A domain vision statement can be created at the start of a project to explicitly capture what is central to the success of the software, what the business goal is, and where the value is. This message should be shared with the team and even stick it up on a wall in the office as a reminder to why the software is being written.

- For new enhancements, a product manager produces an internal press release announcing the finished product, listing the benefits the feature brings. If the intended customer doesn’t feel the benefits are exciting or worthwhile, the product manager refactors the press release until the feature offers real value for the customer. At all times, Amazon is focused on the customer and is clear about the advantage a new feature can bring before it sets out with development.

- Understanding the subdomains of your system enables you to break down the problem space. Subdomains are abstract concepts; don’t get subdomains confused with the organizational structure of a company. 

- Try not to bring technical concerns into conversation when you are analyzing the problem space. Security is a technical concern unless your problem space is security.

- The areas that distinguish your company’s unique product offering from a rival’s and define what gives it a competitive edge in the market are known as your core domains. 

- The core domains require your best developers—your commandos, if you will. The core domains may not make up the lion’s share of your company’s technology, but they require the most investment

- What is core certainly changes over time. If you are successful, competitors mimic, so the core domain must evolve to set your business apart from the rest and keep it ahead of the game. 

- A generic domain is a subdomain that many large business systems have. An example of a generic domain is an e-mail sending service, an accounts package, or a report suite. These subdomains aren’t core to the business, but the business can’t operate without them

-  Because these subdomains aren’t core and won’t give you a competitive edge, it doesn’t make sense to spend a lot of effort or investment in building them. Instead, look to buy in software for generic domains. Alternatively, use junior developers to build these systems, freeing up more experienced resources to work on what’s core to your business.

- The remaining subdomains in the system are defined as the supporting domains. These are subdomains that, although not defining what your system does, help to support your core domains. As with the generic domains, if possible, you should look to buy off-the-shelf solutions

- It’s important to note that you may not always need to implement a technical solution to a supporting domain. Perhaps a manual process could meet the needs of the business while developers focus on the core domain.

## Not All Parts of a System Will Be Well Designed

- Don’t waste time and effort on refactoring all of your code—ensure your primary focus is on the core domain. If you end up with working but “messy code” for supporting and generic domains then leave it alone.

- Leaving small silos of BBoM is fine as long as they are within clearly defined boundaries. Perfection is an illusion. Perfection should be reserved for only what is core. The business doesn’t care about quality code for areas that are required but are not key to the system and which are unlikely to be invested in over time.

- If you have areas of an application that resemble the BBoM pattern then the best thing to do is to put a boundary around them to prevent the mud spreading into new areas of the application

- In an ideal world, quality software would always be top of your agenda; however, it’s important to be pragmatic. Sometimes a new system’s core domain could be first to market, or sometimes a business may not be able to tell if a particular idea will be successful and become core to its success. In this instance, the business wants to learn quickly and fail fast without putting in a lot of up-front effort.

- The first version of a product that is not well understood by the business may not be well crafted. This is fine, because the business is unsure if it will be invested in over time, and the development team should understand why the business wants speed of delivery over supple design. However, if the product is a success and there is value in a prolonged investment in the software, you need to refactor to support the evolution; otherwise, the technical debt racked up in the rush to deliver starts to become an issue.

- When developing models in subdomains try and build them in isolation with replacement in mind. Keep them separated from other models, legacy code, and third party services by using clean boundaries.

## What If You Have No Core Domain?

- If you find that the software you are building is all generic or is supporting other applications in your enterprise and therefore you have no core domain then don’t try and apply all of the practices and principles of DDD to your project. You can still benefit from following the strategic patterns of DDD but the Model-Driven Design tactical patterns could be wasted effort. 

## The Salient Points

- Distillation is used to break down a large problem domain to discover the core, supporting, and generic domains.
- Distillation helps reduce complexity within the problem space.
- Focus and effort should be invested on the core domain. Use your best developers here.
- The core domain is the reason you are writing the software.
- Consider outsourcing, buying in, or putting juniors on the supporting and generic domains.
- A domain vision statement reveals a shared understanding of what is core to the success of a product. Use domain experts, project initiation documents, and business strategy presentations to help inform the domain vision statement.
- Plan to change the model within the core domain as you learn more about the problem. Don’t get too attached to a solution—your core domain may change over time.
- Not all of a system will be well designed. Focus effort on the core domain. For legacy BBoM systems define an anti-corruption boundary to avoid new code becoming tangled within the mess of old.

# 4. Model-Driven Design

- it is important to implement in code the analysis model that was produced during knowledge-crunching sessions; i.e., the model that the business understands. 

- DDD acknowledges the need to produce a single model that serves as an analysis model for business people to understand and which is implemented using the same terminology and concepts in code.

- This process is known as Model-Driven Design and is heavily dependent on Ubiquitous Language to tie the technical implementation of the model to the analysis model and keep them in sync throughout the lifetime of the system.

## What Is a Domain Model?

- The domain model, (...) is at the center of Domain-Driven Design (DDD). It is formed first as an analysis model through the collaboration between a development team and business experts during knowledge-crunching sessions. It represents a view, not the reality, of the problem domain designed only to meet the needs of business use cases. 

-  Its usefulness comes from its ability to represent complex logic and polices in the domain to solve business use cases. The model contains only what is relevant to solve problems in the context of the application being created. It needs to constantly evolve with the business to keep itself useful and valid.

- The domain represents the problem area you are working within. It is the firm reality of the situation. The domain model, on the other hand, is an abstraction of the problem domain, expressed as a code implementation that represents a view, not the reality, of the problem. 

- The usefulness of the domain model comes in its ability to represent complex logic and polices in the domain to solve business problems and not how well it reflects reality.

- The model is built from the collaboration between the development team and the business experts. The model contains only what is relevant to solve problems in the context of the application being created. It needs to constantly evolve with the business to keep itself useful and valid. The domain model only exists to help us solve problems; in order to be effective it needs to have clarity and be free of technical complexities. This way both the business and development teams can collaborate on its design.

## Model-Driven Design

- Model-Driven Design is the process of binding an analysis model to a code implementation model, ensuring that both stay in sync and are useful during evolution. 

- Model-Driven Design differs from DDD in that it is focused on implementation and any constraints that may require changes to an initial model, whereas DDD focuses on language, collaboration, and domain knowledge.

- The two complement each other; a Model-Driven Design approach enables domain knowledge and the shared language to be incorporated into a software model that mirrors the language and mental models of the business experts.

- The important aspect of modeling together is the constant feedback the development team gets from the business experts.

- the development team members may come across parts of the model that they thought were useful and could solve a problem but during implementation had to change. This knowledge is fed back to the business experts for clarification and to refine their own understanding of the problem domain. In this process, the code model and analysis model are one, and a change in one will result in a change to the other.

## Using a Ubiquitous Language to Bind the Analysis to the Code Model

- The true value of following the Domain-Driven Design (DDD) philosophy is in the collaboration of developers and domain experts to produce a better understanding of the domain.

- A UL enables teams to organize both the mental and the code model with ease.

- The usefulness of creating a UL has an impact that goes beyond its application to the current product under development. It helps define explicitly what the business does, it reveals deeper insights into the process and logic of the business, and it improves business communication.

## Collaborating on a Ubiquitous Language

-  when creating a model of the problem domain and implementing it in code, you may need to create new concepts and terminology. The business may use jargon much in the same way that the IT community does, with some terms proving to be too generic. The development team and domain experts need to create new terms and explicitly define the meaning of existing terms to implement the model in code.

- The team members must communicate with each other using the UL. The development team must use it in code, and the domain experts must use it when talking to the team


- The following best practices can help to shape your UL.

- Ensure that you have linguistic consistency. If you are using a term in code that the domain expert doesn’t say, you need to check it with her. It could be that you have found a concept that was required, so it needs to be added to the UL and understood by the domain expert. Alternatively, maybe you misunderstood something that the domain expert said; therefore, you should rectify the code with the correct term.
- Create a glossary of domain terms with the domain expert to avoid confusion and to help make concepts explicit.
- Ensure that you use one word for a specific concept. Don’t let the domain expert or developers have two words for something because this can lead to confusion, or there might be two concepts with different contexts.
- Stay away from overloaded terms like policy, service, or manager. Be explicit even if it means being wordy.
- Don’t use terms that have a specific meaning in software development, such as design pattern names, because developers may assume its implementation rather than behavior.
- Naming is very important. Validate your code design by speaking to your business users about classes. Would a business user understand “Query sent to the cache with, users matched using regex to determine if they get discount”. Does your code and concepts make sense when you say them aloud? If not ask your domain expert on how they would name concepts.
- Name exceptions in terms of the UL.
- Don’t use the name of a design pattern within your domain model. What does a decorator mean to a business user? Would they understand the role of a factory? Perhaps your business already has the concept of an adapter; the Gang of Four design pattern could confuse them.
- The UL should be visible everywhere, from namespaces to classes, and from properties to method names. Use the language to drive the design of your code.
- As you gain a deeper understanding of the domain you are working in, your UL will evolve. Refactor your code to embrace the evolution by using more intention-revealing method names. If you find a grouping of complex logic starting to form, talk through what the code is doing with your domain expert and see if you can define a domain concept for it. If you find one, separate the logical grouping of code into a specification or policy class.

## How to Create Effective Domain Models

- Rich domain models are built to satisfy complex problems, the best way to create effective domain models is to firstly focus on areas of the application that are important to the business. Ignore the parts of a system that simply manage data and where most of the operations are CRUD based. Instead look for the hard parts, the areas in the core domain that the business cares passionately about and often the parts that are key to making or saving money.

- A common misunderstanding is that a domain model should match reality; in fact, you should not look to model real life at all but rather model useful abstractions within the problem domain.

- A domain model is not a model of real life; it is a system of abstractions on reality, an interpretation that only includes aspects of the problem domain that are prevalent to solving specific business use cases. A domain model should exclude any irrelevant details of a domain that do not serve to solve problems. 

- Having a useful model that is rich in the UL is the key to meeting business objectives in the problem domain. Creating a useful domain model is hard and takes lots of exploration, experimentation, collaboration, and learning.

- The domain model exists for one reason: to serve the application under development.

- Remember that you are producing a model to fulfill the needs of a business use case (or set of business use cases), not trying to model real life.

- Remove any behavior that is no longer relevant to avoid noise.

-  It is really important to limit abstractions in your code base and only create them for concepts in your domain that have variations. Don’t seek to abstract every domain concern.

- Remember it is always better to be explicit rather than hiding an important domain concept behind layers of needless abstraction.

## Focus Your Code at the Right Level of Abstraction

- An effective domain model should express the intent of the business use case by aiming code at the right level of abstraction.

- At a low level we should avoid abstraction and instead favor composition of behavior from explicit concrete objects. Abstraction creates a dependency between classes and more dependencies equate to higher code coupling.

- When they do and you find variations of the concept then you can introduce abstractions in the form of interfaces or abstract classes.

- Technical implementations will reveal any problems with the design and will help cement your understanding of a problem domain.

- If you don’t get it right the first time, refactor to a better solution. Constantly refactor to your understanding of the problem domain to produce a more express model. Models will change with more knowledge.

## When to Apply Model-Driven Design

- Simple problems don’t require complex solutions. You don’t need to create a UL for your entire application. Focus your efforts with domain experts on the complex or important core domain.

- Always challenge yourself and ask the questions, “Am I working within the core subdomain? Does this problem require a rich domain? Does the business care about this area of the application? Will it make a difference? Is it important to the business and do they have high expectations of it or do they just want it to work?”

- Try not to create a rich language for your entire domain because many of your supporting and generic domains do not require one and are a waste of effort. Focus your efforts on what gives you value. Try not to create a UL for everything. Areas and subdomains that are not complex will not benefit from a UL, so don’t spread yourself too thin. A core domain is small; focus on it. Creating a UL is costly.

## The Salient Points

- The domain is the reality of the problem. The domain model is a set of abstractions based on a projection of the domain designed to handle specific business use cases.
- A model is represented as an analysis model and a code model. They are one and the same.
- A domain model exists as an analysis model and a code model. A Model-Driven Design binds the analysis model and a code model through the use of the shared language.
- An analysis model is only useful if it stays in synergy with the code model.
- If you are shaping the analysis or code models, you have to be hands-on and contribute to code. There is a place for architects, but they must be coders as well.
- Code is the primary form of expression of the model and needs to be bound using the ubiquitous language.
- The process of developing a UL is the most important of Domain-Driven Design (DDD) because it enables communication and learning.
- Domain jargon must be explicitly defined to ensure accuracy in meaning because the terminology used in communication is baked into the code implementation.
- Implicit ideas in the domain that the team needs to understand are made explicit and given names that form the shared ubiquitous language.
- Domains are full of specialist terms and language that describe complex concepts in a clean, concise manner.
- Feature stories and scenarios can help you understand the behavior of a system, but a domain expert will help you build a model that can support the specified behavior.
- The ubiquitous language should be used in tests, namespaces, class names, and methods.
- It’s important to care about the conversation; a ubiquitous language is about collaboration and not the development team just adopting the language of the business.
- Use domain scenarios to prove the usefulness of the model and to validate the team’s understanding of the domain.
- Only apply Model-Driven Design and create a UL for a core domain that will make a difference. Don’t apply these practices to the entire application.

# 5. Domain Model Implementation Patterns

## The Domain Layer

- The domain layer, at the heart of your application, is the area of code that contains your domain model. It isolates the complexities of the domain model from the accidental technical complexities of the application. It is responsible for ensuring that infrastructure concerns, such as managing transactions and persisting state, don’t bleed into the business concerns and blur the rules that exist in the domain. In most cases, the domain layer makes up only a small part of your application

- By not thinking about persistence needs, you can build an expressive model purely focused on the domain problem at hand. Of course you will need to persist it and may need to compromise, but you should not think about this when modelling. This keeps the domain model free of infrastructural code and focused only on domain logic.

- The domain model pattern is no silver bullet as it can be costly to implement. It’s the most technically challenging and requires developers with a good grasp of object-oriented programming.

- What you should not do is try to apply the domain model pattern for everything. 

- If the portion of the application you are working on does not have frequently changing logic and is merely a form of data, it is best not to try to apply the domain model pattern.

- The transaction script pattern follows a procedural style of development rather than an object-oriented approach.

- Transaction script is a simple procedural pattern that is useful for the parts of your domain that have little or no logic

- The problems with the transaction script pattern are revealed when an application grows and the business logic complexities increase. 

- The table module pattern maps the object model to the database model. A single object represents a table or view in the database. The object is responsible for all persistence needs along with business logic behavior.

- for simpler parts of the domain that are isolated by a bounded context and that are simply forms over data, this pattern is a good fit and easier to come to grips with than the domain model pattern. 

- Active record is a variation of the table module pattern that maps objects to rows of a table as opposed to having objects represent the tables themselves.

- The active record pattern is a popular pattern that is especially effective when your underlying database model matches your business model. 

- In the active record pattern, each business object is responsible for its own persistence and related business logic.

## The Salient Points

- The domain layer contains the model of the domain and is isolated from infrastructure and presentation concerns.
- The domain model can be implemented with multiple domain logic patterns.
- There may be more than one model at play on a large project and therefore more than a single pattern to represent domain logic.
- As long as the pattern isolates code representing domain logic from technical code then it is a good fit for DDD.
- The domain model pattern is a good fit for a complex problem domain. Concepts in the domain are encapsulated as objects containing both data and behavior.
- The transaction script pattern organizes all domain logic to fulfill a business transaction or use case in a procedural module.
- The table module pattern represents your data model in object form. The Table Module is useful for data-driven models that closely reflect the underlying data schema.
- The active record pattern is like the table module pattern in that it is data-driven but it represents rows in tables as opposed to the tables themselves. It’s a good fit for low complexity logic but high CRUD-based models.
- An anemic model is similar to the domain model pattern; however, the model is devoid of any behavior. It is purely a model of the state of an object all behavior resides in service classes that modify.
- Functional programming is an equally valid approach to building domain models.
- When using functional programming, behaviors can be grouped into aggregates (that represent domain concepts) and applied to pure, immutable data structures (that also represent domain concepts).

# 6. Maintaining the Integrity of Domain Models with Bounded Contexts

- with each implementation using an appropriate code design pattern suitable for the complexity of the problem. Ideally you will have a model for each subdomain; however, this might not always be the case as some complex subdomains could contain more than a single model and some models could span two or more subdomains. No matter how many models you have you will find that they will need to interact to fulfill the behaviors of a system. 

- it is vital to protect the integrity of each model and clearly define the boundaries of their responsibility in code. This is achieved by binding a model to a specific context, known as a bounded context.

## The Challenges of a Single Model

- One of the epiphanies that DDD practitioners have is the realization that some concepts in a system are very similar—they might even have the same name. Yet actually, they mean very different things to different parts of the business. 

- When a physical entity, such as a product, actually represents multiple domain concepts, it is often modeled as a single concept by developers. Unfortunately, it’s very easy to fall into the trap of thinking that because a product can be a physical item that it should be modeled as a single class in code. This leads to coupling, as each model shares the same product class

- when multiple contexts are coupled, code can become excessively complex and the collaboration overhead between teams can become excessively costly. The shared class, in this example product, also violates the Single Responsibility Principle (SRP), since there are four contexts that all want it to change for completely different reasons.

- A better solution that reduces the coupling would be for each context—Promotion, Allocation, Loyalty, and Shipping—to have its own model. Each model would then contain a unique representation of a product that only satisfies the needs of the model’s context.

- Another reason to prefer smaller models is that integrating with legacy code or third parties can be less problematic.

- Having a single model of the entire system is useful in some scenarios, including business information (BI) and reporting.

## Use Bounded Contexts to Divide and Conquer a Large Model

- A bounded context defines the applicability of a model. It gives clarity on what a model is used for, where it should be consistent, and what it should ignore. 

- Each model has a context implicitly defined within a subdomain. 

- The context defines the scope of the model, limiting the boundaries of the problem space, enabling the team to focus without distractions.

- The bounded context enforces communication in such a manner as to not lessen the purity of the model.

- A bounded context is first and foremost a linguistic boundary. When talking with domain experts, if you feel a sentence requires a context, this is a big hint that you need to isolate that model within a bounded context.

- Treat bounded contexts like the borders of a country. Nothing should pass into the bounded context unless it goes through the border control and is valid. Just like countries where people speak a different language, so does the code within your bounded context. 

- One of the most important parts of DDD is the protection of boundaries. A model is defined in a context. This should be followed through to the implementation in the code; otherwise, you will find yourself in a BBoM. 

-  It is important when developing the application that you isolate models within bounded contexts to avoid the blurring of responsibilities that can lead to code that resembles a BBoM.

- Business capabilities are often easy to discern but can be misleading. For example, if a business has a Sales department and a Customer Service department, there is very likely to be a sales and customer bounded context. But that’s not always true, so it’s important not to blindly model business capabilities.

- No absolute or relative value can tell you how many classes or lines of code you need. A bounded context’s size is dependent mostly on aspects of the problem domain. 

- context boundaries can be influenced by the following:

- Ambiguity in terminology and concepts of the domain
- Alignment to subdomains and business capabilities
- Team organization and physical location
- Legacy code base
- Third party integration

- multiple models will be at play in your domain. You need to enforce linguistic boundaries to protect the validity of a domain term. Therefore, linguistic boundaries are bounded context boundaries. 

- An organization is an ecosystem of interdependent services, each with its own vocabulary. Hence business capabilities are often strong indicators of linguistic boundaries. 

- What actually is a business capability? A business capability is a grouping of people in an organization that collaborate on business processes made up of lower-level capabilities.

- The main rationale for aligning teams with bounded contexts is that independence allows teams to both move faster and make better decisions. 

- communication between teams is sometimes a good thing, so don’t completely avoid it; just limit it to when it’s useful. One example of useful cross-team communication is knowledge and skill sharing.

- Unlike a subdomain, a bounded context is a concrete technical implementation that enforces boundaries between models within an application. Bounded contexts exist in the solution space and are represented as explicit domain models in a context.

## The Salient Points

- Trying to use a single model for a complex problem domain will often cause code to result in a Big Ball of Mud.
- A monolithic model increases collaboration overhead amongst teams and reduces their efficiency at delivering business value.
- For each model at play within an application, you must explicitly define its context and communicate it to other teams.
- A bounded context is a linguistic boundary. It isolates models to remove ambiguity within UL.
- A bounded context protects the integrity of the domain model.
- Identifying and creating bounded contexts is one of the most important aspects of Domain-Driven Design.
- There are no rules for defining the boundaries of a model and therefore bounded contexts. Instead you should base bounded contexts around linguistic boundaries, team organization, subdomains and physical deployments.
- Subdomains are used in the problem space to partition the problem domain. Bounded contexts are used to define the applicability of a model in the solution space.
- A single team should own a bounded context.
- Architectural patterns apply at the bounded context level, not at the application level. If you don’t have complex logic in a bounded context, use a simple create, read, update, and delete (CRUD) architecture.
- Speak a ubiquitous language within an explicitly bounded context.
- A bounded context should be autonomous—owning the entire code stack from presentation through domain logic and onto the database and schema.


# 7. Context Mapping

- Often, teams that manage other contexts are not motivated by the same forces, or they have different priorities. For projects to succeed, teams usually need to manage changes in these situations at a political rather than technical level.

## A Reality Map

- A context map (...)  its responsibility is to ensure that boundaries between various contexts of the system are defined explicitly and that each team understands the contact points between them.

- A context map is not a highly detailed document created in some kind of enterprise architecture tool, it is a high-level, hand drawn diagram that communicates a holistic picture of the contexts in play. A context map should be simple enough to be understood by domain experts and development teams alike. As well as clearly labelling the contexts the teams understand, the diagram should also show areas of the system that are not well understood to reflect the messy and often unintelligible reality of the codebase.

- It is extremely important that context maps reflect reality, showing the code in the present state rather than an ideal future state. Context maps need not show the detail of a model; instead, they must demonstrate the integration points and the flow of data between bounded contexts. Like the code model and analysis model, the context map should change only when code changes so it does not give a false impression of the landscape. The map should show the stark reality; only then will it be useful.

- Teams that are not on the same project might find release schedules and development priorities need to be aligned if a change is required to a bounded context outside their ownership. 

## Recognising the Relationships between Bounded Contexts


- In order to avoid corruption and protect your model from external influences you can create an isolation layer that contains an interface written in terms of your model. The interface adapts and translates to the interface of the other context. This isolation layer is known as an anticorruption layer.

- it’s important not to compromise the integrity of your bounded context to match the API of another.

- If you have a system that resembles a BBoM and you need to introduce additional functionality it is tempting to simply add code to it and in turn add to the mess; alternatively you can request to rewrite the entire system at the same time as adding the new feature. Neither of these two options is practical as it can be time consuming and risky to rewrite a large application, and simply adding to the mess can increase the maintenance nightmare. A more pragmatic option is to lean on the anticorruption layer, which can be used to isolate the new context from the existing code mess. Using an anticorruption layer in this context is a great refactoring practice because you are able to create clear boundaries without needing to update the mess of code that lives within a context.

- it may be better to collaborate and to share part of the model to ease integration. This shared model is known as a shared kernel. The pattern is of particular use if you have two bounded contexts in the same subdomain that share a subset of domain logic.

- Because there is a shared code dependency, a shared kernel can be more risky due to the tighter coupling that leads to one team being able to break another team’s system. It’s important that everyone on both teams understands this and that a continuous integrated test system verifies the behavior of both models when the common model is modified.

- If the cost of integration between contexts is too great due to technical complexities or political ones, a decision can be made to not integrate contexts at all and simply have teams implement separately from one another. Integration can instead be achieved via user interfaces or manual processes.

- The customer-supplier relationship emphasizes that the customer team’s bounded context relies on the supplier team’s bounded context, but not vice versa. Sometimes there is no opportunity to form a collaborative relationship with an upstream context and so the downstream context must conform to the upstream context’s integration points.

-If an upstream context is not able to collaborate then the downstream context will need to conform to the upstream context when integrating. The most common occurrence of the conformist relationship is integrating with external suppliers.

- The most obvious downside to the conformist relationship is that the downstream team, which works to the requirements of the upstream team, may have to sacrifice clarity of its domain model because it must align to the model of the upstream context even though it may be conceptually different than your own view. Alternatively, an anticorruption layer can be used to retain the integrity so that changes to a contact point don’t affect the underlying model.

## The Strategic Importance of Context Maps

- In many ways, the communication between bounded contexts, both technical and organizational, is more important for teams starting out on a project than the bounded contexts themselves. Information that context maps provide can enable teams to make important strategic decisions that improve the success of a project. A context map is a powerful artifact that can bring new team members up to speed quickly and provide an early warning for potential trouble hot spots. Context maps can also reveal issues with communication and work flows within the business.

- All development teams in the organization need to understand the context map. Teams don’t need to understand the inner workings of each bounded context; instead, they need to be aware of those other contexts—the application programming interface (API) they expose, the relationships they have, and, most importantly, the conceptual models they are responsible for. With this information, teams can prevent blurring the lines of responsibility and ensure that all contexts retain their integrity.

- Retaining integrity is important to keep your codebase focused on a single model. This enables the code to become supple because any change affects only a single bounded context and doesn’t have a rippling effect across multiple areas of your domain. It’s this suppleness that enables you to alter code and to adapt quickly and confidently when the business needs a change to process or logic.

- Context mapping is about investigation and clarification; you may not be able to draw a clear context map straight away, but the process of clarifying responsibility, explicitly defining blurred lines, and understanding communication flow while mapping contexts is as important as the finished artifact.

## The Salient Points

- A context map reflects the way things are right now. It provides a holistic view of the technical integration methods and relationships between bounded contexts. Without them, models can be compromised, and bounded contexts can quickly change to balls of mud as integration blurs the lines of a model’s applicability.
- An anticorruption layer provides isolation for a model when interfacing with another context. The layer ensures integrity is not compromised by providing translation from one context to another.
- Integration using the shared kernel pattern is for contexts that have an overlap and shared a common model.
- Integration via an open host service exposes an external API instead of requiring clients to transform from one model to another. Typically, this creates a published language for clients to work with.
- Relationships between bounded contexts can be understood in terms of being upstream or downstream of one another. Upstream context have influence over downstream contexts.
- Collaboration between two teams not working to a common goal or not on the same project is known as a customer-supplier relationship. Downstream customers can collaborate with their upstream suppliers to integrate contexts.
- The conformist pattern describes the relationship between an upstream and downstream team where the upstream team will not collaborate with the downstream team. This is often the case when the upstream team is a third-party.
- The partnership relationship pattern describes two teams that have a common goal and a usually on the same project but working on two different contexts.
- Separate ways should be followed if bounded contexts are too costly to integrate and other nontechnical methods can be found.

# 8. Application Architecture

- Domain-Driven Design (DDD) focuses on managing the challenges of building applications with complex domain logic by isolating the business complexities from the technical concerns

## Application Architecture

- Developing software while following the principles of DDD does not require you to use any particular application architecture style. But one thing that your architecture must support is the isolation of your domain logic.

- To avoid turning your codebase into a Big Ball of Mud (BBoM) and thus weakening the integrity and ultimately the usefulness of a domain model, it is vital that the structure of an application supports the separation of technical complexities from the complexities of the domain.

- a domain model represents a conceptual abstract view of the problem domain created to fulfill the needs of the business use cases. The domain layer containing the abstract model does not depend on anything else and is agnostic to the technicalities of the clients it serves and data stores that persist the domain objects.

- Coordinating the retrieval of domain objects from a data store, delegating work to them, and then saving the updated state is the responsibility of the application service layer. Application service layers are also responsible for coordinating notifications to other systems when significant events occur within the domain. All these interfaces with external resources are defined within the application service layer but are implemented in the infrastructural layer.

- The application service layer enables the support of disparate clients without compromising the domain layer’s integrity. New clients must adapt to the input defined by the application’s contract—its API. They must also transform the output of the application service into a format that is suitable for them. In this way, the application layer can be thought of as an anticorruption layer, ensuring that the domain layer stays pure and unaffected by external technical details.

- The infrastructural layers of an application are the technical details that enable it to function. Whereas the application and domain layers are focused on modeling behavior and business logic, respectively, the infrastructural layers are concerned with purely technical capabilities, such as enabling the application to be consumed, whether by humans via a user interface or by applications via a set of web service or message endpoints.

- In addition, the infrastructural layer can provide capabilities for logging, security, notification, and integration with other bounded contexts and applications.

- To avoid tight coupling of layers, higher layers must communicate with lower layers by adapting to their message types. This again keeps the lower layers isolated and loosely coupled to any external layers

- you should favor application or bounded context databases over integration databases. Just as you apply context boundaries within the domain model, you must do the same for the persistence model. This helps to force clients to integrate through the well-defined application service layer, protecting the integrity of your model and ensuring invariants are met.

## Application Services

- Application services contain application logic only. This logic covers security, transaction management, and communication with other technical capabilities such as e-mail and web services. They are the clients of the domain layer and delegate all work to that layer. No domain logic should be found within the application services; instead,

- Application logic is all about coordination and orchestration through delegation to domain and infrastructural services. The application services don’t do any work, but they understand who to talk to to complete the task. Domain logic, on the other hand, is focused only on domain rules, concepts, information, and work flows. Domain logic is free from technical details, including persistence.

- Your application service methods can reveal whether a domain model is required at all. If you find that all your business use cases are simply updating, adding, or deleting data, then it’s a good bet that the domain is lacking any real logic and can be kept simple by employing a transaction script or data wrapper pattern

## Application Clients

## The Salient Points

- DDD does not require a specific architecture—only one that can separate the technical concerns from the business concerns.
- Separate the concerns of your application, and isolate business complexity from technical complexity by layering your application.
- Outer layers depend on inner layers. Inner layers expose interfaces that outer layers must adapt to and implement. This form of dependency inversion protects the integrity of the domain and application layers.
- The domain layer is at the heart of your application. It is isolated from technical complexities by the application layer.
- Application services expose the capabilities of a system by abstracting the domain logic to a higher level.
- Application services are based around business use cases; they are the clients of the domain layer. They delegate to the domain layer to fulfill the use cases.
- Application services should remain ignorant to the clients that consume them. Clients should adapt to the API of the application, which enables the support of discrepant clients.
- The application service layer is the concrete implementation of the bounded context boundary.

# 9. Common Problems for Teams Starting Out with Domain-Driven Design

- Domain-Driven Design (DDD) is a philosophy born out of a need to realign the focus of development teams writing software for complex domains. It is not a framework or a set of predefined templates that you can apply to a project. Although there is value in design patterns and frameworks, DDD emphasizes the value in collaboration, exploration, and learning between the business and development team to produce useful and relevant software. Teams should embrace the problem domain they are working within and look outside of their technical tunnel vision. The most fundamental point to being a great software craftsman is to understand the problem domain you work within and value this as much as you value your technical expertise.

## Overemphasizing the Importance of Tactical Patterns

- The code is an artifact of developers and domain experts working together and modeling the problem domain. The code represents the end of the process of collaboration and discovery. 

- Architectures are bounded context and not application specific.

- DDD is about discovering what you need to write, why you need to write it, and how much effort you should use. 

- DDD does prescribe a set of design best practices, patterns, and building blocks that are often mistakenly thought to be core to applying DDD to a product. Instead, think of these design artifacts as merely a means to an end used to represent the conceptual model. The heart of DDD lies deep in the collaboration between the development team and domain experts to produce a useful model.

## Missing the Real Value of DDD: Collaboration, Communication, and Context

-  The true value of DDD lies in the creation of a shared language, specific to a context that enables developers and domain experts to collaborate on solutions effectively. Code is a by-product of this collaboration. The removal of ambiguity in conversations and effortless communication is the goal. 

- Understanding where contexts end and begin is the responsibility of a context map. Without the notion of context and a context map to guide you, teams cannot deliver value because they are constantly fighting the unorganized mess of their codebase.

- The biggest issue that contributes to legacy code and technical debt is how it’s organized. Code is easy to write, but without due care and attention to how it is structured, it can become extremely hard to read. Understanding about context enables you to isolate unrelated concepts so that models are more pure and focused. (...) Code that is easier to maintain and read will allow teams to deliver value faster, which is the essence of DDD.

- Recognize when domain experts are talking in a different context but still using the same terms. If the same terms are used within the business, it is easy to fall into the trap of thinking that the models can be reused. Beware implicit models that are used for more than one context. It’s better to create explicit models. Apply the principle of Don’t Repeat Yourself (DRY) to a bounded context only and not a system. Don’t be afraid to use the same concepts and names in different contexts. The most important thing teams need to know about is that they should protect their boundaries.

- Without a shared language, you cannot create a shared model. This shared vision of the problem enables the capturing of implicit concepts and collaborative problem solving. The process of creating a language is a direct result of collaboration between the development team and domain experts. Being able to easily solve problems and understand the problem domain is where the payoff comes from.

- Without a UL, contexts are hard to discover, because a bounded context is primarily defined by the applicability of language. Models created without context and explicit language quickly turn into a BBoM as concepts with the same name are modeled as one.

- Collaboration is all about getting lots of people with different points of view working on creating a model of the problem domain that can be used to solve problems. No one has the authority on a good idea, and no suggestion is stupid.

- Trying to collaborate on knowledge crunching with anyone other than a domain expert can be a wasted effort.

## Spending Too Much Time on What’s Not Important

- The design of software will suffer without a clear and shared vision of the goal of the product, often captured using a domain vision statement. Well-informed and educated design decisions can be made when developers understand the intent behind business users’ requirements. Missing the intent of the business and blindly developing leads to poor results.

- Accepting that not all of a system will be well designed and that not all of a system needs to be well designed is a big step forward for a team. Without a focus on the key aspects of a system, talented members of a team may be distracted by frameworks and instead want to work on the latest JavaScript framework at the presentation layer instead of the core aspects of a product.

## Making Simple Problems Complex

- Applying techniques designed to manage complex problems to domains with little or no complexity will result in at best wasted effort and at worst needlessly complicated solutions that are difficult to maintain due to the multiple layers of abstractions

- Simple problems require simple solutions

- Problems with a low business expectation should be tackled in a no-thrills manner. This is not to say that they should be built in a haphazard manner. On the contrary, they should be built to be performant and maintainable, but problems that have little logic need straightforward solutions.

- The domain model pattern is useful for complex or frequently changing models. The effort required to employ the domain model pattern for models that are generic or lack domain logic will be far greater than any value that will be gained. Utilize model-driven design and the domain model pattern for the core domain, and use other domain logic patterns for simpler parts of your system.

## Underestimating the Cost of Applying DDD

- Applying the principles of DDD is hard and costly both in time and resource. It makes sense to only fully apply them to the most important areas of your system: your core domain. The principles hang on a business willing to work with you on solutions rather than have you work in isolation. DDD often is more valuable to the nontechnical parts of product design.

- Remember: DDD isn’t a silver bullet. Just as switching from an upfront waterfall approach to a more agile/XP project methodology didn’t solve all your software development problems, opting to follow DDD won’t suddenly produce better software. The common denominator in any successful project is a team of clever people who are passionate about what they are doing and who care about it succeeding.

- If a development team is working alongside domain experts who are not invested in the project or do not understand the intent or vision, they will unlikely discover a useful model, create a UL, and work as an effective team. 

- Don’t try to strive for perfection in areas that don’t need it. For generic or supporting subdomains, keep things simple, straightforward, and uncomplicated. Use CRUD and simple domain logic patterns. Get the code written so it works; then move on to the core domain. The core domain is the area where you can strive for perfection. Small balls of mud are sometimes better in bounded contexts that are unimportant;

- It is far better to have small balls of mud, isolated from other contexts that can easily be replaced, rather than trying to strive for beautiful code everywhere.

## The Salient Points

- The tactical patterns of DDD can guide you toward creating an effective domain model; however, this area of DDD is evolving, and the implementation details have been overemphasized. The patterns may have value, but this is not where the value of DDD lies.
- DDD is far more than coding. Collaboration with domain experts to knowledge crunch and have a shared understanding of the problem domain expressed in a ubiquitous language are the pillars of DDD.
- Context is everything; context and isolation retain the integrity of your code. It reduces cognitive load and makes a model specific.
- You need a smart dedicated team willing to learn about the domain.
- You need access to a domain expert. Teams can’t reveal deeper insights without them.
- Use CRUD for bounded contexts with low complexity. You are not a bad programmer if you don’t have a domain model.
- Bounded context and the ubiquitous language are the foundation of DDD.
- DDD is about the process of learning, refining, experimenting, and exploring in the quest to discover a useful model in collaboration.


# 10. Applying the Principles, Practices, and Patterns of DDD

## Selling DDD

- it is a powerful and extremely effective philosophy when used in the correct circumstances, such as these: (Without these key ingredients, applying the principles and practices of DDD will overcomplicate your development effort rather than simplify it)
- You have a skilled, motivated, and passionate team that is eager to learn.
- You have a nontrivial problem domain that is important to your business.
- You have access to domain experts who are aligned to the vision of the project.
- You are following an iterative development methodology.

- Don’t sell DDD as a project methodology; instead, understand and apply the principles appropriately and where you can gain value. Just as design patterns are best arrived at when you refactor, the principles and practices of DDD should be used only when necessary, and with each on its own merit.

- Technology is not the solution to business problems; it is merely an implementation detail. Problem solving is achieved through collaboration with domain experts who hold the key to discovering a useful model.

- Of course, you are free to talk to your stakeholders about DDD, but it’s best to focus on the need for collaboration. The success of a product falls on the commitment level of the business and its experts; this is how you sell DDD.


## Applying the Principles of DDD

- the key to applying DDD is to start simple. Do the simplest thing possible until you encounter complexity or ambiguity. 

- When you find ambiguity during conversation, explicitly define it within the ubiquitous language (UL). When your model is becoming too large, decompose the complexity and apply the strategic patterns of code organization and modeling techniques. If you keep things simple and arrive at applying the principles and practices rather than trying to crack a nut with a sledgehammer, you will get immense value from DDD.

- What is the business goal/driver for this product?
- What value will this product bring to the business?
- How will you know if this is a success? What does good look like?
- How is this different from what has been done before?

- By listening to the stakeholder answering your questions, you can identify the most important part of the product—the area of the software that is the fundamental reason you are building it. 

- An effective way to engage stakeholders when gathering requirements is to apply the behavior-driven development (BDD) methodology. BDD is a shared language that helps you capture the behaviors of a system. You can think of it as a UL for requirements.

- What you are capturing from the stakeholders are use-cases, inputs, and outputs. These business use cases form your application services. If they are complex, they drive the decision on what domain logic pattern you will implement. During requirements gathering, focus on what the stakeholder wants, when, and why. The why part is essential. 

- If you find that the problem domain is becoming too large to manage, you can ease cognitive load by abstracting the problem to a higher level by creating subdomains.

- The core domain should directly support the overall vision that the stakeholders have; if it does not, you may have incorrectly identified the core domain, or you may need to clarify the vision with your stakeholders.

- Understanding the state of the software solutions already in production is essential to making informed decisions on how you will integrate your product. The best way to capture the landscape is by creating a context map.

- This is your war map. It should be simple enough for all to draw quickly, so don’t spend too much time on UML diagrams.

- Before starting to model a solution and applying the principles of DDD, you need to ensure the product you are about to provide a solution for meets the following criteria:
- Is a complex problem or has complexity in a subdomain
- Is important to the business and has high expectations of it
- Has accessibility to a domain expert
- Has a motivated and smart team

- A domain expert is a subject matter expert with deep knowledge of the problem domain. Whereas a stakeholder defines what the system needs to do, a domain expert collaborates with the development team, using his insight, expertise, and experience to model a solution that satisfies the behaviors.

- The point is that the term domain expert does not refer to a title; it’s anyone in the business who can offer expertise in the problem domain.

- A domain expert will have a day job; her time will be precious, so it is vital that you utilize time with her wisely.

- Business analysts are not invalid. They hold skills that developers and domain experts may not possess. Business analysts can facilitate conversations with domain experts and can help the team capture terminology that forms the UL.

- It is important for the stakeholder to trust the domain expert and regard this person as an expert.

- Try to collocate your project team with the business. Your team should be able to access the domain experts and users easily and regularly to ensure constant feedback. 

- When working in the solution space, ensure that you focus on satisfying the behaviors of the product rather than trying to model the entire problem domain.

- Modeling in the complicated areas that are at the heart of the product is exactly what the principles of DDD were made for.

- The UL is formed from the knowledge crunching exercise between domain experts and the development team as they start to model a solution to the more important and trickier parts of a product. Clear and unambiguous communication between the development team and the domain expert is vital to enable discoveries and to reduce translation cost between the team’s code model and the domain expert’s mental model.

- Sometimes while modeling, you become stagnant; your solution may have painted you into a corner, and a new scenario cannot be fulfilled with the current model. This is fine. Instead of trying to make the scenario fit the model, make a new model that is useful for the existing and new scenarios.

- The result of tackling a problem from various angles is not the creation of a perfect model but instead the learning and discovery of concepts in the problem domain. This is far more valuable and leads to a team able to produce a useful model at each iteration.

- The mental model that was created between you and your domain expert should be reflected in code with the same terminology, language, and concepts. Once it turns the mental model into code, the development team may find that the model does not meet the needs of the scenario, and it needs to make a new concept or change an existing one. Because of the use of the UL and the shared understanding of the model throughout the team, communication with the domain expert is easy, and the new solution can be validated in collaboration and without translation. The update to the code model is reflected in the mental model, and the two models evolve together.

- If you are working in a legacy codebase or are integrating with a legacy code, it is vital to ensure that your code is not contaminated by the mess that already exists. (If there is mess; remember that legacy doesn’t mean bad code!) It may be tempting to clean up the legacy codebase, but this is a task that can quickly become time consuming and distract from your real goal of introducing new functionality. Instead, lean on the anticorruption layer pattern to create a boundary between your new code and the existing code. This protection boundary enables you to create a clean model that is isolated from other teams’ influences.

- Even if the technical design of the code has been modified to increase clarity, the names and methods of classes, along with the namespaces, should continue to be updated to reflect the more insightful abstractions that are discovered through knowledge-crunching sessions. This continued investment in the model helps keep it relevant and match the vision and intent of the domain experts.

- Don’t strive for perfect code; strive for perfect boundaries. 

- A model is constantly evolving and changing; you cannot effectively utilize the practices and patterns of DDD without embracing evolution.

- As a developer, it is your job to continuously challenge the effectiveness and simplicity of your model design as iterations change and evolve it to meet the new behaviors of the stakeholders.

## Exploration and Experimentation

- The activity of modeling happens whenever you need it; it is not a step in a project methodology.

- Don’t get attached to ideas; trial and error is required to reveal concepts in the domain that will help you solve business problems. 

- be careful of premature refactoring. Don’t refactor until you know enough about the domain, and don’t become preoccupied with applying design patterns. Delaying refactoring can also reveal which areas of the code change most often and why. With this knowledge, you can make more informed design changes to your codebase.

## Making the Implicit Explicit

- If domain experts talk about it, make it explicit. If domain experts hint at a concept, make it explicit. If you talk about something that puzzles domain experts, maybe you have misunderstood something they have said and you need to work on your UL. Give things a name, and if you can’t think of a good name, defer it and call it the blue policy until you can think of something more meaningful.

- A domain model should communicate the intent of the business. Ensure that you take care in naming all methods and properties of your classes. Try to describe the behaviors by involving the UL. Don’t leave your code design up to interpretation. Help yourself and other developers by writing code that is insightful, revealing the rich language of the domain.

## A Problem Solver First, A Technologist Second

- Code is a product of DDD, not the process

- All problems are not created equal; some are complex and are of little business value, so it makes no sense to waste effort in finding automated solutions for them.

## How Do I Know That I Am Doing It Right?

- Unlike becoming a scrum master, there is no certificate awarded when applying the principles and practices of DDD. Your reward from your investment will result in a product that is easily understood, straightforward to maintain, meets the expectations of your stakeholders, and is fun to work on.

- Passion is contagious; if you commit to spend time with your domain experts to understand a domain at a deeper level and can show how this results in a more expressive codebase then your team will follow.

## The Salient Points

- Don’t sell DDD as a silver bullet. Focus on the alignment with the business and learning more about the domain you are building software for.
Apply the principles of DDD only when they are needed. Don’t use them as a tool for all problems.
- Decompose the problem space and focus on the core domain. All interesting conversations will happen here. This is where you apply the principles of DDD to maximize value and where you should apply the most effort.
- Before modeling a solution, capture the reality of the landscape, and understand other models and contexts in play. Who owns these? What relationships do you have with them? What and how is data exchanged?
- Build a model to satisfy feature scenarios. Start with the most risky or complex. Utilize your domain expert’s time here, and don’t bother him with simple data management.
- If you are working in a legacy environment, ensure that you protect yourself from external code, don’t trust anyone, and enforce your borders. - Carve out an area to add new functionality. Don’t try to clean up everything.
- Constantly integrate, refine, and challenge your model. Don’t stop at your first good idea. Explore and experiment, and validate good ideas by trying new models and solutions. Have at least three useful models.
- Don’t assume anything, keep things simple, delay large design decisions, and wait for complexity or new behaviors to challenge your solution. Then refactor toward strategic patterns when you need to.
- Modeling is a team activity, and one that should happen whenever the team is stuck, encounters an area it is unsure of, or needs clarification. It should not be confined to a predefined step in a project time line.
- The model and the language evolve together. A model that cannot be communicated and talked about with ease will have limited usefulness and will be hard to evolve.
- You will also find that your team members understand the business better. You will notice that they will be able to talk more fluently with stakeholders and offer solutions to problems that the business didn’t know it had or maybe did not have a solution for.