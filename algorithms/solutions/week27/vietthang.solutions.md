# Problem 2

```elixir
defmodule Directions do
  def oposite("NORTH"), do: "SOUTH"
  def oposite("SOUTH"), do: "NORTH"
  def oposite("WEST"), do: "EAST"
  def oposite("EAST"), do: "WEST"
  
  def reduce(directions), do: _reduce(directions, [])
  
  def _reduce([], stack), do: stack
  def _reduce([head | tail], stack) do
    top = List.last(stack)
    remain = Enum.drop(stack, -1)
    if oposite(head) == top,
      do: _reduce(tail, remain),
    else: _reduce(tail, stack ++ [head])
  end
end
```
