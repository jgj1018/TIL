* An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).


- ref1

```python
def solution(A, K):
    # write your code in Python 2.7
    if len(A) == 0:
        return A
    K = K % len(A)
    return A[-K:] + A[:-K]
```


- ref2

```python
def solution(a,k):
    length= len(a)
    temp1=0
    b=[]
    for i in range(length):     
        p=k+i
        if p>=length:
            p=p%length
        b.insert(p,a[i])
    return b
```


- ref3

```python
def solution(A, K):
    N = len(A)
    if (N == 0):
        return A
    K = K%N
    first = A[N-K:]
    last = A[:N-K]
    return first+last
```