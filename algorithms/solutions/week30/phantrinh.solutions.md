### Prolem 1 - [Mini-Max Sum](https://www.hackerrank.com/challenges/mini-max-sum/problems)
```python
arr = map(int, raw_input().rstrip().split())
print sum(arr) - max(arr), sum(arr) - min(arr)
```

### Prolem 2 - [Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problems)
```python
strings_count = int(raw_input())

strings = {}

for _ in xrange(strings_count):
  strings_item = raw_input()
  if strings_item not in strings:
    strings[strings_item] = 0
  strings[strings_item] += 1

queries_count = int(raw_input())

queries = []

for _ in xrange(queries_count):
  queries_item = raw_input()
  if queries_item not in strings:
    print 0
  else:
    print strings[queries_item]
```
