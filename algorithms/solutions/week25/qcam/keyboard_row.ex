defmodule Week25.Solution1 do
  @qwerty [
    ?q, ?w, ?e, ?r, ?t, ?y, ?u, ?i, ?o, ?p,
    ?Q, ?W, ?E, ?R, ?T, ?Y, ?U, ?I, ?O, ?P
  ]

  @asdf [
    ?a, ?s, ?d, ?f, ?g, ?h, ?j, ?k, ?l,
    ?A, ?S, ?D, ?F, ?G, ?H, ?J, ?K, ?L
  ]

  @zxcv [
    ?z, ?x, ?c, ?v, ?b, ?n, ?m,
    ?Z, ?X, ?C, ?V, ?B, ?N, ?M
  ]

  def find_words(words) do
    Enum.filter(words, &same_row?/1)
  end

  defp same_row?(<<character::integer, rest::bits>>)
       when character in @qwerty do
    same_row?(rest, @qwerty)
  end

  defp same_row?(<<character::integer, rest::bits>>)
       when character in @asdf do
    same_row?(rest, @asdf)
  end

  defp same_row?(<<character::integer, rest::bits>>)
       when character in @zxcv do
    same_row?(rest, @zxcv)
  end

  defp same_row?(<<character::integer, rest::bits>>) do
    false
  end

  defp same_row?(<<>>, _matching_characters), do: true

  defp same_row?(<<character::integer, rest::bits>>, matching_characters) do
    if character in matching_characters do
      same_row?(rest, matching_characters)
    else
      false
    end
  end
end

ExUnit.start()

defmodule Week25.Solution1Test do
  use ExUnit.Case, async: true

  import Week25.Solution1

  describe "find_words/1" do
    test "filters out words that can be typed using letters on only one row of American keyboard" do
      assert find_words(["Alaska", "Dad", "Peace"]) == ["Alaska", "Dad"]
      assert find_words(["QQQQQQwerty", "JKKkfhasq"]) == ["QQQQQQwerty"]
    end
  end
end
