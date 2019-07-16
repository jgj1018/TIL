### Chapter 1. Introduction


- Hope is not a strategy.


- At their core, the development teams want to launch new features and see them adopted by users. At their core, the ops teams want to make sure the service doesn’t break while they are holding the pager. Because most outages are caused by some kind of change—a new configuration, a new feature launch, or a new type of user traffic—the two teams’ goals are fundamentally in tension


- SRE is what happens when you ask a software engineer to design an operations team. 


- Google places a 50% cap on theaggregate “ops” work for all SREs—tickets, on-call, manual tasks,etc. This cap ensures that the SRE team has enough time in theirschedule to make the service stable and operable.


- Google’s rule of thumb is that an SRE team must spend the remaining50% of its time actually doing development.  So how do we enforce thatthreshold? In the first place, we have to measure how SRE time isspent.  With that measurement in hand, we ensure that the teamsconsistently spending less than 50% of their time on development workchange their practices. Often this means shifting some of theoperations burden back to the development team, or adding staff to theteam without assigning that team additional operationalresponsibilities.