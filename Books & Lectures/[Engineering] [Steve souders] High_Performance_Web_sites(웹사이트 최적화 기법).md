#### Chapter 0A 앞단 성능의 중요성

* 현실적으로 대부분의 웹 페이지는 최종 사용자의 반응 시간(브라우저 반응 시간) 중 HTML 문서를 웹 서버로부터 다운로드받는 데 소요되는 시간이 10% ~ 20%도 채 되지 않는다. (...중략...) 브라우저는 HTML을 분석하고 페이지 안에 포함되어 있는 이미지, 스크립트, 스타일시트와 같은 HTML 구성요소를 다운받기 시작한다. (...중략...) HTTP 트래픽을 보는 방법을 통하여 최종 사용자 응답 시간의 80%는 페이지 안의 구성요소를 다운받는 데 소비되는 것을 알 수 있었다.


* HTTP 문서를 요청하기 위한 HTTP 요청 바로 다음에 오는 빈 공간을 볼 수 있다. 이것은 브라우저가 HTML, 자바스크립트, CSS를 파싱하고 캐시로부터 이런 구성요소를 불러오는(읽는) 시간이다.


* 스크립트는동시 다발적으로 요청하지 않는다. 그 이유는 스크립트가 다운로드 중인 경우에 브라우저는 대부분 추가적인 HTTP 요청을 막기 때문이다.

#### Chapter 0B HTTP의 이해

* 조건부 GET 요청 : 브라우저 캐시에는 구성요소의 복사본이 있지만 그 구성요소가 유효한지 확실하지 않을 경우 조건부 GET 요청을 보낸다. (...) 일반적으로 캐시된 구성요소의 유효성은 최종 수정 날짜로 판단된다. 브라우저는 구성요소가 마지막으로 언제 수정되었는지를 응답 헤더의 Last-Modified 항목을 통해 알 수 있다. 브라우저는 If-Modified-Since라는 헤더 속성을 통해서 서버로 최종 수정 날짜를 보내게 된다. (...) 구성요소가 지정한 날짜로부터 수정되지 않았다면 서버는 "304 Not Modified"라는 상태 코드를 반환하게 된다.


* 조건부 GET 요청과 304 응답은 페이지를 더 빠르게 로드할 수 있게 도와주지만 유효성을 확인하려면 여전히 클라이언트과 서버간의 요청/응답의 왕복이 필요하다. 하지만 헤더 만료기한(Expires)은 서버로 접근하여 구성요소의 유효성을 확인하는 작업을 생략할 수 있게 해주고 브라우저는 캐시의 복사본이 아직 유효한지 바로 알 수 있게 해 준다.


* 페이지 안의 대부분의 이미지는 공통된 이미지 서버에 요청을 보내게 된다. 지속성 있는 연결(Persistent connections)은 이렇게 같은 서버에 여러 개의 소켓 연결을 맺는 비효율 문제를 해결하기 위해 나왔다. 즉 하나의 연결 안에 여러 개의 요청을 보내는 것이다. 브라우저와 서버는 헤더의 Connection 속성에 Keep-Alive값을 지정할 수 있다. (...) 이것은 HTTPS에서 더 중요한데. 보안 소켓 연결은 더 많은 시간을 필요로 하기 때문이다.

#### 규칙 1 HTTP 요청을 줄여라
#### 규칙 2 콘텐츠 전송 네트워크를 이용하라

* 구성요소가 저장되어 있는 웹서버가 사용자와 가깝다면 여러 개의 HTTP 요청 시간이 짧아질 것이다. (...) CDN(콘텐츠 전송 네트워크)은 사용자에게 효율적으로 콘텐츠를 전달하기 위하여 여러 지역에 웹 서버를 분산시켜 놓는 기술이다. (...) 응답 시간을 줄이는 것 외에도 CDN 서비스는 백업, 저장 용량의 확대, 캐싱과 같은 기능을 포함한다. (...) CDN에 의존하류경우의 단점은 다른 웹 사이트의 트래픽에 내 사이트가 영향을 받을 수 있다는 것이다. CDN은 이미지, 스크립트, 스타일시트, 플래시와 같은 정적 콘텐츠를 전달할 때 이용 된다. (...) 정적 파일은 호스트에서 쉽게 이용될 수 있고 의존적인 요소도 거의 갖고 있지 않다. 그렇기 때문에 CDN을 쉽게 도입할 수 있고 지리적을 ㅗ분산된 사용자의 응답시간을 더 쉽게 개선할 수 있다.

#### 규칙 3 헤더에 만료기한을 추가하라

* 헤더의 Expires 속성은 지정된 날짜를 이용하기 때문에 서버와 클라이언트 간에 시간을 맞추어서 이용해야만 하는 문제점이 있다. (...) 대신에 Cache-Control은 max-age 속성을 설정하여 구성요소를 얼마 동안 캐시에 보관할지를 설정한다. 이 시간은 초 단위로 지정한다.


* 여러분ㅇ리 서버의 구성요소를 변경하더라도 이미 웹사이트에 방문했던 사용자는 만료기한이 지나기 전까지는 최신 버전의 구성요소를 받지 않는다는 것이다. 여기서 사용자가 최신 버전의 구성요소를 다시 받아볼 수 있게 하기 위해서는 HTML 페이지의 모든 파일 이름을 변경해 주면 된다.

