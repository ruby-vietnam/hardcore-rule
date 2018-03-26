# Problem 1

```ruby
def is_power_of_four(num)
    b_num = num.to_s(2)
    return false if b_num.length % 2 == 0
    return false if b_num[0] != 1
    return false if b_num.slice(1, b_num.length).to_i != 0
    true
end
```
