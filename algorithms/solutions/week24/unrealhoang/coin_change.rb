# Dynamic programming:
#
# Top down calculate minimum coin needed for a specific amount.
# Caching calculated result.
#
class Solver
  def initialize(coins, amount)
    @coins = coins
    @amount = amount
    @cache = Array.new(amount + 1, nil)
  end

  def change(amount)
    return -1 if amount < 0
    return 0 if amount == 0
    @cache[amount] ||= begin
                         puts "calculate #{amount}"
                         result = nil
                         @coins.each do |value|
                           if (t = change(amount - value)) != -1
                             if result.nil? || result > t + 1
                               result = t + 1
                             end
                           end
                         end
                         result ? result : -1
                       end
  end

  def calculate
    change(@amount)
  end
end



# @param {Integer[]} coins
# @param {Integer} amount
# @return {Integer}
def coin_change(coins, amount)
  r = Solver.new(coins, amount).calculate
  return r
end

coin_change([1,2,5], 11)
coin_change([186,419,83,408], 6249)
