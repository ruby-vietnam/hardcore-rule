## Problem 1 - [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

```python
def solution(n):
    f = [1, 1]

    if n < f.__len__():
        return f[n]

    for i in range(2, n + 1):
        f.append(f[-1] + f[-2])

    return f[-1]
```

## Problem 2 - [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

```python
def solution(s):
    if s.__len__() == 0:
        return 0

    d, c, i, j, mx = {}, 0, -1, -1, 0

    f = lambda vs: sum(map(lambda v: 1 if v > 0 else 0, vs))

    while i < s.__len__() and j < s.__len__() - 1:
        while i < j:
            i += 1
            d[s[i]] -= 1
            if j - i == f(d.values()):
                break
        while j < s.__len__() - 1:
            j += 1
            d[s[j]] = d.get(s[j], 0) + 1
            if j - i != f(d.values()):
                break
            mx = max(mx, j - i)

    return mx
```

## Problem 3 - [Course Schedule](https://leetcode.com/problems/course-schedule/description/)

```python
def solution(numCourses, prerequisites):
    afterCourses = [set([]) for _ in range(numCourses)]

    for pre in prerequisites:
        afterCourses[pre[0]].add(pre[1])

        flag = [True] * numCourses
        stack, flag[pre[1]] = [pre[1]], False

        while stack.__len__() > 0:
            i = stack.pop()

            if i == pre[0]:
                return False

            for j in afterCourses[i]:
                if flag[j] == True:
                    flag[j] = False
                    stack.append(j)

    return True
```
