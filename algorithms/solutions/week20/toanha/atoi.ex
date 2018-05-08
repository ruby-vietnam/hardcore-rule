# https://leetcode.com/problems/plus-one

defmodule Main do
  @max_int 2_147_483_647
  @min_int -2_147_483_648

  def atoi(str) do
    _atoi(String.to_charlist(str))
  end

  def _atoi(str) do
    i = _number_digits(str, nil)

    cond do
      i > @max_int -> @max_int
      i < @min_int -> @min_int
      true -> i
    end
  end

  defp _number_digits([], value), do: value

  defp _number_digits([digit | tail], value)
       when digit in '0123456789' do
    _number_digits(tail, (value || 0) * 10 + digit - ?0)
  end

  defp _number_digits([digit | tail], value)
       when digit in ' ' do
    _number_digits(tail, value)
  end

  defp _number_digits([digit | tail], value)
       when digit in '-' do
    _number_digits(tail, value) * -1
  end

  defp _number_digits([non_digit | tail], value) when is_nil(value) do
    0
  end

  defp _number_digits([non_digit | tail], value) do
    _number_digits(tail, value)
  end

  def run do
    IO.inspect(atoi("42"))
    IO.inspect(atoi("   -42"))
    IO.inspect(atoi("4193 with words"))
    IO.inspect(atoi("words and 987"))
    IO.inspect(atoi("-91283472332"))
    IO.inspect(atoi("91283472332"))
  end
end

Main.run()
