def hamming_distance(x, y)
  (x ^ y).to_s(2).chars.count("1")
end
