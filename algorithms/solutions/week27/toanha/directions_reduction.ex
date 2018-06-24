defmodule Directions do
  @directions %{
    "NORTH" => "SOUTH",
    "SOUTH" => "NORTH",
    "WEST" => "EAST",
    "EAST" => "WEST"
  }

  def loop([], stack) do
    Enum.reverse(stack)
  end

  def loop([h | t], stack) do
    if length(stack) > 0 do
      [h_s | t_s] = stack

      if @directions[h] == h_s do
        loop(t, t_s)
      else
        loop(t, [h | stack])
      end
    else
      loop(t, [h | stack])
    end
  end

  def reduce(directions) do
    loop(directions, [])
  end
end
