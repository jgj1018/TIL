## 1. Good, Bad and Effective Design

- Some use "The task-board shuffle"
- Some economize with "No design", but there is no such thing as "No design".
- There is only "Good" and "Bad" design
- One of scrum's most important tenets: "Knowledge Acquisition"

### Insidiout problems in Software Industry

- Software development is considered a cost center, rather than a profit center
- Developers trying to throw technology at business problems; chasing "shiny objects"
- Database and data model given priority over business process and operations
- Developers not placing proper emphasis on naming objects and operations with a business focus.
- Poor collaboration betweenb stakeholders and developers: the "Specifications Divide"
- Project estimates given too much attention and cause delays in productive development
- "Task-board shuffle" and "No design" lead to developing a big ball of mud
- Developers house business logic in the user interface and persistence code. This leads to slow queires and locking block database results.
- Wrong model abstractions lead to wrong solutions that miss the concrete business needs.
- Strong couping between services make systems difficult to maintain
- Failed coupling between services leads to failed business operations and unreconciled data within the whole system

### We model software, intentionally or not.

- "Economy" of "No design" is a fallacy
- It fools many into thinking that they can deliver quality software faster without thoughtful design.
- The resulting software diverges from the business goals and is hard to maintain

### Effective design is Best

- Meet the needs of the business and distinguishes the business from its competition.
- Forces the business to understand what it must excel at.
- Helps developers create correct model


## 2. Strategic Design with Bounded Contexts and the Ubiquitous Languages

- You can think of a ubiquitous language as the model within a specific service, The service being bounded context.
- Think of bounded context also as deviding nuances of meanings, or different words for the same thing.
- A boundary context helps us to model what is in context. Semantically, what belongs in our bounded context according to our ubiquitous language.

### Ubiquitous Compared to Human languages

- German is spoken in Germany, French in Franch, and Italian in Italy.
- When you cross a national border, the official language changes
- The same is true for context boundaries and uniquitous languages
- The bounded context makes the boundary where an official language is spoken.

- The domain expert has a focus in a specific area of the business and they've been charged to carry a vision about the area of the business.
- A vision will result in a software that will distinguish the organization from all others and give it competitive advantage..

### 2.5 Developing a ubiquitous language

- developing scenario : how specific objects or concepts within your domain model collaborate with other concepts within the domain model to accomplish a specific scenario goal.
- We can use BDD (behavior-driven development) based on a developing scenario (Given-When-Then)


## 3. Strategic Design with Subdomains

- We always have multiple bounded contexts within a core domain project.
- The most optimal modeling composition is when there is just one bounded context per subdomain.
- A subdomain is a subportion of the business domain.

### Sub-Part of your Business Domain

- Whole business domain is too complex to reason about
- Divide up whole business domain into logical Subdomains.
- Only consider Subdomains used in your specific problem space.

### Subdomains in a DDD setting

- Domain expert participating
- One clean bounded context as the core domain
- Other supporting bounded contexts.

### Core Domain

- Where your organization is making strategic investment in software
- Among highest priority projects
- Addresses at what your organization must excel by means of software
- How your organization will distinguish itself from all others.

### Supporting Domain

- Necessary to support a core domain
- Requires custom development because an off-the-shelf product doesn't exist
- However, this software doesn't deserve the investment the core domain gets
- Consider outsourcing to avoid heavy investment

### Generic subdomain

- Necessary, but generic
- Avoid investing heavily in this software.
- May be possible to purchase as off-the-shelf product or be outsourced.
- If developed in-house, don't assign developers with elite skills, such as with core domain team.

## 4. Strategic Design with Context Mapping

- Partnership : very heavy relationship. they have to coordinate, their deliveries together, they have to release at the same time, because they are supporting each other.
- Shared kernal ; at least two team have a very similar software model. 
- A customoer-supplier : it is where there is a definite upstream, downstream relationship between two teams. A change in upstream has impact on downstream.
- Confomist : it is where there is a definite upstream, downstream relationship where team 1 has an upstream model that will directly impact and influence the downstream team 2 model slavishly consume the model of team 1 and conform to it.
- Anti-corruption layer : it is where there are two teams with two separate models, but the downstream team does not want to be influenced by the upstream model unnecessarily. It's the opposite of the conformist pattern.

- If you do have to integrate with a big ball of mud, try to use an anti-corruption layer between your downstream bounded context which is no doubt a clean core domain and the upstream big ball of mud. This will allow you to consume the big ball of mud

