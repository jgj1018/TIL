
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

- A problem space gives you a set of requirements, inputs, and expected outputs—this is usually provided from your stakeholders. A solution space contains a model that can meet the needs of the requirements—this is where domain experts can help.

- Start with the areas of the problem domain that keep the business up at night—the areas that will make a difference to the business and that are core for the application to be a success. For example, asking the domain experts which parts of the current system are hard to use, or which manual processes stop them from doing more creative, value-adding work.

- Naming is important when modeling a domain. However, premature naming can be a problem when you discover through further knowledge crunching that concepts turn out to be different from what you first understood them to be. (...) When you feel you have really understood a part of the model, you will be in a better place to give it a sensible and meaningful name.

- Much like DDD, BDD does not focus on the technical aspects of an application. Where it differs is that BDD focuses on the software behavior, how the system should behave, whereas DDD focuses on the domain mo