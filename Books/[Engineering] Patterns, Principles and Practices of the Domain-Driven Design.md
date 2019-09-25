
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


# Focusing on the Core Domain

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