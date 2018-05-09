# Problemm 1: Power of Four

URL: https://leetcode.com/problems/power-of-four/description/

Status;
```
  ✔ Accepted
```

```ruby
def is_power_of_four(num)
    # 4 ** x = num with x is integer <=> 2 ** (2x) = num <=> num > 0 and 2x = log(num, 2)
    return false if num <= 0
    Math.log(num, 2) % 2 == 0
end
```
