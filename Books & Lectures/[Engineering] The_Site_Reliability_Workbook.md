### Chapter 1. How SRE Relates to DevOps


##### Background on DevOps

- DevOps and Site Reliability Engineering (SRE). Although we talk about them individually as if they are totally separate reactions to the enterprise mentality just described we hope to persuade you that in fact they are much more alike, and practitioners of each have much more in common, than you might assume.


- (DevOps) Sharing and collaboration are at the forefront of this movement.


- (DevOps: No More Silos) The first key idea is no more silos.
 
 
- (DevOps: Accidents Are Normal) The second key idea is that accidents are not just a result of the isolated actions of an individual, but rather result from missing safeguards for when things inevitably go wrong. (...) it is more profitable to focus on speeding recovery than preventing accidents.


- (DevOps: Change Should Be Gradual) The third key idea is that change is best when it is small and frequent. This strategy, coupled with automatic testing  of smaller  changes and reliable rollback of bad changes, leads to approaches to change management like continuous integration (CI) and continuous delivery or deployment (CD).


- (DevOps: Tooling and Culture Are Interrelated) Tooling is an important component of DevOps, particularly given the emphasis on managing change correctly. (...) A good culture can work around broken tooling, but the opposite rarely holds true. 


- (DevOps: Measurement Is Crucial) measurement is particularly crucial in the overall business context of, for example, breaking down silos and incident resolution.


##### Background on SRE

- <span style="color:red"> DevOps is a broad set of principles about whole-lifecycle collaboration between operations and product development. SRE is a job role, a set of practices (described next) we’ve found to work, and some beliefs that animate those practices. If you think of DevOps as a philosophy and an approach to working, you can argue that SRE implements some of the philosophy that DevOps describes, and is somewhat closer to a concrete definition of a job or role than, say, “DevOps engineer.”8 So, in a way, class SRE implements interface DevOps.</span>


- (SRE: Operations Is a Software Problem) The basic tenet of SRE is that doing operations well is a software problem.


- (SRE: Manage by Service Level Objectives (SLOs)) SRE does not attempt to give everything 100% availability. Instead, the product team and the SRE team select an appropriate availability target for the service and its user base, and the service is managed to that SLO
 

- (SRE: Work to Minimize Toil) For SRE, any manual, structurally mandated operational task is abhorrent. For SRE in the Google context, toil is not the job—it can’t be.  Any time spent on operational tasks means time not spent on project work—and project work is how we make our services more reliable and scalable.


- (SRE: Automate This Year’s Job Away) The real work in this area is determining what to automate, under what conditions, and how to automate it. SRE as practiced in Google has a hard limit of how much time a team member can spend on toil, as opposed to engineering that produces lasting value: 50%


- (SRE: Move Fast by Reducing the Cost of Failure) One of the main benefits of SRE engagement is not necessarily increased reliability, although obviously that does happen; it is actually improved product development output. Why? Well, a reduced mean time to repair (MTTR) for common faults results in increased product developer velocity, as engineers don’t have to waste time and focus cleaning up after these issues. This follows from the well-known fact that the later in the product lifecycle a problem is discovered, the more expensive it is to fix.
 

- (SRE: Share Ownership with Developers) Rigid boundaries between “application development” and “production” (sometimes called programmers and operators) are counterproductive. (...)  SREs tend to be inclined to focus on production problems rather than business logic problems, but as their approach brings software engineering tools to bear on the problem, they share skill sets with product development teams.


- (SRE: Use the Same Tooling, Regardless of Function or Job Title) Yet we share this absolute assumption with DevOps: teams minding a service13 should use the same tools, regardless of their role in the organization. There is no good way to manage a service that has one tool for the SREs and another for the product developers, behaving differently (and potentially catastrophically so) in different situations.


##### Compare and Contrast
- DevOps and SRE are both contingent on an acceptance that change is necessary in order to improve.


