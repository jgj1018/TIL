### Chapter 1. Introduction


- Hope is not a strategy.


- At their core, the development teams want to launch new features and see them adopted by users. At their core, the ops teams want to make sure the service doesn’t break while they are holding the pager. Because most outages are caused by some kind of change—a new configuration, a new feature launch, or a new type of user traffic—the two teams’ goals are fundamentally in tension


- SRE is what happens when you ask a software engineer to design an operations team. 


- Google places a 50% cap on theaggregate “ops” work for all SREs—tickets, on-call, manual tasks,etc. This cap ensures that the SRE team has enough time in theirschedule to make the service stable and operable.


- Google’s rule of thumb is that an SRE team must spend the remaining50% of its time actually doing development.  So how do we enforce thatthreshold? In the first place, we have to measure how SRE time isspent.  With that measurement in hand, we ensure that the teamsconsistently spending less than 50% of their time on development workchange their practices. Often this means shifting some of theoperations burden back to the development team, or adding staff to theteam without assigning that team additional operationalresponsibilities.


- In general, an SRE team is responsible for the availability, latency, performance, efficiency, change management, monitoring, emergency response, and capacity planning of their service(s).


- Google caps operational work for SREs at 50% of their time. Their remaining time should be spent using their coding skills on project work. In practice, this is accomplished by monitoring the amount of operational work being done by SREs, and redirecting excess operational work to the product development teams: reassigning bugs and tickets to development managers, (...) The redirection ends when the operational load drops back to 50% or lower.


- Postmortems should be written for all significant incidents, regardless of whether or not they paged; postmortems that did not trigger a page are even more valuable, as they likely point to clear monitoring gaps. This investigation should establish what happened in detail, find all root causes of the event, and assign actions to correct the problem or improve how it is addressed next time. Google operates under a blame-free postmortem culture, with the goal of exposing faults and applying engineering to fix these faults, rather than avoiding or minimizing them.


- The use of an error budget resolves the structural conflict of incentives between development and SRE. SRE’s goal is no longer “zero outages”; rather, SREs and product developers aim to spend the error budget getting maximum feature velocity. This change makes all the difference. An outage is no longer a “bad” thing—it is an expected part of the process of innovation, and an occurrence that both development and SRE teams manage rather than fear.


- humans should be notified only when they need to take action.


- Alerts: Signify that a human needs to take action immediately in response to something that is either happening or about to happen, in order to improve the situation.


- Tickets: Signify that a human needs to take action, but not immediately. The system cannot automatically handle the situation, but if a human takes action in a few days, no damage will result.


- Logging: No one needs to look at this information, but it is recorded for diagnostic or forensic purposes. The expectation is that no one reads logs unless something else prompts them to do so.


- The most relevant metric in evaluating the effectiveness of emergency response is how quickly the response team can bring the system back to health—that is, the MTTR.(mean time to repair )


- When humans are necessary, we have found thatthinking through and recording the best practices ahead of time in a“playbook” produces roughly a 3x improvement in MTTR as compared tothe strategy of “winging it.” The hero jack-of-all-trades on-callengineer does work, but the practiced on-call engineer armed with aplaybook works much better. 


- Demand forecasting and capacity planning can be viewed as ensuringthat there is sufficient capacity and redundancy to serve projectedfuture demand with the required availability. There’s nothingparticularly special about these concepts, except that a surprisingnumber of services and teams don’t take the steps necessary to ensurethat the required capacity is in place by the time it isneeded.


### Chapter 11. Being On-Call


- As the guardians of production systems, on-call engineers take care of their assigned operations by managing outages that affect the team and performing and/or vetting production changes.


- When on-call, an engineer is available to perform operations on production systems within minutes, according to the paging response times agreed to by the team and the business system owners. Typical values are 5 minutes for user-facing or otherwise highly time-critical services, and 30 minutes for less time-sensitive systems.


- we strive to invest at least 50% of SRE time into engineering: of the remainder, no more than 25% can be spent on-call, leaving up to another 25% on other types of operational, nonproject work.


- Being an SRE on-call typically means assuming responsibility for user-facing, revenue-critical systems or for the infrastructure required to keep these systems up and running.


- following intuition can lead an engineer to waste time pursuing a lineof reasoning that is incorrect from the start.


- The most important on-call resources are: Clear escalation paths, Well-defined incident-management procedures, A blameless postmortem culture


- when an incident occurs, it’s important to evaluate what went wrong, recognize what went well, and take action to prevent the same errors from recurring in the future. SRE teams must write postmortems after significant incidents and detail a full timeline of the events that occurred. By focusing on events rather than the people, these postmortems provide significant value. Rather than placing blame on individuals,


- Misconfigured monitoring is a common cause of operational overload. Paging alerts should be aligned with the symptoms that threaten a service’s SLOs. All paging alerts should also be actionable. Low-priority alerts that bother the on-call engineer every hour (or more frequently) disrupt productivity, and the fatigue such alerts induce can also cause serious alerts to be treated with less attention than necessary.


- Noisy alerts that systematically generate more than one alert per incident should be tweaked to approach a 1:1 alert/incident ratio. Doing so allows the on-call engineer to focus on the incident instead of triaging duplicate alerts.


