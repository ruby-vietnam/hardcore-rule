##Problem 1:

#Given a 32-bit signed integer, reverse digits of an integer.

# @param {Integer} x
# @return {Integer}
def reverse(x)
    x < 0 ? (0 - x.to_s.reverse.to_i) : x.to_s.reverse.to_i
end