- Collaboration is front and center for DevOps work. An effective shared ownership model and partner team relationships are necessary for SRE to function. Like DevOps, SRE also has strong values shared across the organization, which can make climbing out of team-based silos slightly easier.


- Change management is best pursued as small, continual actions, the majority of which are ideally both automatically tested and applied.


- The right tooling is critically important, and tooling to a certain extent determines the scope of your acts. 


- Measurement is absolutely key to how both DevOps and SRE work. For SRE, SLOs are dominant in determining the actions taken to improve the service. (...)  For DevOps, the act of measurement is often used to understand what the outputs of a process are, what the duration of feedback loops is, and so on. Both DevOps and SRE are data-oriented things, whether they are professions or philosophies.


- The brute reality of managing production services means that bad things happen occasionally, and you have to talk about why. SRE and DevOps both practice blameless postmortems in order to offset unhelpful, adrenaline-laden reactions.


- Ultimately, implementing DevOps or SRE is a holistic act; both hope to make the whole of the team (or unit, or organization) better, as a function of working together in a highly specific way. For both DevOps and SRE, better velocity should be the outcome.


- <span style="color:red"> DevOps is in some sense a wider philosophy and culture. Because it effects wider change than does SRE, DevOps is more context-sensitive. DevOps is relatively silent on how to run operations at a detailed level. For example, it is not prescriptive around the precise management of services. It chooses instead to concentrate on breaking down barriers in the wider organization. This has much value.</span>


- <span style="color:red"> SRE, on the other hand, has relatively narrowly defined responsibilities and its remit is generally service-oriented (and end-user-oriented) rather than whole-business-oriented. As a result, it brings an opinionated intellectual framework (including concepts like error budgets) to the problem of how to run systems effectively. Although SRE is, as a profession, highly aware of incentives and their effects, it in turn is relatively silent on topics like siloization and information barriers. It would support CI and CD not necessarily because of the business case, but because of the improved operational practices involved. Or, to put it another way, SRE believes in the same things as DevOps but for slightly different reasons.</span>

- the basic foundations of SRE include SLOs, monitoring, alerting, toil reduction, and simplicity.


### Chapter 2. Implementing SLOs

- Service level objectives (SLOs) specify a target level for the reliability of your service. Because SLOs are key to making data-driven decisions about reliability, they’re at the core of SRE practices.


- Their day-to-day tasks and projects are driven by SLOs: ensuring that SLOs are defended in the short term and that they can be maintained in the medium to long term. One could even claim that without SLOs, there is no need for SREs.


- SLOs are a tool to help determine what engineering work to prioritize.


- There are SLOs that all stakeholders in the organization have approved as being fit for the product.


- The people responsible for ensuring that the service meets its SLO have agreed that it is possible to meet this SLO under normal circumstances.


- The organization has committed to using the error budget for decision making and prioritizing. This commitment is formalized in an error budget policy.


- There is a process in place for refining the SLO.


- Once you have an SLO target below 100%, it needs to be owned by someone in the organization who is empowered to make tradeoffs between feature velocity and reliability.


- SLI is an indicator of the level of service that you are providing.


- we generally recommend treating the SLI as the ratio of two numbers: the number of good events divided by the total number of events.


- the SLO is a target percentage and the error budget is 100% minus the SLO.


- a single SLI specification might have multiple SLI implementations, each with its own set of pros and cons in terms of quality (how accurately they capture the experience of a customer), coverage (how well they capture the experience of all customers), and cost.

- hoose one application for which you want to define SLOs. If your product comprises many applications, you can add those later.


- Decide clearly who the “users” are in this situation. These are the people whose happiness you are optimizing.


- Consider the common ways your users interact with your system—common tasks and critical activities.


- Draw a high-level architecture diagram of your system; show the key components, the request flow, the data flow, and the critical dependencies. Group these components into categories listed in the following section (there may be some overlap and ambiguity; use your intuition and don’t let perfect be the enemy of the good).


