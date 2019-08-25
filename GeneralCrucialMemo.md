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

- You can’t “fix” people, but you can fix systems and processes to better support people making the right choices when designing and maintaining complex systems.

#### 디지털 마케팅 개론 - 김진&최정아

- 마케팅의 본질은 소비자가 느끼는 욕구를 해결하는 제품과 서비스를 개발하여, 그 가치를 해당 고객에게 전달하는 것이다. 바꿔 말하면 고객과 제품/서비스 그리고 채널을 올바르게 이어주는 활동이라 할 수 있다.

- 마케팅은 고객, 제품, 메시지, 채널의 4가지 요소를 전략적으로 잘 활용하여 제품 및 서비스에 대한 마케팅 효과(인지도 제고, 가입자 확보, 판매 매출 증대 등) 을 향상시키는 일련의 과정이다.

- 가장 먼저 소비자가 느끼는 다양한 문제점을 공감하고 목표 고객을 정의한다. 둘째로 해당 소비자 그룹의 문제를 해결하기 위한 가치있는 제품/서비스가 준비되어야 하며, 셋째로 제품/서비스의 핵심 가치를 잘 전달하기 위한 메시지를 개발한다.

- 목표 고객의 문제를 해결해주는 제품의 핵심 가치에 대한 메시지를 가장 효과적인 채널을 통해 전달하는 것, 이것이 마케팅의 기본이다.

- 디지털 마케팅을 조직 내에 정착시키려면 무엇보다 조직 구조의 문화가 중요하다. 기업은 마케팅 목적을 분명하게 정의할 수 있어야 하고, 마케터에게 KPI(Key Performance Indicator)를 명확히 할당하며, 각각의 KPI를 측정할 수 있는 도구를 제공해야 한다. 더불어 (...) 구글 애널리틱스, R 등의 분석 도구로 측정하는 데이터를 기반으로 기업의 의사 결정이 이루어지는 조직 문화가 형성되어야 한다.

- 데이터 분석으로 고객을 이해하고 제품의 핵심 가치를 적절히 표현하는 마케팅 메시지를 준비했다면 이제 효과적인 채널을 선택할 차례이다. 앞서 살펴본 바와 같이 디지털 마케팅 채널은 크게 다섯가지로 분류된다. 메시지의 생산과 채널 관리 주체가 기업인 Create 채널, 누가 만든 메시지든 해당 메시지를 배포하는 주체는 일반 대중인 Share 채널, 비용을 지불하여 단기간에 대량으로 도달시키는 물량 공세가 가능한 Push 채널, 식별된 고객과 우호적인 관계를 구축함으로써 전환률과 광고수익률(ROAS)을 높이는 Communication 채널, 미리 설정된 규칙에 따라 개인 맞춤형 메시지를 시의적절하게 도달시키고 마케터의 업무 부담을 줄여주는 Automation채널이다.

- 정리하자면 온라인 사업의 목표를 크게 보아 전자상거래, 리드 확보, 고객 서비스, 콘텐츠 서비스 4가지로 요약된다. 어떤 목표를 가졌든 디지털 마케팅의 5가지 채널 중 일부만 활용하는 것보다 모든 채널을 고르게 활용함으로써 가장 높응 성과를 이룰 수 있다. 그러나 기업의 자원은 한정되어 있으므로 채널의 성과에 따라 적절히 분배해야 하는 것도 현실이다.

- 오늘날의 디지털 마케팅은 인간의 감(gut feeling)과 어림짐작이 아닌 고객 행동 데이터 분석 결과를 토대로 의사 결정이 이루어진다. 디지털 마케팅의 복잡한 단계가 간소해질 뿐만 아니라 구체적인 실행의 많은 부분이 자동화되어 인간의 수작업이 줄어 들었다. 고객 한 사람 한 사람의 요구에 민감하게 반응하는 것이 가능해짐에 따라 개인 맞춤형 마케팅이 강세를 보이게 되었다.

- 디지털 마케팅도 기업 활동의 일환이므로 기업의 전략적 목표와 긴밀하게 연관되어야 한다. 

- 디지털 마케팅이란 제품이 가진 핵심 가치와 그것을 구매해줄 적합한 고객을 찾아 제품을 가치를 설명하고 고객을 설득하기 위한 채널 전략을 수립하고 고객과 커뮤니케이션하는 활동이다.

- 디지털 마케팅과 데이터 분석은 불가분의 관계이다. 디지털 마케팅의 커다란 특징 중 하나는 성과 측정과 실시간 대응이다. 모든 디지털 채널이 온라인상에서 사람들이 남기는 각종 활동 기록을 추적하고 체계적으로 데이터베이스화 할 수 있다. 인터넷 활동 기록은 쿠키에 남고, 픽셀이라 불리는 고객행동 추적 이미지가 고객 행동을 모니터링하며, 네트워크의 다양한 정보는 DMP에게 수집되어 분류된다. 고객에 대한 각종 데이터를 마케터가 이해하기 쉽도록 시각화 하여 제공하는 클라우드 기반의 여러 유무료 서비스가 이미 시장에 나와 있다. 기업은 목표 고객의 온라인상 발자취를 쫓아 고객의 관심사, 활동 이력, 인구통계학적 정보 및 구체적인 상황에서의 고객 행동 패턴에 대한 정보를 입수하고 분석한다. 이를 토대로 마케팅 캠페인을 기획 집행할 수 있다. 

- 채널이 달라지고 디지털 마케팅으로 패러다임이 바뀌었지만 여전히 마케팅을 주도하는 것은 기술이 아니라 고객과의 지속적인 관계를 추구하는 기업의 의지이다. 기술은 목적이 아니라 도구이기 떄문이다. 

- 분석된 데이터 자체는 중립적이다. (...) 데이터가 다루는 층위는 매우 다양하여 하나의 원리에서 자동적으로 결론이 도출될 수는 없다. (...) 결과를 해석할 수 있는 인간의 깊이 있는 통찰이 요구된다. 그러므로 복잡한 데이터 분석 결과를 의사 결정에 활용할 수 있도록 간결하게 시각화할 줄 알아야 하고, 나아가 각각의 데이터를 만들어 낸 개별 고객을 위한 마케팅 메시지를 어떤 형태로 개인화하여 디지털 채널에 재전송할 것인가 고민해야 한다. 