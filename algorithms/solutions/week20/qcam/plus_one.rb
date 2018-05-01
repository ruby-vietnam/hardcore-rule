def plus_one(digits)
  next_digit(digits.reverse(), [], 1)
end

def next_digit(rest, acc, remnant)
  return to_digits(acc, remnant) if rest.length == 0

  digit, *rest = rest
  acc_digit = digit + remnant

  if acc_digit == 10
    next_digit(rest, acc.push(0), 1)
  else
    next_digit(rest, acc.push(acc_digit), 0)
  end
end

def to_digits(digits, remnant)
  if remnant != 0
    [1] + digits.reverse()
  else
    digits.reverse()
  end
end
