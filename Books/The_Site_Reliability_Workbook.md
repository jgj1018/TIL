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