def is_isomorphic(s, t)
  scache = {}
  tcache = {}

  s.chars.each_with_index do |schar, i|
    tchar = t[i]

    if scache.has_key?(schar)
      return false if scache[schar] != tchar
    else
      if tcache.has_key?(tchar)
        return false if tcache[tchar] != schar
      else
        tcache[tchar] = schar
        scache[schar] = tchar
      end
    end
  end

  true
end
