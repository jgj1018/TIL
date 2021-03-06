### 3.7 기준 포인트 요약

* https://docs.python.org/ko/3/library/functions.html

##### all(iterable)
* iterable 의 모든 요소가 참이면 (또는 iterable 이 비어있으면) True 를 돌려줍니다.

##### any(iterable)
* iterable 의 요소 중 어느 하나라도 참이면 True 를 돌려줍니다.

##### bin(x)
* 정수를 "0b" 가 앞에 붙은 이진 문자열로 변환합니다. 접두어 "0b" 가 필요할 수도, 필요 없을 수도 있다면, 다음 방법을 사용할 수 있습니다.

```python
>>> bin(3)
'0b11'
>>> bin(-10)
'-0b1010'

>>> format(14, '#b'), format(14, 'b')
('0b1110', '1110')
```

##### chr(i) 
* 유니코드 코드 포인트가 정수 i 인 문자를 나타내는 문자열을 돌려줍니다. 예를 들어, chr(97) 은 문자열 'a' 를 돌려주고, chr(8364) 는 문자열 '€' 를 돌려줍니다. 이 것은 ord()의 반대입니다.

##### setattr(object, name, value)

* 이것은 getattr() 과 한 쌍입니다. 인자는 객체, 문자열 및 임의의 값입니다. 문자열은 기존 어트리뷰트 또는 새 어트리뷰트의 이름을 지정할 수 있습니다. 이 함수는 객체가 허용하는 경우 값을 어트리뷰트에 대입합니다. 예를 들어, setattr(x, 'foobar', 123) 는 x.foobar = 123 과 동등합니다.

* 자매품 getattr, delattr

##### dir([object])
* 인자가 없으면, 현재 지역 스코프에 있는 이름들의 리스트를 돌려줍니다. 인자가 있으면, 해당 객체에 유효한 어트리뷰트들의 리스트를 돌려주려고 시도합니다. 객체에 __dir__() 메서드가 있으면, 이 메서드가 호출되는데, 반드시 어트리뷰트 리스트를 돌려줘야 합니다. 객체가 __dir__() 을 제공하지 않으면, 함수는 (정의되었다면) 객체의 __ dict__ 어트리뷰트와 형 객체로부터 정보를 수집하기 위해 최선을 다합니다.


