# Problem 1: Two Sum II - Input array is sorted

URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

```ruby
# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
    first_index = 0
    last_index = numbers.size - 1

    while first_index < last_index do
        case numbers[first_index] + numbers[last_index] <=> target
        when 0
            return [first_index + 1, last_index + 1]
        when -1
            first_index += 1
        when 1
            last_index -= 1
        end
    end
end

```
