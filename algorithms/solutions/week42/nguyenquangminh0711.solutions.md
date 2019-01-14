## Problem 1
Problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Complexity: O(n * log n)
Loop from 1 -> n, at each element, use binary search to find the matched sum in the next range.

```ruby
# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
    numbers.each_with_index do |a, index_a|
        head = 0
        tail = numbers.length - 1
        loop do
            break if head > tail
            index_b = (head + tail) / 2
            sum = a + numbers[index_b]
            
            if index_a != index_b && sum == target
                return [index_a + 1, index_b + 1]
            elsif target >= sum
                head = index_b + 1
            else
                tail = index_b - 1
            end
        end
    end
end
```

## Problem 2

https://leetcode.com/problems/merge-intervals/submissions/
Complexity: O(n * log n)
First, sort the interval array by starting point. Then loop in the sorted array, check whether the current interval could be merged into the last one? If yes, merge, if not, ignore.

```ruby
# Definition for an interval.
# class Interval
#     attr_accessor :start, :end
#     def initialize(s=0, e=0)
#         @start = s
#         @end = e
#     end
# end

# @param {Interval[]} intervals
# @return {Interval[]}
def merge(intervals)
    return [] if intervals.empty?
    intervals = intervals.sort_by { |i| i.start }
    result = [intervals.first]
    intervals[1..-1].each do |interval|
        if mergeable?(result.last, interval)
            merge_interval(result.last, interval)
        else
            result << interval
        end
    end
    result
end

def mergeable?(a, b)
    (b.start <= a.end  && a.end <= b.end) ||
        (b.start <= a.start && a.start <= b.end) ||
        (a.start <= b.end  && b.end <= a.end) ||
        (a.start <= b.start && b.start <= a.end) 
end

def merge_interval(a, b)
    a.start = [a.start, b.start].min
    a.end = [a.end, b.end].max
end```

## Problem 3

https://leetcode.com/problems/maximum-swap/submissions/
Complexity: O(n * 2)
Loop from 1 -> n, at each digit, check if the current digit is the biggest from i -> n. If yes, continue. Ohterwise, swap it with the max digit with highest index and return.
