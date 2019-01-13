# Problem 1
```ruby
# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
  hash = {}
  numbers.each_with_index do |n, i|
    if hash[target - n]
      return hash[target - n], i + 1
    end
    hash[n] = i + 1
  end
end
```

```elixir
defmodule Solution do
  def two_sum(numbers, target) do
    numbers
    |> Stream.with_index(1)
    |> Enum.reduce_while(%{}, fn {number, index}, map ->
      if map[target - number] do
        {:halt, {map[target - number], index}}
      else
        {:cont, Map.put(map, number, index)}
      end
    end)
  end
end
```

# Problem 2
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
  intervals.sort{|a, b| a.start <=> b.start}
           .reduce([]) do |acc, interval|
    if acc.empty? || acc.last.end < interval.start
      acc << interval
    else
      last = acc.pop
      if last.end >= interval.end
        acc << Interval.new(last.start, last.end)
      else
        acc << Interval.new(last.start, interval.end)
      end
    end
  end
end
```

```elixir
defmodule Interval do
  defstruct(start: 0, end: 0)

  def merge(intervals) do
    intervals
    |> Enum.sort_by(& &1.start)
    |> Enum.reduce([], fn interval, acc ->
      case acc do
        [] ->
          [interval]

        [head | rest] = acc ->
          if head.end >= interval.start do
            new_interval = %Interval{
              start: head.start,
              end: Enum.max([head.end, interval.end])
            }

            [new_interval | rest]
          else
            [interval | acc]
          end
      end
    end)
  end
end
```
