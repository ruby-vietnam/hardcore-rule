# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
    return false if s.length != t.length
    char_count = {}
    s.each_char do |c|
        char_count[c] ||= 0
        char_count[c] += 1
    end
    t.each_char do |c|
        char_count[c] ||= 0
        char_count[c] -= 1
        if char_count[c] < 0
            return false
        end
    end
    return true
end
