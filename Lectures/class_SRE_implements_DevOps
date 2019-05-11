- Source: https://www.youtube.com/watch?v=uTEL8Ff1Zvk&list=PLIivdWyY5sqJrKl7D2u-gmis8h9K66qoj&index=1



- If you think about devops as a philosophy, SRE is a precriptive way of accomplishing that philosophy
- class SRE implements DevOps.

- Reduce orginization silos - Share ownership
- Accept failures as normal - SLOs & Blameless PMs
- Implement gradual change - Reduce cost of failures
- Leverage Tooling & Automation - Automate this year's job away.
- Measure Everything - Measure toil and reliability.

- Define availability 
- Level of availability.
- Plan in case of failure.

##### SLI (Service level indicator)
SLI indicators or metrixs over time, which inform about the health of a service.
- For example, 95th percentile latency of hompage requests over past 5 min < 300ms
- Request latency
- Batch throughput
- Failures per request.

##### SLO (Service level objectives)
- it is agreed upon bounds for how often those SLIs must be met.
- For example, 95th percentile homepage SLI will succeed 99.9% over trailing year.
- Binding target for a collection of SLIs.

##### SLA (Service level agreement)
- Business agreement between a customoer and service provider typically based on SLOs.
- For example, service credits if 95th percentile hompage SLI succeeds less than 99.5% over trailing year.

- SLIs drive SLOs which inform SLAs.


##### Error budget

- The difference between actual uptime and the calculated target uptime from our SLO is the budget of how much unavailability we can tolerate for the system to be stable over the entire window of the SLO. We call this error budget.
- SLOs mathematically define the error budget
.
- The main benefits of error budget is that it's a quantitative measurement shared between the product and SRE teams, which means we can balance innovation and stability to an appropriate level.

- When we defined earlier the expectation of how much uptime a service is going to have and how we're going to measure it, we need to actually concreately implement that using a neutral third party like monitoring system.

- SRE team needs to have executive buy-in for error budgets. If SRE teams don't have the ability to enforce the error budgets then the whole system is going to break down.

- It's important to have error budgets from top to bottom for everything in your stack. that way you can figure out how much error budget you allocate to your dependencies and how much error budget is reserved for your developers to spend. And this is another reason why targeting 100% availability isn't realistic, because all of your dependencies are not 100% available either.

- When you have to do manual action to keep your system from failing, in the wait before you actually do that manual action, you will start burning through your error budget. But the actual act of doing that manual work, we track that separately. And that's a concept that we call toil


##### Toal and toil budget

- Overhead (not toil) : Email, Expense reports, Meetings, Traveling.

###### Characteristics of toil

- they're not tails because they're not directly tied to a production service.
- Toils are tied to running a production service that tends to be manual, repetitive, automatable, tactical, devoid of long-term value.
- Scales linearly as service grows.

###### Measuring toil
- Don't mix toil and project work.
- Account on call time as toil
- Survey, sample, and log toil.

- Toil does closely influence the desire to measure everytinh and reduce organizational silence.



##### CRE
- CRE customer reliability engineering and they focus on breaking down the organizational barriers, not between individual silos in a single company, but instead between a cloud customer and its platform provider.
- CREs are regular google SREs that are focused externally instead of working on our own GCP applications, we instead help customers who are implementing their applications on GSP, and we help them also implement SRE practices like SLIs and SLOs.

##### Managing risks

- Risk analysis : List of items that may cause an SLO violation.

- How does that help me figure out if my error budget is realistic? we need to figure out how often each failure is likely to happen and how severe it will be if and when it happens.

- TTD / TTR / Freq of yr/ Users / Bad min of yr


#### Actionable alerting for SRE.

- SRE will eventually wind up turning off the redundant alerts that are measuring potential causes of problems rather than corresponding recessarily to actual unhappy users.


#### Observability

- Structured logging
- Metrix
- Trace


#### Incident management

- (1) Process for declaring incidents.
- (2) Dashboard for viewing current incidents.
- (3) Database of who to contact for each kind of incident.

#### Postmorterms and Retrospectives.

- Blameless postmorterm metadata
- (1) What systems were affected?
- (2) Who was involved in responding?
- (3) How did we find out about the event?
- (4) When did we start responding?
- (5) What mitigations did we deploy? (either temporarily or permanently?)
- (6) When did the incident conclude?

- You will want to keep track of that is explicitly filing an issue in your issue tracker of choice for each action item so that you'll make sure to prioritize it for the future. And you can tag these things with the postmortem tag in your bug tracker so you can see how at risk you are of repeat outages based off of how many high priority items that you've checked off and how many remain outstanding.