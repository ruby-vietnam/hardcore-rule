defmodule Week31.ABBA do
  def detect(string) do
    detect(string, {false, false})
  end

  defp detect(<<>>, {has_ab?, has_ba?}) do
    has_ab? and has_ba?
  end

  defp detect(<<"AB", rest::bits>>, {_has_ab?, has_ba?}) do
    detect(rest, {true, has_ba?})
  end

  defp detect(<<"BA", rest::bits>>, {has_ab?, _has_ba?}) do
    detect(rest, {has_ab?, true})
  end

  defp detect(<<_::integer, rest::bits>>, flags) do
    detect(rest, flags)
  end
end

ExUnit.start()

defmodule Week31.ABBATest do
  use ExUnit.Case, async: true

  import Week31.ABBA

  test "detect/1" do
    assert detect("ABBBBA")
    assert detect("ABABBBAB")
    refute detect("ABA")
    refute detect("AXBYBXA")
    refute detect("")
  end
end
