# Problem 1

```js
defmodule Solution do
  @first_row "qwertyuiopp"
  @second_row "asdfghjkl"
  @third_row "zxcvbnm"
  
  def keyboard_row(input) when is_binary(input) do
    input =
      input
      |> String.downcase()
      |> String.codepoints()

    cond do
      Enum.all?(input, &String.contains?(@first_row, &1)) -> true
      Enum.all?(input, &String.contains?(@second_row, &1)) -> true
      Enum.all?(input, &String.contains?(@third_row, &1)) -> true
      true -> false
    end
  end

  def keyboard_row(input) when is_list(input),
    do: Enum.filter(input, &keyboard_row(&1))
end
 ```
 
