##### (Books) The Site Reliability Workbook

- You can bring SREs on board to build a shell of abstracted APIs, automation, configuration management, monitoring, and testing around these legacy systems that will offload work from SAs. The legacy system remains brittle to change, but now you can at least reliably identify misbehavior and roll back when appropriate. This tactic is still avoidance, but is a bit like refinancing high-interest technical debt into low-interest technical debt. It’s usually a stopgap measure to prepare for an incremental replacement.

##### (Blog) https://medium.com/@muneeb.ahmed20/building-a-reporting-service-in-microservice-architecture-8d5bf3b90fb7

- Reporting service is never bounded to timely consistent data it moreover bounded towards availability of data if talking in terms of CAP theorem. In a microservice architecture, if designed correctly whenever the state of an application changed an event is published to event processor (Kafka) and consumed by multiple application. First and foremost thing is to design a reporting database correctly and then write a master listener which reads from each topic in Kafka and update the reporting database correctly. These master listeners are just workers that read messages from different topics in Kafka and update the database with the right information. As already discussed reporting database requires availability instead of consistency. Information will be consistent after some time depending on the workers’ throughput.

##### (Blog) https://martinfowler.com/bliki/MonolithFirst.html

- A more common approach is to start with a monolith and gradually peel off microservices at the edges. Such an approach can leave a substantial monolith at the heart of the microservices architecture, but with most new development occurring in the microservices while the monolith is relatively quiescent. 


##### (Blog) https://medium.com/swlh/how-to-avoid-common-agile-pitfalls-350a4534544b

- Like anyone new to Agile, to start off with it was all a big illusion. Buzz words and phrases are being thrown around like “death of documentation”, “no more governance and red tape” and “we’re reacting because we’re agile now”. When looking back at this, no-one had no idea what it meant and none of these things were particularly true. However they are said so often, usually by people who don’t understand or really want it to take off, that people start to take them as gospel. One reason this can happen is because Agile is imposed on a team without them understanding why. No team is going to do something just because they are told they must, it should be an organic process where the benefits of Agile make the team want to use it.


##### (Books) Site Reliability Engineering

```

BEST PRACTICES FOR INCIDENT MANAGEMENT

- Prioritize. Stop the bleeding, restore service, and preserve the evidence for root-causing.
- Prepare. Develop and document your incident management procedures in advance, in consultation with incident participants.
- Trust. Give full autonomy within the assigned role to all incident participants.
- Introspect. Pay attention to your emotional state while responding to an incident. If you start to feel panicky or overwhelmed, solicit more support.
- Consider alternatives. Periodically consider your options and re-evaluate whether it still makes sense to continue what you’re doing or whether you should be taking another tack in incident response.
- Practice. Use the process routinely so it becomes second nature.
- Change it around. Were you incident commander last time? Take on a different role this time. Encourage every team member to acquire familiarity with each role.
```

