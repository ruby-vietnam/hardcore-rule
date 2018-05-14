# 1. The bulb is off when the number of touches onto it is an even number.
# 2. The bulb is on when the number of touches onto it is an odd number.
# 3. The bulb at position X can be touched at the Yth round when Y is the divisor of X. For example:
#    * The first bulb (X = 1) will only be touched at the first round (Y = 1).
#    * The forth bulb (X = 4) will be touched at the first, second and forth round (Y = 1, 2, 4).
#    * And so on, the Xth bulb will be touched at the Yth round when Y is the divisor of X.
# 4. On that basis, we can conclude that the number of touches on the Xth bulb equals to the number of divisors of X.
# 5. We know that the amount of divisors of X is odd if only X is a square number.
# 6. Thus the question can be rephrased as: find the amount of square numbers in the range of 1 to N.
#
# Thanks @linxGnu for being nice enough to explain this to me.
def bulb_switch(n)
  Math.sqrt(n).floor()
end
