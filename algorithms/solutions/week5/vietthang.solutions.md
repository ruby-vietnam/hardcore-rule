# Problem set #1

```go
func getRow(rowIndex int) []int {
    collection := []int{}
    for i := 0; i <= rowIndex; i++ {
        collection = append(collection, 1)
        for j := len(collection) - 2; j > 0; j-- {
            collection[j] = collection[j] + collection[j - 1]
        }
    }
    return collection
}
```

# Problem set #2

```ruby
defmodule ValidString do
  def valid_parenthesis_string(str) when is_bitstring(str) do
    str
    |> String.codepoints()
    |> loop(0)
  end

  defp loop([head | tail], point) do
    # Assume: "(" equal 1, ")" equal -1. and empty string equal 0.
    case head do
      "(" -> loop(tail, point + 1)
      ")" -> loop(tail, point - 1)
      "*" -> # "*" could be one of three possibilities
        [_ | t] = tail
        loop(t, point + 1) || loop(t, point - 1) || loop(t, point)
    end
  end
  defp loop([], point), do: point == 0

  # if point <= 0: invalid
  defp loop(_, point) when point <= 0, do: false
end
```

____