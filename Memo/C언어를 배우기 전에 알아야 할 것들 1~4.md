
- [C 언어를 배우기 전에 알아야 할 것들](https://www.youtube.com/watch?v=V_oM9ePJyP8)

### 왜 컴퓨터가 2진법을 사용하는가?

- 강의 설명 : 컴퓨터가 전자식으로 구성되어 있기 때문에. 전기 신호는 1과 0
- 추가 조사 내용 : https://madplay.github.io/post/2017/12/29/001 (전압의 안정성을 담보하기 위해)
- 8 bits = 1 byte = 영문 1글자 담을 수 있는 기억공간의 크기

### 왜 컴퓨터는 16진법을 사용하는가? 

- 2진수로는 자릿수를 너무나 많이 차지하기 때문에 16진수로 바꿔서 표현함. 
- 추가 조사 내용 : (http://greenalice.tistory.com/210) 
- 2진수와 16진수의 변환 시 4bits씩 끊어서 계산할 것. 
- 0x는 16진수로 숫자를 표현함을 의미한다. 

```
10010110 = 0x96 
10110011 = 0xB3 
```

### 왜 2의 보수를 사용하는가?

- 반가산기 전가산기 : 사칙연산의 베이스
- 추가 조사 내용 1 (보수) : (http://sessionk.tistory.com/126)
- 추가 조사 내용 2 (보수, 고정 소수점) : (http://ndb796.tistory.com/4)
- 추가 조사 내용 3 (반가산기 전가산기) : (http://raisonde.tistory.com/entry/%EB%B0%98%EA%B0%80%EC%82%B0%EA%B8%B0Half-adder%EC%99%80-%EC%A0%84%EA%B0%80%EC%82%B0%EA%B8%B0Full-adder)

### etc

- 실행이란 결국은 cpu가 하는 연산.
- 사용자 명령 -> HHD 내의 실행 이미지(기계어) 를 주기억 장치에 로드  -> Instance 생성(Instance는 보통 프로세스에 일치) -> cpu가 해당 기계어 코드 실행
- 추가 조사 내용 1 (32비트 컴퓨터와 64비트 컴퓨터의 차이점) : (http://thrillfighter.tistory.com/116)

