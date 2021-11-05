# Heaters

``` ruby
# @param {Integer[]} houses
# @param {Integer[]} heaters
# @return {Integer}
def find_radius(houses, heaters)
    houses.sort!
    heaters.sort!
    ans = 0
    houses.each do |house|
        min = 0
        max = heaters.length - 1
        while min < max
            mid = min + ((max - min + 1) / 2).ceil
            if heaters[mid] < house
                min = mid
            else
                max = mid - 1
            end
        end
        left = (heaters[min] - house).abs
        
        min = 0
        max = heaters.length - 1
        while min < max
            mid = min + ((max - min) / 2).floor
            if heaters[mid] < house
                min = mid + 1
            else
                max = mid
            end
        end
        right = (heaters[min] - house).abs
        
        ans = [[left, right].min, ans].max
    end
    
    ans
end
```

