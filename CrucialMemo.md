##### https://medium.com/@muneeb.ahmed20/building-a-reporting-service-in-microservice-architecture-8d5bf3b90fb7

- Reporting service is never bounded to timely consistent data it moreover bounded towards availability of data if talking in terms of CAP theorem. In a microservice architecture, if designed correctly whenever the state of an application changed an event is published to event processor (Kafka) and consumed by multiple application. First and foremost thing is to design a reporting database correctly and then write a master listener which reads from each topic in Kafka and update the reporting database correctly. These master listeners are just workers that read messages from different topics in Kafka and update the database with the right information. As already discussed reporting database requires availability instead of consistency. Information will be consistent after some time depending on the workers’ throughput.

##### https://martinfowler.com/bliki/MonolithFirst.html

- A more common approach is to start with a monolith and gradually peel off microservices at the edges. Such an approach can leave a substantial monolith at the heart of the microservices architecture, but with most new development occurring in the microservices while the monolith is relatively quiescent. 



