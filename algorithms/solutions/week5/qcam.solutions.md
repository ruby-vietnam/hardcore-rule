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

## Problem 3

```elixir
defmodule Problem3 do
  def max_envelopes(envs) do
    envs
    |> sort_envelopes()
    |> count_maxs([])
  end

  defp sort_envelopes(envs) do
    Enum.sort(envs, fn {w1, h1}, {w2, h2} ->
      cond do
        w1 < w2 -> false
        w1 > w2 -> true
        w1 == w2 -> h1 > h2
      end
    end)
  end

  def count_maxs([], maxs) do
    maxs
  end

  def count_maxs([current_env | envs], maxs) do
    maxs = [count(current_env, envs, 1) | maxs]

    count_maxs(envs, maxs)
  end

  defp count(_current_env, [], acc) do
    acc
  end

  defp count({w1, h1} = current_env, next_envs, acc) do
    [{w2, h2} = next_candidate | next_envs] = next_envs

    if w1 > w2 && h1 > h2 do
      count(next_candidate, next_envs, acc + 1)
    else
      count(current_env, next_envs, acc)
    end
  end
end

IO.inspect Problem3.max_envelopes([{5, 4}, {6, 4}, {6, 7}, {2, 3}])
IO.inspect Problem3.max_envelopes([{5, 0}, {4, 4}, {3, 3}, {3, 2}, {1, 1}, {1, 0}])
```
