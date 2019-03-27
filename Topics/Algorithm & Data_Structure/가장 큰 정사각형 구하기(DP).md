* https://programmers.co.kr/learn/courses/30/lessons/12905?language=python3#
- [[파이썬] (level4) 가장 큰 정사각형 찾기](http://whatisthenext.tistory.com/138)
- [Level 2. 가장 큰 정사각형 찾기 (Python)](https://damacho.github.io/2018/06/11/MaxSquareFinder.html)

- ref1

```python
def findLargestSquare(board):
    # 'O'에 해당하는 것을 1로, 'X'에 해당하는 값을 0으로 바꿔준다.
    table = [[1 if x == "O" else 0 for x in sub_board] for sub_board in board]
    max_square = 0
    for x in range(1, len(table)):
        for y in range(1, len(table[x])):
            # 만약 table[x][y]의 값이 0(즉, 'X')라면 정사각형을 만들 수 없으므로 건너 뛴다.
            if table[x][y] == 0:
                continue
            # 해당 좌표 기준(x,y) : 왼쪽검사(x, y-1), 위쪽 검사(x-1, y), 11시 방향 대각선 검사(x-1, y-1)
            else:
                # 최소값을 하나 뽑아낸다. 차례대로 min(왼쪽 좌표, 위쪽 좌표, 왼쪽 대각선 좌표)를 의미한다.
                _min = min([table[x][y-1], table[x-1][y], table[x-1][y-1]])
                table[x][y] = _min + 1

                # 만약, max_square보다 큰 값이 등장하면, 교체해준다.
                if max_square < table[x][y]:
                    max_square = table[x][y]

    # 넓이를 반환해야 하므로 제곱을 해서 반환한다.
    return max_square**2
```

- ref2

```python
def solution(board):
    # check whether board is consist of only zeros
    _s = 0
    for i in range(len(board)):
        _s += sum(board[i][:])
    if _s == 0:
        return 0
    
    _s = 0  # initialize _s to 0
    
    table = [[x for x in sub] for sub in board]
    for x in range(1,len(table)):
        for y in range(1, len(table[x])):
            if table[x][y] == 0:
                continue
            else:
                _min = min([table[x][y-1], table[x-1][y], table[x-1][y-1]])
                table[x][y] = _min + 1
                if _s < table[x][y]:
                    _s = table[x][y]
                    
    # if board looks like identity matrix _s would be 0, but max square would be 1.
    if _s == 0:
        return 1
    else:
        return _s ** 2
```

