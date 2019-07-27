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