- Rolling windows are more closely aligned with user experience: if you have a large outage on the final day of a month, your user doesn’t suddenly forget about it on the first day of the following month. We recommend defining this period as an integral number of weeks so it always contains the same number of weekends.


- Calendar windows are more closely aligned with business planning and project work. For example, you might evaluate your SLOs every quarter to determine where to focus the next quarter’s project headcount. 


- In order for a proposed SLO to be useful and effective, you will need to get all stakeholders to agree to it. 


- Once you have an SLO, you can use the SLO to derive an error budget. In order to use this error budget, you need a policy outlining what to do when your service runs out of budget.


- Remember that lowering the SLOs also lowers the number of situations to which the SREs will respond; the product manager needs to understand this tradeoff.


- When we talk about enforcing an error budget, we mean that once you exhaust your error budget (or come close to exhausting it), you should do something in order to restore stability to your system.


- This policy should cover the specific actions that must be taken when a service has consumed its entire error budget for a given period of time, and specify who will take them


- The development team gives top priority to bugs relating to reliability issues over the past four weeks.


- The development team focuses exclusively on reliability issues until the system is within SLO. This responsibility comes with high-level approval to push back on external feature requests and mandates.


- To reduce the risk of more outages, a production freeze halts certain changes to the system until there is sufficient error budget to resume changes.


- Sometimes a service consumes the entirety of its error budget, but not all stakeholders agree that enacting the error budget policy is appropriate. If this happens, you need to return to the error budget policy approval stage.


- When starting out, you should probably review the SLO frequently—perhaps every month. Once the appropriateness of the SLO becomes more established, you can likely reduce reviews to happen quarterly or even less frequently.


- If some of your outages and ticket spikes are not captured in any SLI or SLO, or if you have SLI dips and SLO misses that don’t map to user-facing issues, this is a strong sign that your SLO lacks coverage. This situation is totally normal and should be expected. Your SLIs and SLOs should change over time as realities about the service they represent change. Don’t be afraid to examine and refine them over time!


- Sometimes you determine that you need a tighter SLO to make your users happy, but improving your product to meet that SLO will take some time. If you implement the tighter SLO, you’ll be permanently out of SLO and subject to your error budget policy. In this situation, you can make the refined SLO an aspirational SLO—measured and tracked alongside your current SLO, but explicitly called out in your error budget policy as not requiring action. This way you can track your progress toward meeting the aspirational SLO, but you won’t be in a perpetual state of emergency.


- The obvious decisions start from what to do when you’re not meeting your SLO—that is, when you’ve exhausted your error budget. As already discussed, the appropriate course of action when you exhaust your error budget should be covered by the error budget policy.


- You can use critical user journeys to help capture the experience of your customers. A critical user journey is a sequence of tasks that is a core part of a given user’s experience and an essential aspect of the service.


- Once you identify user-centric events, you can solve the problem of measuring them. You might measure them by joining distinct log events together, using advanced JavaScript probing, using client-side instrumentation, or using some other process. Once you can measure an event, it becomes just another SLI, which you can track alongside your existing SLIs and SLOs. Critical user journeys can improve your recall without affecting your precision.


- We need a way to distinguish certain classes of requests from others. You can use bucketing to accomplish this—that is, adding more labels to your SLIs, and then applying different SLOs to those different labels.


- While your prime concern is implementing a user-centric SLO that covers the entire stack, SLOs can also be a useful way to coordinate and implement reliability requirements between different components in the stack. 


- There are two schools of thought regarding how an error budget policy should address a missed SLO when the failure is caused by a dependency that’s handled by another team: Your team should not halt releases or devote more time to reliability, as your system didn’t cause the issue. You should enact a change freeze in order to minimize the chances of future outages, regardless of the cause of that outage. The second approach will make your user


- <span style="color:red"> SLOs are the tool by which you measure your service’s reliability.</span>


