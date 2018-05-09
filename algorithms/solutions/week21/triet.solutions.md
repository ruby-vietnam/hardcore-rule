## Problem 1

```Go
func isAnagram(s string, t string) bool {
    mS := map[rune]int{}
    for _, r := range s{
        v, exists:= mS[r]
        if exists {
            mS[r] = v+1
        }else{
            mS[r] = 1
        }
    }
    
    for _, r := range t {
        v, exists:= mS[r]
        if exists {
            mS[r] = v-1
        }else{
            return false
        }
    }
    
    for _, value := range mS {
        if value > 0 {
            return false
        }
    }
    
    return true
}
```

```Ruby
# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
  ms = {}
  s.each_char do |r|
    ms[r] = if ms.key?(r)
              ms[r] + 1
            else
              1
            end
  end

  t.each_char do |r|
    return false unless ms.key?(r)
    ms[r] = ms[r] - 1
  end

  ms.each do |_, value|
    return false if value.positive?
  end

  true
end
```

