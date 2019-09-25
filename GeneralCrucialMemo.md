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

#### Continuous Integration Versus Continuous Delivery Versus Continuous Deployment

- Continuous here implies automation—automation in transforming source code into deliverables, in testing and validation, and even in installing and configuring software.

- Continuous here also implies that a change can proceed, without human intervention, through the stages of builds, testing, packaging, and so on. Combined, these stages form a “pipeline” of processes and applications to take source code changes and turn them into a releasable product

- In the continuous integration (CI) phase, individual changes from a developer are merged and tested. The goal of CI is to quickly validate individual code changes that have been submitted for inclusion in the code base. An intended consequence of this is quickly identifying any problems in the code and automatically notifying the developer of problems so that the code base is not broken any longer than necessary.

- In the continuous delivery cycle, the isolated changes merged and validated during CI can be combined with the remaining product code. Then, the set is put through progressively more encompassing types of testing. The goal of continuous delivery is not necessarily to deploy the end result, but to prove that the end result is deployable. 

- Continuous deployment is a process that can be added on at the end of the continuous delivery pipeline. The idea is that since the continuous delivery pipeline has proven the latest changes to be deployable, we should automate the deployment process and go ahead and deploy the result.


#### https://www.martinfowler.com/articles/continuousIntegration.html

- If a clash occurs between two developers, it is usually caught when the second developer to commit builds their updated working copy. If not the integration build should fail. Either way the error is detected rapidly. At this point the most important task is to fix it, and get the build working properly again. In a Continuous Integration environment you should never have a failed integration build stay failed for long. A good team should have many correct builds a day. Bad builds do occur from time to time, but should be quickly fixed.

- The result of doing this is that there is a stable piece of software that works properly and contains few bugs. Everybody develops off that shared stable base and never gets so far away from that base that it takes very long to integrate back with it. Less time is spent trying to find bugs because they show up quickly.


#### http://aeternum.egloos.com/1111257

- 정리하면 VALUE OBJECT는 객체의 상태를 변경하는 메소드를 포함할 수 있다. 그러나 실제로는 메시지를 수신하는 VALUE OBJECT의 상태를 변경하는 것이 아니라 변경된 상태 결과를 포함하는 새로운 VALUE OBJECT를 생성하여 반환하는 것이다. 일반적인 REFERENCE OBJECT는 상태 변경이 가능하다. 만약 REFERENCE OBJECT가 불변이고 별칭 문제에 관해 신경 쓰고 싶지 않다면 객체에 상태 변경 메소드를 포함시키지 말아야 한다. VALUE OBJECT는 새로운 값이 필요할 때마다 값을 가진 객체를 새로 생성한다. 반면 REFERENCE OBJECT는 오직 유일한 식별자를 가진 하나의 객체만이 존재해야 한다.

#### Jack W. Reeves, What Is Software Design?

- 소프트웨어 개발 과정이 어떻게 바뀌고 있는지도 살펴보자. 옛날 옛적에, 우리는 폭포수형 프로세스(waterfall process)를 썼다. 이제 우리는 나선형 개발(spiral development)과 신속 시제품 작성(rapid prototyping)을 논하고 있다. 이런 기법이 ‘위험 완화’나 ‘단축된 제품 출하 시간’과 같은 말로 정당화되고 있지만, 사실 이런 것은 생명 주기에서 코딩을 일찍 시작하는 것에 대한 변명일 뿐이다. 좋다. 이는 설계를 검증하고 다듬기 위한 빌드/테스트 주기를 더 일찍 시작할 수 있게 해준다. 이는 또한 높은 단계의 설계를 개발하는 소프트웨어 설계자가 구체적인 설계 주위를 맴돌 가능성이 더 있음을 의미한다.

#### Robert L. Glass, 소프트웨어 공학의 사실과 오해

- 바로 여기에 문제가 있다. 만약 설계자가 코더보다 높은 수준의 기본단위를 사용한다면, 결과로 나오는 설계는 코더가 작업을 시작하는데 부적절할 것이다. 따라서 코더는 코딩을 하기 전에 적절한 수준의 설계를 추가하기 위해 시간을 소모해야 할 것이다. 이런 경우 코더는 설계자가 기대한 완전한 설계 솔루션과는 다르게 작업할 수 있으므로, 설계에서 코딩으로의 전환은 최상의 경우라도 불편할 테고, 보통은 많은 문제를 야기할 것이다.
반대의 경우도 동일한 문제가 발생한다. 만약 설계자의 경험이 부족하다면 설계자는 매우 상세한 수준의 설계를 만들 것이다. 그러나 이 설계자보다 경험이 많은 코더는 지나치게 상세한 수준의 설계를 받아들이지 않고 자신의 설계 아이디어로 대체할 것이다. 이는 설계자가 코더보다 똑똑하거나 숙련된 사람이어야 하는가에 대한 문제가 아니라, 그들이 같은 경험과 기본 단위를 가지고 있는가에 대한 문제이다.