- <span style="color:red"> Error budgets are a tool for balancing reliability with other engineering work, and a great way to decide which projects will have the most impact.</span>


- You should start using SLOs and error budgets today.


### Chapter 3. SLO Engineering Case Studies


- It does not try to transform operations engineers into application developers, or vice versa. Instead, it gives both a common frame of reference. In our experience, an error budget/SLO approach has led both teams to make similar decisions when presented with the same facts, as it removes a good deal of subjectivity from the conversation.


- We use the SLO/error budget concept as a method to allocate resources going forward. For example, if we missed the SLO for last month, that behavior helps us prioritize relevant fixes, improvements, and bug fixes. 


- In addition to our monthly Evernote/Google review of SLO performance, we’ve settled on a six-month SLO review cycle, which strikes the right balance between changing SLOs too often and letting them become stale. In revising our SLOs, we’ve also learned that it’s important to balance what you would like to measure with what’s possible to measure.


- Armed with an easy-to-remember acronym, we set out to evangelize SLOs to the enterprise:
- Why SLOs are important
- How SLOs support our “freedom and responsibility” culture
- What should be measured
- What to do with the results


- Since developers were now responsible for the operation of their software, they needed to establish SLOs to demonstrate their ability to build and support reliable software, and also to communicate with the consumers of their services and product managers for customer-facing services. However, most of this audience was unfamiliar with concepts like SLAs and SLOs, so they needed to be educated 


- As we needed to secure executive backing for our move to SLOs, our education campaign started with senior leadership. We then met with development teams one by one to espouse the values of SLOs. We encouraged teams to move from their custom metric-tracking mechanisms (which were often manual)


### Chapter 4. Monitoring

- At the most basic level, monitoring allows you to gain visibility into a system, which is a core requirement for judging service health and diagnosing your service when things go wrong.


- When choosing a monitoring system, it is important to understand and prioritize the features that matter to you


- Different organizations will have different needs when it comes to the freshness of data and the speed of data retrieval.


- Data more than four to five minutes stale might significantly impact how quickly you can respond to an incident.


- Without a long-term view of your data, you cannot analyze long-term trends like system growth.


- The metrics you retain about events or resource consumption should ideally be monotonically incrementing counters.


- A robust monitoring system should allow you to concisely display time-series data in graphs, and also to structure data in tables or a range of chart styles.


- For each set of dashboards, displaying the same types of data consistently is valuable for communication.


- When one of your service dependencies has a firing alert (e.g., a slow backend), you don’t need to alert for error rates of your service.


- You also need to be able to ensure alerts are no longer suppressed once the event is over.


- The real-time nature of our metrics-based monitoring system means that engineers can be notified of problems very rapidly. We tend to use logs to find the root cause of an issue, as the information we need is often not available as a metric.


- When reporting isn’t time-sensitive, we often generate detailed reports using logs processing systems because logs will nearly always produce more accurate data than metrics.


- Every alert required an explicit triage step to determine if it was user-facing, which slowed down response time.


- Once alerts were directly tied to SLOs, they were more clearly actionable, so the false-positive rate decreased significantly.


- SLI metrics are the first metrics you want to check when SLO-based alerts trigger.


- When investigating the cause of an SLO violation, you will most likely not get enough information from the SLO dashboards. These dashboards show that you are violating the SLO, but not necessarily why.


- Even if your service didn’t change, any of its dependencies might change or have problems, so you should also monitor responses coming from direct dependencies.


- Aim to monitor and track the usage of every resource the service relies upon. Some resources have hard limits you cannot exceed, like RAM, disk, or CPU quota allocated to your application. 


- In an ideal world, monitoring and alerting code should be subject to the same testing standards as code development.


- It’s very likely that your alerting rules will not fire for months or years after you configure them, and you need to have confidence that when the metric passes a certain threshold, the correct engineers will be alerted with notifications that make sense.


