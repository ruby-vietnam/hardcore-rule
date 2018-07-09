def count(s)
  last = nil
  last_count = 0
  result = []
  s.chars.each do |i|
    if last != i
      if last_count > 0
        result << last_count
        result << last
      end
      last = i
      last_count = 1
    else
      last_count += 1
    end
  end
  if last_count > 0
    result << last_count
    result << last
  end
  result.join('')
end

# @param {Integer} n
# @return {String}
def count_and_say(n)
  t = "1"
  (n-1).times do |i|
    t = count(t)
  end
  t
end
