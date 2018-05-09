defmodule Main do
  use Bitwise

  def hamming_distance(x, y) do
    x
    |> bxor(y)
    |> Integer.digits(2)
    |> Enum.sum()
  end

  def run do
    IO.inspect(hamming_distance(4, 1) == 2)
    IO.inspect(hamming_distance(4, 3) == 3)
    IO.inspect(hamming_distance(1, 1) == 0)
  end
end

Main.run()
