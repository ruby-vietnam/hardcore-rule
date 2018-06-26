# Problem 1: Subdomain Visit Count

https://leetcode.com/problems/subdomain-visit-count/description/

```
Runtime: 72 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {String[]} cpdomains
# @return {String[]}
def subdomain_visits(cpdomains)
  visited_list = cpdomains.map { |cpdomain| arr = cpdomain.split(' ') }
  visited_list.map!{ |visited| [visited[1], visited[0].to_i] }
  hash = {}
  while visited_list.length > 0
    visited = visited_list.shift
    hash[visited[0]] ||= 0
    hash[visited[0]] += visited[1]
    visited[0] = visited[0].split('.')
    visited[0].shift
    visited[0] = visited[0].join('.')
    visited_list.push(visited) if visited[0].length > 0
  end
  result = []
  hash.each { |key, value| result.push("#{value} #{key}") }
  result
end
```
