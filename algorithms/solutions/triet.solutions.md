## Problem 1
https://leetcode.com/problems/subdomain-visit-count

```ruby
# @param {String[]} cpdomains
# @return {String[]}
def subdomain_visits(cpdomains)
    m = cpdomains.reduce(Hash.new(0)) { |m, domain| 
      subdomain = domain.split(' ')[1].split('.').reverse.reduce { |subdomain, part| 
        m[subdomain] += domain.split(' ')[0].to_i
        part + '.' + subdomain
      }
      m[subdomain] += domain.split(' ')[0].to_i
      m
    }.reduce([]) { |arr,(k,v)| arr << v.to_s + ' ' + k }
end
```
