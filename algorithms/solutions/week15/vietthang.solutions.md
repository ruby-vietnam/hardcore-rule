# Problem 1

```elixir
def moveZeros(nums), do: moveZeros(nums, [], [])
def moveZeros([0 | t], nonZeros, zeros), do: moveZeros(t, nonZeros, zeros ++ [0])
def moveZeros([h | t], nonZeros, zeros), do: moveZeros(t, nonZeros ++ [h], zeros)
def moveZeros([], nonZeros, zeros), do: nonZeros ++ zeros
```