* 만약 구성요소 헤더에 Expires가 지정되지 않았다 하더라도 브라우저 캐시에 여전히 보관된다. 그리고 다음 요청이; 오면 브라우저에서 구성요소의 날짜를 찾아 만료되었는지 확인한다. 효율적인 작업을 위해서 브라우저는 서버로 조건부 GET 요청을 보내게 된다. (역자 주: 헤더를 이용할 떄의 차이점이 바로 서버로 확인 요청을 보내고 안 보내고의 차이라고 보면 된다. 따라서 헤더의 Expires를 지정할 경우 구성요소를 확인하는 추가적인 GET 요청조차 보내지 않기 때문에 더 빠른 성능을 낼 수 있다.


#### 규칙 4 Gzip 컴포넌트

* HTTP 요청 결과로 받게 되는 응답 크기가 줄어들면 서버에서 클라이언트로 보내는 패킷 자체가 감소하기 때문에 전달 시간을 줄일 수 있게 된다. (...) HTTP 1.1에서부터 웹 클라이언트는 HTTP 요청의 Accept-Encoding 헤더를 이용해 압축의 지원 여부를 보내주게 된다.

```
	Accept-Encoding: gzip, deflate
```

* (...) 웹 서버는 응답 헤더 안의 Content-Encoding 속성을 통하여 웹 클라이언트에게 사용된 압축 방식을 알려준다.

```
	Content-Encoding: gzip
```

* 많은 웹사이트는 HTML 문서를 gzip으로 압축한다. 그리고 gzip은 스크립트와 스타일시트 또한 활용할 수 있지만 많은 웹사이트가 적용하지 않고 있다. (...) gzip을 이용할 경우 서버에서 압축을 적용하고 클라이언트에서 압축을 해제하기 위한 추가적인 CPU 비용이 들어간다. (...) 일반적으로 gzip은 1~2KB 보다 큰 파일일 경우에 적용해 볼 만한 가치가 있다.


* 웹 서버 응답 헤더에 Vary 속성을 추가로 지정하는 것이다. 이 설정은 프록시로 하여금 받은 요청의 헤더에 따라 응답을 바꾸어 전달하도록 명령한다. 압축 여부는 요청 헤더의 Accept-Encoding 속성에 의해 결정되기 때문에 서버의 Vary 응답 헤더의 Accept-Encoding을 포함하는 것이 맞다.


* 다른 접근 방법은 Vary: * 또는 Cache-Control: private 헤더를 이용하여 명시적으로 프록시 캐시를 사용하지 않도록 설정하는 것이다. Vary: * 헤더는 브라우저 캐시가 저장된 구성요소를 아예 사용하지 못하게 하기 때문에, Cache-Control: private가 더 선호되고 있고 구글과 야후에서도 이 방식을 사용하고 있다.


#### 규칙 5 스타일시트는 위에 넣어라

* 스타일시트는 LINK 태그를 이용하여 문서의 HEAD 영역에 넣어야 한다. (...) 인터넷 익스플로러가 필요한 구성요소를 모두 다운받았음에도 불필요한 스타일시트를 다운받을 때까지 랜더링을 멈추고 기다린다. 페이지 안의 스타일시트 위치를 다운로드 시간에 영향을 주지 않지만 렌더링에는 영향을 준다는 것이다.

#### 규칙 6 스크립트는 아래에 넣어라

* HTTP/1.1 스펙에서는 한 호스트당 동시에 2개의 구성요소를 다운로드하는 것을 제안하고 있다. 많은 웹 페이지의 구성요소는 보통 하나의 호스트 이름을 갖고 있다. 이러한 HTTP 요청은 계단 패턴대로 다운로드 하게 된다. 웹 페이지가 2개의 호스트 이름을 사용하고 구성요소의 비중도 반씩 나누어져 있다면 으답 속도가 두 배 빠를 것이다.


* 동시 다운로드를 최대화하는 것은 추가 비용 없이 얻어지진 않는다. 대신 대역폭과 CPU 속도에 의존하기 때문에 동시에 너무 많은 다운로드를 실행하게 되면 성능이 떨어질 수 있다.


* 스크립트가 다운로드되는 동안에는 동시 다운로드가 불가능하다. 그리고 브라우저는 다른 호스트 이름이라 하더라도 추가적인 다운로드 요청을 하지 않는다.


* 스크립트를 페이지 아래에 넣는 것이 가장 좋다. 페이지 렌더링의 방해를 받지 않고 페이지 안에서 눈에 보이는 구성요소는 가능한 한 일찍 다운로드 된다.


* 경우에 따라서는 스크립트를 아래로 옮기는 것이 쉽지 않을 수도 있다. 예를 들어 스크립트가 document.write 를 이용하여 콘텐츠를 삽입한다고 하면 더 아래로 이동할 수 없게 될 것이다. (...) 대안으로 자주 언급되는 방법은 defer를 이용하는 스크립트를 사용하는 것이다. defer 속성은 스크립트 안에 document.write를 포함하지 않는 스크립트를 뜻하며 브라우저는 계속 렌더링을 할 수 있게 된다.

#### 규칙 7 CSS Expression을 피하라

#### 규칙 8 자바스크립트와 CSS를 외부 파일에 넣어라

* 자바스크립트와 CSS가 외부 파일로 브라우저에 캐시되어 있다면 추가적인 HTTP 요청도 없을 뿐만 아니라 HTML 문서의 크기를 줄일 수 있다.

* 사용자당 페이지 뷰가 적을 경우 인라인 자바스크립트와 CSS를 이용하는 것이 더 좋다. (...) 반면에 사용자의 페이지 뷰가 많다면 브라우저는 캐시 안에 외부 구성요소를 보관하고 있을 경우가 더 많을 것이다.

* 모든 페이지에서 같은 자바스크립트와 CSS를 이용한다면 외부 파일을 사용하는 것이 재사용 면에서는 더 높은 효율을 보일 것이다. 그 이유는 사용자가 페이지를 돌아다니는 동안 자바스크립트와 CSS 구성요소는 브라우저 캐시 안에 이미 존재하기 때문이다.
