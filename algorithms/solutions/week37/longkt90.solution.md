# Problem 1 : Power of Three

URL: https://leetcode.com/problems/power-of-three/description/

```ruby
def is_power_of_three(n)
    return false if n < 1
    while n % 3 == 0
        n /= 3
    end
    n == 1
end
```
