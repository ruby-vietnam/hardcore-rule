# Problem 1: 242. Valid Anagram
Status:
```
  ✔ Accepted
  ✔ 34/34 cases passed (84 ms)
  ✔ Your runtime beats 91.55 % of ruby submissions
```

```Ruby
def is_anagram(s, t)
  chars_set_s = {}
  chars_set_t = {}
  s.each_char { |c| chars_set_s[c] = chars_set_s[c].to_i + 1 }
  t.each_char { |c| chars_set_t[c] = chars_set_t[c].to_i + 1 }
  chars_set_s == chars_set_t
end
```

# Problem 2: 535. Encode and Decode TinyURL

Status:
```
  ✔ Accepted
  ✔ 739/739 cases passed (52 ms)
  ✔ Your runtime beats 31.03 % of ruby submissions
```

```Ruby
require 'uri'

def encode(longUrl)
  URI.escape(longUrl)
end

def decode(shortUrl)
  URI.unescape(shortUrl)
end
```
