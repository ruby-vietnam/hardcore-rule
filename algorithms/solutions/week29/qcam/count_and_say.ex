defmodule Week29 do
  def count_and_say(n) do
    count_and_say(n - 1, "1")
  end

  def count_and_say(0, acc), do: acc

  def count_and_say(n, acc) do
    count_and_say(n - 1, say(acc))
  end

  def say(<<start::integer, rest::binary>>) do
    say(start, rest, 1, "")
  end

  def say(char, <<>>, count, acc) do
    acc <> Integer.to_string(count) <> <<char>>
  end

  def say(char, <<next::integer, rest::binary>>, count, acc) when char == next do
    say(char, rest, count + 1, acc)
  end

  def say(char, <<next::integer, rest::binary>>, count, acc) do
    say(next, rest, 1, acc <> Integer.to_string(count) <> <<char>>)
  end
end

ExUnit.start()

defmodule Week29Test do
  use ExUnit.Case, async: true

  test "count_and_say" do
    assert Week29.count_and_say(1) == "1"
    assert Week29.count_and_say(2) == "11"
    assert Week29.count_and_say(3) == "21"
    assert Week29.count_and_say(4) == "1211"
    assert Week29.count_and_say(5) == "111221"
    assert Week29.count_and_say(6) == "312211"
    assert Week29.count_and_say(7) == "13112221"
    assert Week29.count_and_say(8) == "1113213211"
  end

  test "say" do
    assert Week29.say("1113") == "3113"
    assert Week29.say("1112") == "3112"
    assert Week29.say("1") == "11"
    assert Week29.say("11") == "21"
    assert Week29.say("21") == "1211"
  end
end
