defmodule DirectionsTest do
  use ExUnit.Case

  test "#reduce 1" do
    directions = ~w[NORTH WEST SOUTH EAST]
    message = "#{directions} cannot be reduced further"
    assert Directions.reduce(directions) == directions, message
  end

  test "#reduce 2" do
    directions = ~w[NORTH SOUTH SOUTH EAST WEST NORTH WEST]
    reduced_directions = ~w[WEST]

    message =
      Enum.join(directions, " ") <> " can be reduced to " <> Enum.join(reduced_directions, " ")

    assert Directions.reduce(directions) == reduced_directions, message
  end
end
