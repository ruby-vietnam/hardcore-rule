# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
  loop do
    return false if n == 0
    return true if n == 1
    return false if n % 3 != 0
    n = n / 3
  end
end
