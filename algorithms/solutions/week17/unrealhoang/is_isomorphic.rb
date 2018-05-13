# @param {String} s
# @param {String} t
# @return {Boolean}
def is_isomorphic(s, t)
    return false if s.size != t.size
    mapped = {}
    mapped_back = {}
    s.chars.zip(t.chars).each do |sc, tc|
        return false if (mapped[sc] && mapped[sc] != tc)
        return false if (mapped_back[tc] && mapped_back[tc] != sc)
        mapped[sc] = tc
        mapped_back[tc] = sc
    end
    return true
end
