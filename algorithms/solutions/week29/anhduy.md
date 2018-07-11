# 38

```ruby
def count_and_say(n)
  a = ['1']
  (n - 1).times do
    count = 0
    b = [1, a[0]]
    i = 1
    while i < a.length do
      if a[i-1] == a[i]
        b[count] += 1
      else
        count += 2
        b[count] = 1
        b[count + 1] = a[i]
      end
      i += 1
    end
    a = b.join.split('')
  end
  a.join
end
```
