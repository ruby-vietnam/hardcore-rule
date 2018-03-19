## Problem 3

Problem: https://leetcode.com/problems/valid-number/description/

### Overview

* Complexity: 0(n)
* Beat 100% Elixir solutions (or 0%).
* Pass 38/38 assertions.

### Solution

4 tokens are accepted: `num_char` (0-9), `e`, `whitespace` (`\r`, `\t` `\n`, `\s`), `dot`.

Rules:

* `num_char` is accepted when:
  * there are no trailing white spaces.
* `e` is accepted when:
  * there are `num_char`s upfront.
  * there is no `e` upfront.
* `dot` is accepted when:
  * there are `num_char`s upfront.
  * there is no `e` upfront.
  * there is no `dot` upfront.
* `whitespace` is accepted when:
  * there is nothing upfront.
  * there is nothing behind.

### Implementation

```elixir
defmodule Week13.Bai3 do
  def is_num(string) do
    is_num(string, 0, 0, false, false)
  end

  def is_num(<<whitespace, rest::bits>>, 0, 0, false, _trailing_whitespace?) when whitespace in '\r\n\t\ ' do
    is_num(rest, 0, 0, false, false)
  end

  def is_num(<<whitespace, rest::bits>>, before_e, after_e, decimal?, _trailing_whitespace?) when whitespace in '\r\n\t\ ' do
    is_num(rest, before_e, after_e, decimal?, true)
  end

  def is_num(<<num, _rest::bits>>, _before_e, _after_e, _decimal?, true) when num in ?0..?9 do
    false
  end

  def is_num(<<num, _rest::bits>>, _before_e, 0, _decimal?, true) when num in ?0..?9 do
    false
  end

  def is_num(<<num, rest::bits>>, before_e, 0, decimal?, false) when num in ?0..?9 do
    is_num(rest, before_e + 1, 0, decimal?, false)
  end

  def is_num(<<num, rest::bits>>, before_e, after_e, decimal?, false) when num in ?0..?9 do
    is_num(rest, before_e, after_e + 1, decimal?, false)
  end

  def is_num(<<?., _rest::bits>>, _before_e, _after_e, true, _trailing_whitespace?) do
    false
  end

  def is_num(<<?., _rest::bits>>, 0, _after_e, _decimal?, _trailing_whitespace?) do
    false
  end

  def is_num(<<?., _rest::bits>>, _before_e, after_e, _decimal?, _trailing_whitespace?) when after_e > 0 do
    false
  end

  def is_num(<<?., rest::bits>>, before_e, _after_e, _decimal?, false) do
    is_num(rest, before_e, 0, true, false)
  end

  def is_num(<<?e, _rest::bits>>, 0, _after_e, _decimal?, _trailing_whitespace?) do
    false
  end

  def is_num(<<?e, _rest::bits>>, _before_e, after_e, _decimal?, _trailing_whitespace?) when after_e > 0 do
    false
  end

  def is_num(<<?e, rest::bits>>, before_e, after_e, decimal?, false) do
    is_num(rest, before_e, after_e + 1, decimal?, false)
  end

  def is_num(<<_num, _rest::bits>>, _before_e, _after_e, _decimal?, _trailing_whitespace?) do
    false
  end

  def is_num(<<>>, _, _, _, _) do
    true
  end
end

defmodule Week13.Bai3Test do
  use ExUnit.Case, async: true

  import Week13.Bai3, only: [is_num: 1]

  test "is_num/1 with integer" do
    assert is_num("1")
    assert is_num("12")
    assert is_num("9999")
    assert is_num("1234567890")
    assert is_num("    1234")
    assert is_num("1234    ")
    refute is_num("a")
    refute is_num("1a")
    refute is_num("a1")
    refute is_num("aabbcc")
    refute is_num("    12 34")
  end

  test "is_num/1 with float" do
    assert is_num("1.0")
    assert is_num("0.10")
    assert is_num("14.10")
    assert is_num("1400123.10")
    assert is_num("1234567890.0123456789")
    assert is_num("    1234567890.0123456789")
    assert is_num("1234567890.0123456789    ")
    refute is_num("123.5.6")
    refute is_num("1234a.56")
    refute is_num("1234.5a6")
    refute is_num("1234.a5a6")
    refute is_num(".1234.a5a6")
    refute is_num("a.123")
    refute is_num("12.09 1")
  end

  test "is_num/1 with e number" do
    assert is_num("1e2")
    assert is_num("789e789")
    assert is_num("1.99e9")
    assert is_num("0.1e10")
    assert is_num(" \n\r\t   1234567890.012e3456789")
    assert is_num("1234567890.012345e6789    \n")
    assert is_num("1234567890.0123456789e1234567890")
    refute is_num("e23")
    refute is_num("1e2e3")
    refute is_num("1.0e2.3")
    refute is_num("1.0 e23")
    refute is_num("1e2.33")
    refute is_num("1e2.e33")
    refute is_num("1.5e6  \n 22")
  end
end
```