#### Pete McBreen, 소프트웨어 장인 정신
- 작업이 더 작은 단계로 세분화될수록, 한 사람에서 또 다른 사람으로 정보를 전달하는 데에 더 많은 시간이 걸린다. 생산라인 접근 방식은 수작업 노동에는 잘 맞을 수 있다. 그러나 지적인 작업에는 형편없이 실패한다.
소프트웨어 개발은 팀원들의 머리에서 일어난다. 사람들을 특정 활동에 전문화시킴으로써 간단한 프로젝트의 딜리버리도 여러 경로를 통해야 한다. 각 경로는 실수와 결함에의 잠재성을 갖고 있는 값비싼 과정이다.

#### Robert L. Glass 소프트웨어 컨플릭트 2.0

- 그렇다면 설계의 본질은 신속한 모델링과 시뮬레이션이다. 그리고 설계의 핵심 요소는 해결책을 제안하고 실패를 허용하는 능력이다! … 직전 시뮬레이션의 끝에는 항상 실패하는 모델, 즉 문제를 풀기에 불충분한 설계안이 있다. 따라서 성공하려면 실패하는 능력과 실패를 극복하는 능력이 필수적이다. … 설계 수행 면에서, 설계자는 기존에 생각하던 설계 본질이 틀렸다는 사실을, 오히려 시행착오를 거쳐가며 반복하던 엉성한 절차가 바로 설계 핵심이라는 사실을 이해해야 한다

#### http://pds17.egloos.com/pds/201003/31/18/Domain-Driven_Design_Essence.pdf

- 제조 메타포의 두 번째 오류는 구현 전에 설계를 완성시키는 것이 가능하다고 가정하는 점이다. 그러나 실제로는 개략적인 설계를 구현으로 옮기는 도중에 전체 구조에 대한 가장 중요한 통찰을 얻게 된다. 구현 전에 대략적인 설계를 동결시키는 방식은 구현으로부터 얻게 되는 피드백을 원천적으로 차단하는 역효과를 가져온다

- 만약 설계 모델의 일부가 적용 기술 내에서 구현 불가능하다면 설계 모델을 변경해야 한다. 프로그래밍 과정 동안 설계의 실현 가능성과 정확성이 검증되고 테스트되며 그 결과 잘못된 설계가 수정되거나 새로운 설계로 대체된다. 따라서 프로그래밍은 설계의 한 과정이며 설계는 프로그래밍을 통해 개선된다.

- 애자일의 권고는 „설계하지 말라‟가 아니라 „언제나 설계하라‟다. 피드백 주기가 길어지는 사전 설계 Big Up-front Design 대싞 피드백 주기가 짧은 TDDTest-Driven Development 를
적용하라. 그리고 리팩토링 Refactoring 을 통해 설계와 코드를 지속적으로 개선함으로써 코드를 항상 최상의 상태로 유지하라. 점진적인 설계 사이클을 도입함으로써 설계와 구현을 독립적인 활동이 아닊 상호 영향을 주고 받는 유기적인 절차로 바라볼 수 있게 되었다. 따라서 경험을 기반으로 한 지속적인 리팩토링을 통해 최적의 소프트웨어의 설계를 얻을 수 있다

- 구현하기 전 설계하기의 대안은 구현한 후 설계 하기다. 어느 정도의 초기 설계가 필요하긴 하지만, 최초 구현을 시작할 수 있는 정도만 설계하면 된다. 그 이상의 설계는 구현이 자리를 잡고 설계의 진짜 제약들이 불명하게 보일 때 하도록 한다. „아무것도 설계하지 말라‟와 정반대로, XP 의 전략은 „언제나 설계하라‟다. (Kent Beck, 익스트림 프로그래밍 2nd Edition)

- 사실과 완전히 동일한 모델을 만드는 것은 바람직하지 않다. 모델은 현실이라는 기반 위에 해결하고자 하는 문제에 적합한 새로운 추상화 계층을 창조하는 과정이다.

