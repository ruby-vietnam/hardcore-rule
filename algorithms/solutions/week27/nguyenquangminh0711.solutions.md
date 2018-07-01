# Problem 1

https://leetcode.com/problems/subdomain-visit-count/description/

```ruby
# @param {String[]} cpdomains
# @return {String[]}
def subdomain_visits(cpdomains)
    hash = {}
    cpdomains.each do |domain|
        count, name = domain.split(' ')
        count = count.strip.to_i
        sections = name.strip.split('.')
        
        (0..(sections.length - 1)).each do |i|
            sub = sections[i..sections.length - 1].join('.')
            hash[sub] ||= 0
            hash[sub] += count
        end
    end
    hash.map do |sub, count|
        "#{count} #{sub}"
    end
end
```
