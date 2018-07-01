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

## Problem 3

Link: https://leetcode.com/problems/chalkboard-xor-game/description/

 * 168 / 168 test cases passed.
 * Status: Accepted
 * Runtime: 44ms
```ruby
# @param {Integer[]} nums
# @return {Boolean}
def xor_game(nums)
  after_xor = nums.reduce(0) {|cum, num| cum ^ num}

  return true if after_xor == 0

  risky_attemps = count_1_bits(after_xor)
  safe_attemps = nums.size - risky_attemps

  return risky_attemps.even? if safe_attemps.even?
  risky_attemps.odd?
end

def count_1_bits(num)
  count = 0
  while num != 0
    num &= num - 1
    count += 1
  end
  count
end
```
