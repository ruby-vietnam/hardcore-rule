## Problem 2

```elixir
defmodule Problem2 do
  def check_valid_string(str) do
    init = {0, 0}
    check(str, init)
  end

  defp check(<<"(", rest::binary>>, {count, num_stars}) do
    check(rest, {count + 1, num_stars})
  end

  defp check(<<")", _rest::binary>>, {0, 0}) do
    false
  end

  defp check(<<")", rest::binary>>, {count, num_stars}) do
    check(rest, {count - 1, num_stars})
  end

  defp check(<<"*", rest::binary>>, {count, num_stars}) do
    check(rest, {count, num_stars + 1})
  end

  defp check("", {0, _num_stars}) do
    true
  end

  defp check("", {count, num_stars}) do
    count + num_stars == 0 || count - num_stars == 0
  end
end
```
