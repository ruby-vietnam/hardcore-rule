# Solution explanation
#
# 1. XOR the two input integers, since XOR always yields "1" when two input bits are different.
# 2. Convert the XOR-ed result to binary format, which is a string in Ruby.
# 3. Count the occurences of "1" in the string.
def hamming_distance(x, y)
  (x ^ y).to_s(2).chars.count("1")
end
