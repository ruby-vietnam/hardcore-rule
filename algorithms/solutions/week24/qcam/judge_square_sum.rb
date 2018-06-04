def judge_square_sum(c)
  range = 0..Math.sqrt(c).floor()

  range.each do |a|
    b = Math.sqrt(c - a * a)
    return true if b % 1 == 0
  end

  false
end
