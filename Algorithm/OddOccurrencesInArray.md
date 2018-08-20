* A non-empty zero-indexed array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.


- ref1

```python
def test3(A):
    if len(A) == 1:
        return A[0]

    A = sorted(A)
    for i in range(0, len(A), 2):
        if i+1 == len(A):
            return A[i]
        if A[i] != A[i+1]:
            return A[i]
```


- ref2

```python
def solution(A):
  return reduce(lambda x,y: x^y, A)
```

