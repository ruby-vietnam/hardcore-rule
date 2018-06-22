## Problem 1
Link: https://leetcode.com/problems/subdomain-visit-count

 * 52 / 52 test cases passed.
 * Status: Accepted
 * Runtime: 80 ms

```ruby
def resolve_subdomains(domain)
    subdomains = []
    (domain.length - 1).downto(0) do |i|
        if domain[i - 1] == '.' || i == 0
            subdomains << domain[i, domain.length]
        end
    end
    subdomains
end

# @param {String[]} cpdomains
# @return {String[]}
def subdomain_visits(cpdomains)
    subdomain_visit_counts = Hash.new(0)
    cpdomains.each do |cpdomain|
        count, domain = cpdomain.split(" ")
        subdomains = resolve_subdomains(domain)
        subdomains.each{|subdomain| subdomain_visit_counts[subdomain] += count.to_i}
    end

    subdomain_visit_counts.map{|subdomain, count| "#{count} #{subdomain}"}
end
```

## Problem 2

Link: https://www.codewars.com/kata/directions-reduction

 * 9/9 test cases passed.
 * Status: Accepted
```ruby
def opposite_dir?(dir1, dir2)
  dirs = [dir1, dir2].sort
  dirs == ["NORTH", "SOUTH"] || dirs == ["EAST", "WEST"]
end

def dirReduc(arr)
  smart_dir = []
  arr.each do |dir|
    if smart_dir.last && opposite_dir?(smart_dir.last, dir)
      smart_dir.pop
    else
      smart_dir << dir
    end
  end
  smart_dir
end
```
