## Problem 1 - [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
```python
def solution(n):
  i, j = 0, len(numbers) - 1
  while i < j:
      _target = numbers[i] + numbers[j]
      if _target < target:
          i += 1
      elif _target > target:
          j -= 1
      else:
          return [i + 1, j + 1]
  return [-1, -1]
```

## Problem 2 - [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
```python
def solution(n):
  sorted_intervals = sorted(intervals, key=lambda x: x.start, reverse=False)
  results = [sorted_intervals[0]] if len(sorted_intervals) > 0 else []

  for internal_2 in sorted_intervals[1:]:
      merged = False
      for i, internal_1 in enumerate(results):
          if internal_1.end >= internal_2.start:
              results[i] = Interval(internal_1.start, max(internal_2.end, internal_1.end))
              merged = True
              break
      if not merged:
          results.append(internal_2)

  return results
```

## Problem 3 - [Maximum Swap](https://leetcode.com/problems/maximum-swap/)
```python
def solution(n):
  def swap(s, i, j):
      t = s[i]
      s[i] = s[j]
      s[j] = t
      return s

  s = list(str(num))
  for i in range(0, len(s) - 1):
      t, k = s[-1], len(s) - 1
      for j in range(len(s) - 2, i, -1):
          if t < s[j]:
              t, k = s[j], j
      if s[i] < t:
          s = swap(s, i, k)
          return int(''.join(s))

  return int(''.join(s))
```