##### divmod(a, b)
* 두 개의 (복소수가 아닌) 숫자를 인자로 취하고 정수 나누기를 사용할 때의 몫과 나머지로 구성된 한 쌍의 숫자를 돌려줍니다. 두 인자의 형이 다른 경우, 이 항 산술 연산자에 대한 규칙이 적용됩니다. 정수의 경우, 결과는 (a // b, a % b) 와 같습니다.

##### enumerate(iterable, start=0)
* 열거 객체를 돌려줍니다. iterable 은 시퀀스, 이터레이터 또는 이터레이션을 지원하는 다른 객체여야 합니다. enumerate() 에 의해 반환된 이터레이터의 __next__() 메서드는 카운트 (기본값 0을 갖는 start 부터)와 iterable 을 이터레이션 해서 얻어지는 값을 포함하는 튜플을 돌려줍니다.

```python
>>> seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]
```

* 이하와 동등

```python
def enumerate(sequence, start=0):
    n = start
    for elem in sequence:
        yield n, elem
        n += 1
```

##### filter(function, iterable)
* function 이 참을 돌려주는 iterable 의 요소들로 이터레이터를 구축합니다. iterable 은 시퀀스, 이터레이션을 지원하는 컨테이너 또는 이터레이터 일 수 있습니다. function 이 None 이면, 항등함수가 가정됩니다, 즉, 거짓인 iterable 의 모든 요소가 제거됩니다.

```python
li = [-2, -3, 5, 6]

# 양수만 반환하는 리스트
def ft(li):
    result = []
    for e in li:
        if e > 0:
            result.append(e)
        else:
            pass
    return result


# filter 함수 사용시
def positive(x):
  return x > 0

list(filter(positive, li))

# filter + lambda 함수 사용시
list(filter(lambda x: x > 0, li))
```

##### globals()
* 현재 전역 심볼 테이블을 나타내는 딕셔너리를 돌려줍니다. 이것은 항상 현재 모듈의 딕셔너리입니다 (함수 또는 메서드 내에서, 이 모듈은 그것들을 호출하는 모듈이 아니라, 그것들이 정의된 모듈입니다).

##### hash(object)
* 객체의 해시값을 돌려줍니다 (해시가 있는 경우). 해시값은 정수다. 딕셔너리 조회 중에 딕셔너리 키를 빨리 비교하는 데 사용됩니다. 같다고 비교되는 숫자 값은 같은 해시값을 갖습니다

##### hex(x)
* 정수를 "0x" 접두사가 붙은 소문자 16진수 문자열로 변환합니다. 정수를 대문자 또는 소문자 16진수로, 접두사가 있거나 없는 형태로 변환하려면 다음 방법을 사용할 수 있습니다.

```python
>>> hex(255)
'0xff'
>>> hex(-42)
'-0x2a'

>>> format(255, '#x'), format(255, 'x'), format(255, 'X')
('0xff', 'ff', 'FF')
```

##### id(object)
* 객체의 "아이덴티티"를 돌려준다. 이것은 객체의 수명 동안 유일하고 바뀌지 않음이 보장되는 정수입니다. 수명이 겹치지 않는 두 개의 객체는 같은 id() 값을 가질 수 있습니다.


##### isinstance(object, classinfo)
* object 인자가 classinfo 인자 또는 그것의 (직접, 간접 혹은 가상) 서브 클래스의 인스턴스면 참을 돌려줍니다. object 가 주어진 형의 객체가 아니면, 함수는 항상 거짓을 돌려줍니다. classinfo 가 형 객체들의 튜플 (또는 재귀적으로 이런 종류의 튜플이 중첩된 튜플) 이면, object 가 그 형 중 어느 하나의 인스턴스일 때 참을 돌려줍니다.

##### issubclass(class, classinfo)
* class 가 classinfo 의 서브 클래스 (직접, 간접 또는 가상)면 참을 돌려줍니다. 클래스는 그 자체의 서브 클래스로 간주합니다. classinfo 는 클래스 객체의 튜플 일 수 있습니다. 

##### iter(object[, sentinel])
* 이터레이터 객체를 돌려줍니다. 첫 번째 인자는 두 번째 인자의 존재 여부에 따라 매우 다르게 해석됩니다. 두 번째 인자가 없으면, object 는 이터레이션 프로토콜 (__iter__() 메서드)을 지원하는 컬렉션 객체이거나 시퀀스 프로토콜 (0에서 시작하는 정수 인자를 받는 __getitem__() 메서드)을 지원해야 합니다. 이러한 프로토콜 중 아무것도 지원하지 않으면 TypeError 가 일어납니다. 두 번째 인자 sentinel 이 주어지면, object 는 콜러블이어야 합니다. 이 경우 만들어지는 이터레이터는 __next__() 메서드가 호출될 때마다 인자 없이 object 를 호출합니다; 반환된 값이 sentinel 과 같으면, StopIteration 을 일으키고, 그렇지 않으면 값을 돌려줍니다.


```python
with open('mydata.txt') as fp:
    for line in iter(fp.readline, ''):
        process_line(line)
```

##### map(function, iterable, ...)
* iterable 의 모든 항목에 function 을 적용한 후 그 결과를 돌려주는 이터레이터를 돌려줍니다. 추가 iterable 인자가 전달되면, function 은 그 수 만큼의 인자를 받아들여야 하고 모든 이터러블에서 병렬로 제공되는 항목들에 적용됩니다. 다중 이터러블의 경우, 이터레이터는 가장 짧은 이터러블이 모두 소모되면 멈춥니다.

##### oct(x)
* 정수를 "0o"로 시작하는 8진수 문자열로 변환합니다. 결과는 올바른 파이썬 표현식입니다. x 가 파이썬 int 객체가 아니면, 정수를 돌려주는 __index__() 메서드를 정의해야 합니다.
* 정수를 접두사 "0o"가 있거나 없는 형태의 8진수 문자열로 변환하려면, 다음과 같이 표현할 수 있습니다.

```python
format(10, '#o'), format(10, 'o')
# ('0o12', '12')
```

##### ord(c)
* 하나의 유니코드 문자를 나타내는 문자열이 주어지면 해당 문자의 유니코드 코드 포인트를 나타내는 정수를 돌려줍니다. 예를 들어, ord('a') 는 정수 97 을 반환하고 ord('€') (유로 기호)는 8364 를 반환합니다. 이것은 chr() 의 반대입니다.


##### pow(x, y[, z])
* x 의 y 거듭제곱을 돌려줍니다; z 가 있는 경우, x 의 y 거듭제곱의 모듈로 z 를 돌려줍니다 (pow(x, y) % z 보다 더 빠르게 계산됩니다). 두 개의 인자 형식인 pow (x, y) 는 거듭제곱 연산자를 사용하는 것과 동등합니다: x ** y.

```python
>>> pow(2,3,3)
2
>>> pow(2,3)
8
```

##### zip(*iterables)

* 각 iterables 의 요소들을 모으는 이터레이터를 만듭니다. 튜플의 이터레이터를 돌려주는데, i 번째 튜플은 각 인자로 전달된 시퀀스나 이터러블의 i 번째 요소를 포함합니다. 이터레이터는 가장 짧은 입력 이터러블이 모두 소모되면 멈춥니다. 하나의 이터러블 인자를 사용하면, 1-튜플의 이터레이터를 돌려줍니다. 인자가 없으면, 빈 이터레이터를 돌려줍니다. 

* zip()을 * 연산자와 함께 쓰면 리스트를 unzip 할 수 있습니다:

```python
>>> x = [1, 2, 3]
>>> y = [4, 5, 6]
>>> zipped = zip(x, y)
>>> list(zipped)
[(1, 4), (2, 5), (3, 6)]
>>> x2, y2 = zip(*zip(x, y))
>>> x == list(x2) and y == list(y2)
True
```