### Chapter 5. Alerting on SLOs


- The proportion of events detected that were significant. Precision is 100% if every alert corresponds to a significant event. Note that alerting can become particularly sensitive to nonsignificant events during low-traffic periods 


- Reset time : How long alerts fire after an issue is resolved. Long reset times can lead to confusion or to issues being ignored.


- To improve upon the previous solution, you want to create an alert with good detection time and high precision. To this end, you can introduce a burn rate to reduce the size of the window while keeping the alert budget spend constant. Burn rate is how fast, relative to the SLO, the service consumes the error budget.


- Your alerting logic can use multiple burn rates and time windows, and fire alerts when burn rates surpass a specified threshold. This option retains the benefits of alerting on burn rates and ensures that you don’t overlook lower (but still significant) error rates. It’s also a good idea to set up ticket notifications for incidents that typically go unnoticed but can exhaust your error budget if left unchecked—for example, a 10% budget consumption in three days. This rate of errors catches significant events, but since the rate of budget consumption provides adequate time to address the event, you don’t need to page someone. We recommend 2% budget consumption in one hour and 5% budget consumption in six hours as reasonable starting numbers for paging, and 10% budget consumption in three days as a good baseline for ticket alerts.


- Multiple burn rates allow you to adjust the alert to give appropriate priority based on how quickly you have to respond. If an issue will exhaust the error budget within hours or a few days, sending an active notification is appropriate. Otherwise, a ticket-based notification to address the alert the next working day is more appropriate


- To avoid multiple alerts from firing if all conditions are true, you need to implement alert suppression. For example: 10% budget spend in five minutes also means that 5% of the budget was spent in six hours, and 2% of the budget was spent in one hour. This scenario will trigger three notifications unless the monitoring system is smart enough to prevent it from doing so.


- We can enhance the multi-burn-rate alerts in iteration 5 to notify us only when we’re still actively burning through the budget—thereby reducing the number of false positives. To do this, we need to add another parameter: a shorter window to check if the error budget is still being consumed as we trigger the alert. A good guideline is to make the short window 1/12 the duration of the long window.


- One technique for managing a large number of SLOs is to group request types into buckets of approximately similar availability requirements.


- The techniques for alerting on significant events range from alerting when your error rate goes above your SLO threshold to using multiple levels of burn rate and window sizes. In most cases, we believe that the multiwindow, multi-burn-rate alerting technique is the most appropriate approach to defending your application’s SLOs.


### Chapter 6. Eliminating Toil

- we’ll define toil as the repetitive, predictable, constant stream of tasks related to maintaining a service. Toil is seemingly unavoidable for any team that manages a production service. (...) Google limits the time SRE teams spend on operational work (including both toil- and non-toil-intensive work) at 50% 


- Toil can slowly deflate team morale. Time spent working on toil is generally time not spent thinking critically or expressing creativity; reducing toil is an acknowledgment that an engineer’s effort is better utilized in areas where human judgment and expression are possible.


- It’s not always clear that a certain chunk of work is toil. Sometimes, a “creative” solution—writing a workaround—is not the right call. Ideally, your organization should reward root-cause fixes over fixes that simply mask a problem.


- Usually, teams must choose a toil-reduction project from several candidates. An objective measure of toil allows your team to evaluate the severity of the problems and prioritize them to achieve maximum return on engineering investment. Before beginning toil reduction projects, it’s important to analyze cost versus benefit and to confirm that the time saved through eliminating toil will (at minimum) be proportional to the time invested in first developing and then maintaining an automated solution


- Estimate the amount of time you’ll spend on toil reduction efforts, and make sure that the benefits outweigh the cost 


- Before investing effort in managing the toil generated by your existing systems and processes, examine whether you can reduce or eliminate that toil by changing the system.


- If you have a particularly complex business problem with many edge cases or types of requests, consider a partially automated approach as an interim step toward full automation.


