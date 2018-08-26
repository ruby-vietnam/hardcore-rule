# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
    return 1 if n == 0
    return 1 if n == 1
    t = [1, 1]
    (2..n).each do |i|
        t[i] = t[i - 1] + t[i - 2]
    end
    t[n]
end
