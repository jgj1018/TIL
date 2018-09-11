#### Backtracking

* Backtracking is a form of recursion that is particularly useful for types of problems such as traversing tree structures, where we are presented with a number of options at each node, from which we must choose one. Subsequently we are presented with a different set of options, and depending on the series of choices made either a goal state or a dead end is reached. If it is the latter, we must backtrack to a previous node and traverse a different branch. Backtracking is a divide and conquer method for exhaustive search. Importantly backtracking prunes branches that cannot give a result.An example of back tracking is given in the following example. Here, we have used a recursive approach to generating all the possible permutations of a given string, s, of a given length n:

```
def bitStr(n,s):
	if n == 1: return s
    return [digit + bits for digit in bitStr(1,s) for bits in bitStr(n-1, s)]
```