- Use customer input to progress toward a more uniform way of collecting this data; by decreasing free-form requests, you can move closer to handling all requests programmatically.


- rather than asking engineers to file a ticket to provision a new virtual machine for their development work, give them a simple web form or script that triggers the provisioning. Allow the script to gracefully degrade to a ticket for specialized requests or if a failure occurs. Human-backed interfaces are a good start in the war against toil, but service owners should always aim to make their offerings self-service where possible.


- It is important for everyone in the organization to agree that toil reduction is a worthwhile goal. Manager support is crucial in defending staff from new demands.


- To create strong business cases for toil reduction, look for opportunities to couple your strategy with other desirable features or business goals. If a complementary goal—for example, security, scalability, or reliability—is compelling to your customers

- Like anyone new to Agile, to start off with it was all a big illusion. Buzz words and phrases are being thrown around like “death of documentation”, “no more governance and red tape” and “we’re reacting because we’re agile now”. When looking back at this, no-one had no idea what it meant and none of these things were particularly true. However they are said so often, usually by people who don’t understand or really want it to take off, that people start to take them as gospel. One reason this can happen is because Agile is imposed on a team without them understanding why. No team is going to do something just because they are told they must, it should be an organic process where the benefits of Agile make the team want to use it.


### Chapter 7. Simplicity


- For SREs, simplicity is an end-to-end goal: it should extend beyond the code itself to the system architecture and the tools and processes used to manage the software lifecycle


- In general, complexity will increase in living software systems unless there is a countervailing effort. Providing that effort is a worthwhile thing to do.


- Before an engineer goes on-call for the first time, encourage them to draw (and redraw) system diagrams. Keep a canonical set of diagrams in your documentation: they’re useful to new engineers and help more experienced engineers keep up with changes.


- Ensure that an SRE reviews all major design docs, and that the team documents show how the new design affects the system architecture. If a design adds complexity, the SRE might be able to suggest alternatives that simplify the system.


- Simplicity is a natural goal for SREs because simple systems tend to be reliable and easy to run.


### Part II. Practices

- project work is the other main bucket of SRE work. When a team’s interrupt work is well managed, they have time for longer-term engineering work to achieve stability, reliability, and availability goals. This might include software engineering projects aimed at improving the reliability of a service, or systems engineering projects like safely rolling out a new feature to a globally replicated service.


- At Google, we specify that SREs should spend at least 50% of their time on project work; anything less makes for unsustainable engineering and burned-out, unhealthy teams. While every team and organization needs to find its own healthy balance, we’ve found that about one-third of time spent on operational tasks and two-thirds of time spent on project work is just about right 


- Remember one caveat when finding your ideal balance: a team that spends too little of its time on operational tasks risks operational underload. In this situation, engineers might start to forget crucial aspects of the service they are responsible for. You can counter operational underload by taking more risks and moving faster—for example, shorten your release cycles, push more features per release, or perform more disaster recovery testing. If your team is perpetually underloaded, consider onboarding related services or handing back a service that no longer needs SRE support to the development team 


- there should be a continuous feedback loop between the sources of operational load and the project work that systematically improves production. This longer-term work might involve moving to more robust storage systems, redesigning frameworks to reduce brittleness or maintenance load, or addressing systemic sources of outages and incidents.


### Chapter 8. On-Call (not done) 


- At Google, the overall goal of being on-call is to provide coverage for critical services, while making sure that we never achieve reliability at the expense of an on-call engineer’s health. 


- Psychological safety3 is vital for effective on-call rotations. Since being on-call can be daunting and highly stressful, on-call engineers should be fully supported by a series of procedures and escalation paths to make their lives easier. 


### Chapter 9. Incident Response

- Resolving an incident means mitigating the impact and/or restoring the service to its previous condition. Managing an incident means coordinating the efforts of responding teams in an efficient manner and ensuring that communication flows both between the responders and to those interested in the incident’s progress.