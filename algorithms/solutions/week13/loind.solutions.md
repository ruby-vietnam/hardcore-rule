# Problem 1

```ruby
def maximum_product(nums)
    min1 = min2 = 1001
    max1 = max2 = max3 = -1001
    nums.each do |num|
        # Find min
        if min1 > num
            min2 = min1
            min1 = num
        else
            min2 = [num, min2].min
        end

        # Find max
        if max1 < num
            max3 = max2
            max2 = max1
            max1 = num
        else
            if max2 < num
                max3 = max2
                max2 = num
            else
                max3 = [num, max3].max
            end
        end
    end
    sum1 = min1 * min2 * max1
    sum2 = max1 * max2 * max3
    [sum1, sum2].max
end
```
