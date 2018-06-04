### Prolem 1 - [633. Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/)

Status:
```
  ✔ Accepted
```

```ruby
# @param {Integer} c
# @return {Boolean}
def judge_square_sum(c)
    max = Integer(Math.sqrt(c))
    b = nil
    (0..max).each do |a|
        b = Math.sqrt(c - a * a)
        return true if b == Integer(b)
    end

    false
end

```

### Prolem 2 - [179. Largest Number](https://leetcode.com/problems/largest-number/description/)
Status:
```
  ✔ Status: Accepted
```

```ruby
# @param {Integer[]} nums
# @return {String}
def largest_number(nums)
  result = nums.sort do |a, b|
    (b.to_s + a.to_s) <=> (a.to_s + b.to_s)
  end
  return '0' if result[0].zero?
  result.join('')
end
```