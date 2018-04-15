# Problem 1

```ruby
def is_isomorphic(s, t)
  checking_hash = {}
  s.each_char.with_index do |c, index|
    if checking_hash[c].nil?
      return false if checking_hash.values.include?(t[index]) # new key map to same value
      checking_hash[c] = t[index]
    elsif t[index] != checking_hash[c]
      return false
    end
  end
  true
end

```