- 모든 소프트웨어는 특정한 사용자의 문제를 해결하는 것을 목적으로 한다. 이 때 소프트웨어를 사용할 사용자의 활동이나 관심사의 대상이 되는 영역을 소프트웨어의 도메인 Domain 이라고 한다. 따라서 도메인 모델 Domain Model 이란 소프트웨어가 문제를 해결해야 하는 대상 영역을 단순화시키고 추상화시킨 것이다. 

- 소프트웨어의 본질적인 복잡성은 도메인의 복잡성에 기인한다. Frederick Brooks 의 말을 재인용하면 소프트웨어의 본질적인 문제를 외면한 상태에서 비약적인 생산성의 향상을 기대할 수는 없다. 따라서 소프트웨어의 본질적인 문제를 해결하기 위해서는 도메인을 이해하고 끊임없는 탐구를 통해 적절한 도메인 모델을 선택하는 것이 중요하다.

- 모델과 핵심 설계는 상호 영향을 주고 받으며 구체화된다. : 모델과 구현 간의 긴밀한 연결과 피드백을 통해 모델이 의미를 가지도록 하고 최종 산출물인 동작하는 프로그램이 사용자의 요구사항을 만족시킬 수 있도록 보장한다. 모델과 구현을 연결 시키는 것은 분석/설계/구현을 동일한 사이클로 묶음으로써 달성된다. 애자일의 언제나 설계하기 사상, 즉 리팩토링을 통한 점진적인 설계는 모델과 구현의 불일치를 예방하기 위한 프로세스적인 장치다. 모델과 구현이 일치하기 위해서는 모델과 코드의 표현적 차이가 적어야 한다. 코드가 인프라스트럭처에 대해 강하게 의존할 경우 모델과 코드 간의 표현적 차이가 커진다. POJO 기반의 경량 프레임워크 기술이 인프라스트럭처의 늪에서 코드를 구원한다. 모델을 기반으로 분석/설계/구현을 통합하고 피드백을 통해 개선시키는 과정을 MODEL-DRIVEN DESIGN 이라고 한다.
- 모델은 모든 팀 구성원들이 사용하는 언어의 근간을 이룬다. : 모델은 소프트웨어 지식의 집합체이며 정보 흐름의 통로다. 이해관계자들 간의 의사소통에 사용되는 언어에 변화가 생기면 모델의 용어가 변경되고, 모델의 용어가 변경되면 코드가 수정된다. 반대로 코드가 변경될 경우 모델과 의사소통에 사용되는 용어가 변경된다. 모델은 이해관계자들의 공통 언어인 UBIQUITOUS LANGUAGE 를 구성하는 기반이다.
- 모델은 불순물을 걸러낸 핵심 지식만을 포함한다. : 효과적인 도메인 모델은 끊임없는 지식 탐구 활동과 개선을 통해 얻어진다. 수많은 모델을 시도하고, 버리고, 변형한 끝에 도메인의 모든 세부 사항에 적절한 일련의 추상적 개념들을 발겫함으로써 적절한 도메인 모델을 얻게 된다. 지식 탐구 활동은 개발자와 도메인 전문가 간의 긴밀한 협력이 전제되어야 한다. UBIQUITOUS LANGUAGE 가 빛을 발휘하는 때다. 지식 탐구 활동은 끊임없이 모델과 코드를 개선하는 정제 과정이다. 모델과 코드를 긴밀히 연결함으로써 새로운 통찰이 모델과 코드에 반영되도록 할 수 있다. MODEL-DRIVEN DESIGN 이 우리를 정제의 길로 인도한다. 끊임없는 정제가 가능하기 위해서는 소스 코드를 항상 깨끗하고 안정적인 상태로 유지해야 한다. 애자일의 언제나 설계하기 사상과 불석/설계/구현 사이클의 통합, 리팩토링을 통한 점진적인 설계 방식은 이를 가능하게 한다.

- 모델과 코드의 개념적 거리가 멀어지면 멀어질수록 소프트웨어는 도메인과 멀어지고, 도메인 전문가와 개발자는 서로 간의 개념을 일치시키기 위해 번역 과정을 거쳐야 하므로 의사소통이 어려워지고 유지보수가 어려운 코드를 얻게 된다. 모델을 기반으로 코드를 작성하되 모델과 코드를 동기화하기 위해 모든 노력을 쏟아라.

- 구현에 관여하는 사람들은 모델링 작업에 직접 참여해야 한다. 두 역할을 불리할 경우 모델링 작업에서 얻어지는 지식이 코드에 반영되지 못한 찿 소리 없이 사라져 버리게 된다. 또한 구현 과정에서 얻어지는 통찰을 모델에 반영할 수 없게 되므로 결과적으로 코드와 모델 간의 연결 고리가 점점 약해지게 된다. 코드는 모델이며, 모델은 코드다. 극단적인 흑백논리는 소프트웨어 개발에 있어 최대의 적이다.

