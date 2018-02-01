# Problem 1

```ruby
def first_uniq_char(s)
    return -1 if s == ""

    cache = {}

    for i in 0..(s.length - 1)
        char = s[i]
        if cache[char]
            cache[char][:uniq] = false
        else
            cache[char] = {uniq: true, start_at: i}
        end
    end

    cache.select { |k, v| v[:uniq] }.map { |k, v| v[:start_at]}.min || - 1
end
```
