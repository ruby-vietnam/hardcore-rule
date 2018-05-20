defmodule Main do
  def merge_k_lists(arr) do
    arr
    |> List.flatten()
    |> Enum.sort(&(&1 < &2))
  end
end

Main.merge_k_lists([
  [1, 4, 5],
  [1, 3, 4],
  [2, 6]
])
|> IO.inspect()
