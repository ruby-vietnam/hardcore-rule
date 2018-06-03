# Problem 1: Sum of Square Numbers

https://leetcode.com/problems/sum-of-square-numbers/description/

```
Runtime: 92 ms
Your runtime beats 82.35 % of ruby submissions.
```

```ruby
# @param {Integer} c
# @return {Boolean}
def judge_square_sum(c)
  sqrt_c = Math.sqrt(c).to_i
  a = 0
  while a <= sqrt_c
    b = Math.sqrt(c - a * a)
    return true if b == b.to_i
    a += 1
  end
  false
end
```

# Problem 2: Largest Number

https://leetcode.com/problems/largest-number/description/

```
Runtime: 40 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {String}
def largest_number(nums)
  nums.map!(&:to_s)
  nums.sort! {|x, y| y + x <=> x + y }
  nums.join.to_i.to_s
end

```