- 모델을 언어의 기반으로 삼아라. 팀에서 이루어지는 모든 의사소통과 코드에 적극적으로 공통의 언어를 적용하라. 다이어그램과, 문서화, 특히 대화에 동일한 언어를 사용하라. (Eric Evans, Domain-Driven Design)

- 여러 가지 모델을 반영하는 다른 표현을 실험해봄으로써 공통 언어 선택에 따르는 어려움을 해소하라. 그 후 새로운 모델에 적합하도록 클래스, 메서드, 모듈의 이름을 변경하여 코드를 리팩토링하라. 일상에서 사용하는 용어를 다르게 사용할 경우 의미에 대한 공감대를 형성하는 것과 동일한 방식으로 대화에 사용하는 용어 상의 혼란 역시 해결하라. (Eric Evans, Domain-Driven Design)

- UBIQUITOUS LANGUAGE 의 변경은 곧 모델의 변경이라는 사실을 인식하자. (Eric Evans, Domain-Driven Design)

- UBIQUITOUS LANGUAGE 상의 용어에 변경이 발생하면 곧 모델, 코드에 대한 변경으로 파급되어야 한다. 역으로 코드에 사용된 어떤 용어가 수정될 경우 변경 사항은 모델과 UBIQUITOUS LANGUAGE 로 파급되어야 한다.

- 개발자들이 도메인에 대한 통찰을 얻기 위해 적용할 수 있는 체계적인 사고 방법이 존재한다. 무질서하게 뻗어 나가는 소프트웨어 애플리케이션에 질서를 부여할 수 있는 설계 기법 역시 존재한다. 이럮 기술을 연맀한다면 익숙하지 않은 도메인을 접하게 될 경우에도 더 가치 있는 개발자로 발전할 수 있게 될 것이다. (Eric Evans, Domain-Driven Design)

#### Patterns, Principles and Practices of the Domain-Driven Design

- Be wary of customers asking for enhancements to existing software, because they will often give you requirements that are based on the constraints of the current systems rather than what they really desire. 

- You are the enabler. Don’t blindly follow the user’s requirements. Business users may not be able to write effective features or effectively express goals. You must share and understand the underlying vision and be aware of what the business is trying to achieve so you can create real business value.

- Ask powerful questions and learn the intent of the business. Don’t simply implement a set of requirements but actively engage with the business; work with them, not for them.

- Experiment in code to prove the usefulness of the model and to give feedback on the compromises that a model needs to make for technical reasons.

- In order to understand the most valuable areas of a problem domain we need to distill it to reveal what is core. By breaking up the large problem domain we can more effectively resource the different areas to ensure the most talented developers are working in the areas of most importance to the business rather than the areas that may be more technically challenging or that utilize new frameworks of infrastructure.

- DDD is all about reducing complexity; a single monothlic model would increase complexity. Instead you should break the problem domain down so that you are able to create smaller models in the solution space.

- Try not to bring technical concerns into conversation when you are analyzing the problem space. Security is a technical concern unless your problem space is security.

- The areas that distinguish your company’s unique product offering from a rival’s and define what gives it a competitive edge in the market are known as your core domains. 

- Don’t waste time and effort on refactoring all of your code—ensure your primary focus is on the core domain. If you end up with working but “messy code” for supporting and generic domains then leave it alone.

- Leaving small silos of BBoM is fine as long as they are within clearly defined boundaries. Perfection is an illusion. Perfection should be reserved for only what is core. The business doesn’t care about quality code for areas that are required but are not key to the system and which are unlikely to be invested in over time.

- If you have areas of an application that resemble the BBoM pattern then the best thing to do is to put a boundary around them to prevent the mud spreading into new areas of the application

- In an ideal world, quality software would always be top of your agenda; however, it’s important to be pragmatic. Sometimes a new system’s core domain could be first to market, or sometimes a business may not be able to tell if a particular idea will be successful and become core to its success. In this instance, the business wants to learn quickly and fail fast without putting in a lot of up-front effort.

- DDD acknowledges the need to produce a single model that serves as an analysis model for business people to understand and which is implemented using the same terminology and concepts in code.

- Model-Driven Design differs from DDD in that it is focused on implementation and any constraints that may require changes to an initial model, whereas DDD focuses on language, collaboration, and domain knowledge.

- The true value of following the Domain-Driven Design (DDD) philosophy is in the collaboration of developers and domain experts to produce a better understanding of the domain