defmodule Main do
  def sort(str) do
    str
    |> String.to_charlist()
    |> Enum.sort(fn a, b -> a < b end)
    |> to_string()
  end

  def valid_anagram(s1, s2) do
    sort(s1) == sort(s2)
  end
end

IO.inspect(Main.valid_anagram("anagram", "nagaram"))
IO.inspect(Main.valid_anagram("anagr", "nagaram"))