### Chapter 12. Effective Troubleshooting


- Ineffective troubleshooting sessions are plagued by problems at the Triage, Examine, and Diagnose steps, often because of a lack of deep system understanding.


- we should remember that correlation is not causation:6 some correlated events, say packet loss within a cluster and failed hard drives in the cluster, share common causes—in this case, a power outage, though network failure clearly doesn’t cause the hard drive failures nor vice versa.


- In practice, of course, troubleshooting is never as clean as our idealized model suggests it should be. 


- An effective report should tell you the expected behavior, the actual behavior, and, if possible, how to reproduce the behavior.


- Injecting known test data in order to check that the resulting output is expected (a form of black-box testing) at each step can be especially effective, as can injecting data intended to probe possible causes of errors. Having a solid reproducible test case makes debugging much faster(...)


- Once you’ve come up with a short list of possible causes, it’s time to try to find which factor is at the root of the actual problem.


- Once you’ve found the factors that caused the problem, it’s time to write up notes on what went wrong with the system, how you tracked down the problem, how you fixed the problem, and how to prevent it from happening again.


- Typically a sudden increase in latency and resource usage indicates either an increase in traffic sent to the system or a change in system configuration.


### Chapter 13. Emergency Response


- A proper response takes preparation and periodic, pertinent, hands-on training. Establishing and maintaining thorough training and testing processes requires the support of the board and management, in addition to the careful attention of staff. All of these elements are essential in fostering an environment in which teams can spend money, time, energy, and possibly even uptime to ensure that systems, processes, and people respond efficiently during an emergency.


- There is no better way to learn than to document what has broken in the past. History is about learning from everyone’s mistakes.


- When it comes to failures, theory and reality are two very different realms. Until your system has actually failed, you don’t truly know how that system, its dependent systems, or your users will react. Don’t rely on assumptions or what you can’t or haven’t tested.


### Chapter 14. Managing Incidents


- It’s important to make sure that everybody involved in the incident knows their role and doesn’t stray onto someone else’s turf. Somewhat counterintuitively, a clear separation of responsibilities allows individuals more autonomy than they might otherwise have, since they need not second-guess their colleagues.


- The incident commander’s most important responsibility is to keep a living incident document. This can live in a wiki, but should ideally be editable by several people concurrently. 


- It is better to declare an incident early and then find a simple fix and close out the incident than to have to spin up the incident management framework hours into a burgeoning problem.


- if any of the following is true, the event is an incident: Do you need to involve a second team in fixing the problem? Is the outage visible to customers? Is the issue unsolved even after an hour’s concentrated analysis?


- Prioritize. Stop the bleeding, restore service, and preserve the evidence for root-causing.


- Prepare. Develop and document your incident management procedures in advance, in consultation with incident participants.


- Trust. Give full autonomy within the assigned role to all incident participants.


- Introspect. Pay attention to your emotional state while responding to an incident. If you start to feel panicky or overwhelmed, solicit more support.


- Consider alternatives. Periodically consider your options and re-evaluate whether it still makes sense to continue what you’re doing or whether you should be taking another tack in incident response.


- Practice. Use the process routinely so it becomes second nature.


- Change it around. Were you incident commander last time? Take on a different role this time. Encourage every team member to acquire familiarity with each role.



### Chapter 15. Postmortem Culture: Learning from Failure

- The primary goals of writing a postmortem are to ensure that the incident is documented, that all contributing root cause(s) are well understood, and, especially, that effective preventive actions are put in place to reduce the likelihood and/or impact of recurrence.


- Blameless postmortems are a tenet of SRE culture. For a postmortem to be truly blameless, it must focus on identifying the contributing causes of the incident without indicting any individual or team for bad or inappropriate behavior.


- You can’t “fix” people, but you can fix systems and processes to better support people making the right choices when designing and maintaining complex systems.


- When an outage does occur, a postmortem is not written as a formality to be forgotten. Instead the postmortem is seen by engineers as an opportunity not only to fix a weakness, but to make Google more resilient as a whole. While a blameless postmortem doesn’t simply vent frustration by pointing fingers, it should call out where and how services can be improved.


- Blameless postmortems can be challenging to write, because the postmortem format clearly identifies the actions that led to the incident. Removing blame from a postmortem gives people the confidence to escalate issues without fear. It is also important not to stigmatize frequent production of postmortems by a person or team. An atmosphere of blame risks creating a culture in which incidents and issues are swept under the rug, leading to greater risk for the organization


- Our goal is to share postmortems to the widest possible audience that would benefit from the knowledge or lessons imparted.


- In the spirit of nurturing the postmortem culture, SREs proactively create activities that disseminate what we learn about system infrastructure.


- One of the biggest challenges of introducing postmortems to an organization is that some may question their value given the cost of their preparation. The following strategies can help in facing this challenge: Ease postmortems into the workflow. A trial period with several complete and successful postmortems may help prove their value, in addition to helping to identify what criteria should initiate a postmortem. Make sure that writing effective postmortems is a rewarded and celebrated practice, both publicly through the social methods mentioned earlier, and through individual and team performance management.

