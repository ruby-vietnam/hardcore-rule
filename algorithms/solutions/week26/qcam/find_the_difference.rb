def find_the_difference(s, t)
  s = s.split("").sort()
  t = t.split("").sort()

  t.each_with_index do |char, index|
    return char if index == t.length()
    return char if char != s[index]
  end
end
