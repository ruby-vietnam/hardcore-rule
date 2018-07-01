defmodule Directions do
  def reduce([head | directions]) do
    reduce(directions, [head])
  end

  defp reduce([], stack), do: Enum.reverse(stack)
  defp reduce([next | directions], stack) do
    reduce(directions, stack(stack, next))
  end

  defp stack(["NORTH" | stack], "SOUTH"), do: stack
  defp stack(["SOUTH" | stack], "NORTH"), do: stack
  defp stack(["EAST" | stack], "WEST"), do: stack
  defp stack(["WEST" | stack], "EAST"), do: stack
  defp stack(stack, next), do: [next | stack]
end

ExUnit.start()

defmodule DirectionsTest do
  use ExUnit.Case

  test "#reduce 1" do
    directions = ~w[NORTH WEST SOUTH EAST]
    assert Directions.reduce(directions) == directions
  end

  test "#reduce 2" do
    directions = ~w[NORTH SOUTH SOUTH EAST WEST NORTH WEST]
    reduced_directions = ~w[WEST]
    assert Directions.reduce(directions) == reduced_directions
  end
end
