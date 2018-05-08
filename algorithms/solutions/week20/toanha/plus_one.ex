# https://leetcode.com/problems/plus-one

defmodule Main do
  def plus_one(arr) do
    _plus_one(Enum.reverse(arr), [], 1)
  end

  defp _plus_one([head | tail], arr, temp) do
    new_head = head + temp

    if new_head > 9 do
      _plus_one(tail, [rem(new_head, 10) | arr], div(new_head, 10))
    else
      _plus_one(tail, [new_head | arr], 0)
    end
  end

  defp _plus_one([], arr, temp) when temp > 0 do
    [temp | arr]
  end

  defp _plus_one([], arr, _temp) do
    arr
  end

  def run do
    IO.inspect(plus_one([1, 2, 3]) == [1, 2, 4])
    IO.inspect(plus_one([1, 2, 9]) == [1, 3, 0])
    IO.inspect(plus_one([9, 9, 9]) == [1, 0, 0, 0])
  end
end

Main.run()
