def my_atoi(str)
  parse_next(str.chars, [], nil)
end

def parse_next(rest, acc, sign_bit)
  return to_integer(acc, sign_bit) if rest == ""

  character, *rest = rest

  case character
  when " "
    parse_whitespace(rest, acc, sign_bit)
  when "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
    parse_number(rest, character, acc, sign_bit)
  when "+", "-"
    parse_sign(rest, character, acc, sign_bit)
  else
    parse_others(rest, acc, sign_bit)
  end
end

def parse_whitespace(rest, acc, sign_bit)
  if acc == [] && !sign_bit
    parse_next(rest, acc, sign_bit)
  else
    to_integer(acc, sign_bit)
  end
end

def parse_number(rest, character, acc, sign_bit)
  parse_next(rest, acc.push(character), sign_bit)
end

def parse_sign(rest, sign, acc, sign_bit)
  if sign_bit
    # We've encountered a sign bit before.
    to_integer(acc, sign_bit)
  elsif acc != []
    # We've seen some numbers before.
    to_integer(acc, sign_bit)
  else
    # First time seeing a sign.
    parse_next(rest, acc, if sign == "+" then 1 else -1 end)
  end
end

def parse_others(rest, acc, sign_bit)
  to_integer(acc, sign_bit)
end

MAX_INT32 = 2 ** 31 - 1
MIN_INT32 = 2 ** 31

def to_integer(number_characters, sign_bit)
  sign_bit = sign_bit || 1

  unsigned_result, _ =
    number_characters.reverse().reduce([0, 0]) do |(acc, power), number_character|
      number = number_character.ord - "0".ord

      if overflow?(sign_bit, number, power, acc)
        [sign_bit == 1 ? MAX_INT32 : MIN_INT32, power + 1]
      else
        powered = number * (10 ** power)
        [acc + powered, power + 1]
      end
    end

  unsigned_result * sign_bit
end

def overflow?(sign_bit, number, power, acc)
  return true if power > 9 && number != 0
  return false if power < 9
  return true if number > 2
  return false if number < 2

  threshold = number * (10 ** power)

  case sign_bit
  when 1
    MAX_INT32 - threshold < acc
  when -1
    MIN_INT32 - threshold < acc
  end
end
