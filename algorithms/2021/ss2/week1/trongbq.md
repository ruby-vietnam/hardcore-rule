# Week 1

## Problem 1
https://leetcode.com/problems/find-the-town-judge/

We use hashmap with value is a list to represent a list of people that this person trust, this is a directed graph.

There are two properties that can be used to identify judge:

1. Judge does not trust anyone -> we look for any vertex that contains an empty list of trusting person.
2. All people trust judge -> we build another hashmap for a directed graph which is reversed from original, so if person a trust person b then there is a connection from b to a. We then will look for a vertex which have length of `n-1`.

```python
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 0:
            return -1
        
        a = defaultdict(lambda: [])
        b = defaultdict(lambda: [])
        
        for pair in trust:
            a[pair[0]].append(pair[1])
            b[pair[1]].append(pair[0])
        
        for person in range(1, n+1):
            if len(a[person]) == 0 and len(b[person]) == n-1:
                return person
        return -1
```
```
92 / 92 test cases passed.
Status: Accepted
Runtime: 744 ms
Memory Usage: 18.9 MB
```

### Improvement

We can realize that we don't even need to keep list of trusting people, we only care about how many people he trusts.

Using array instead of hashmap can save us a lot of time and memory.

```python
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 0:
            return -1
        
        a, b = [0 for _ in range(n+1)], [0 for _ in range(n+1)]
        
        for pair in trust:
            a[pair[0]] += 1
            b[pair[1]] += 1
        
        for person in range(1, n+1):
            if a[person] == 0 and b[person] == n-1:
                return person
        return -1
```
```
92 / 92 test cases passed.
Status: Accepted
Runtime: 720 ms
Memory Usage: 19 MB
```

Time complexity: O(n^2) due to number of elements in `trust` array can be up to `(n-1)^2`

Space complexity: O(n)
