# https://leetcode.com/problems/find-the-difference/description/

def characters_hash(str)
  hash = Hash.new(0)

  0.upto(str.size - 1) do |idx|
    hash[str[idx]] += 1
  end

  hash
end

# @param {String} s
# @param {String} t
# @return {Character}
def find_the_difference(s, t)
  s_hash = characters_hash(s)
  t_hash = characters_hash(t)

  t_hash.reject { |k, v| v == s_hash[k] }.keys.first
end
