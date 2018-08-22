## Problem 1 - [K-based Numbers](http://acm.timus.ru/problem.aspx?space=1&num=1009)

```python
def solution(N, K):
    f0 = [1] + [0] * (N - 1)
    f1 = [K - 1] + [0] * (N - 1)
    for i in range(1, N):
        f0[i] = f1[i - 1]
        f1[i] = (K - 1) * (f0[i - 1] + f1[i - 1])
    return f1[-1]
```

## Problem 2 - [Spiral Matrix III](https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/)

```python
def solution(R, C, r0, c0):
    direction, idirection = [[0, 1], [1, 0], [0, -1], [-1, 0]], 3
    isize, bsize = 0, True
    output, count = [[r0, c0]], 1
    r, c = r0, c0

    while (count < R * C):
        isize += 1 if bsize else 0
        bsize = not bsize
        idirection = (idirection + 1) % 4

        for i in range(isize):
            pos = [r + direction[idirection][0], c + direction[idirection][1]]
            if 0 <= pos[0] and 0 <= pos[1] and pos[0] < R and pos[1] < C:
                output.append(pos)
                count += 1
            r, c = pos

    return output
```

## Problem 3 - [Possible Bipartition](https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/)

```python
def solution(N, dislikes):
    if dislikes.__len__() == 0:
        return True

    summary = [[] for _ in range(N)]

    for dislike in dislikes:
        if dislike[0] > dislike[1]:
            dislike.reverse()
        summary[dislike[0] - 1].append(dislike[1] - 1)
        summary[dislike[1] - 1].append(dislike[0] - 1)

    group = [0] * N
    iperson, stack = 0, [dislikes[0][0]]
    group[dislikes[0][0]] = 1

    while stack.__len__() > 0:
        iperson = stack.pop()
        for idislike in summary[iperson]:
            if group[idislike] == 0:
                group[idislike] = - group[iperson]
                stack.append(idislike)
            elif group[idislike] == group[iperson]:
                return False

    return True
```

## Problem 4 - [Super Egg Drop](https://leetcode.com/contest/weekly-contest-97/problems/super-egg-drop/)

```python
def solution(K, N):
    f = [[0] * (K + 1), [1] * (K + 1)]

    drop_max = 1
    while drop_max < N:
        ft = [0]
        for k in range(1, K + 1):
            drop_value = f.__len__() if k == 1 else f[-1][k - 1] + 1 + f[-1][k]
            drop_max = max(drop_max, drop_value)
            ft.append(drop_value)
        f.append(ft)

    return f.__len__() - 1
```
