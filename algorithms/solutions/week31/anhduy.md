# 550A

```ruby
def find_ab_ba(str)
  i = 0
  while (i < str.length - 3) do
    if str[i..i+1] == 'ab'
      j = i + 2
      while (j < str.length - 1) do
        if str[j..j+1] == 'ba'
          return 'YES'
        end
        j += 1
      end
      return 'NO'
    elsif str[i..i+1] == 'ba'
      j = i + 2
      while (j < str.length - 1) do
        if str[j..j+1] == 'ab'
          return 'YES'
        end
        j += 1
      end
      return 'NO'
    else
      i += 1
    end
  end
  return 'NO'
end

```

# 124

```ruby
def max_path_sum(root)
  return 0 unless root

  max_left = max_path_sum(root.left)
  max_right = max_path_sum(root.right)

  max_left_path = find_max_path(root.left)
  max_right_path = find_max_path(root.right)
  

  max_root = root.val
  if max_left_path > 0
    max_root += max_left_path
  end
  if max_right_path > 0
    max_root += max_right_path
  end

  [max_left, max_root, max_right].max
end

def find_max_path(root)
  unless root
    return 0
  end
  max_path = [find_max_path(root.left), find_max_path(root.right)].max
  if max_path > 0
    max_path + root.val
  else
    root.val
  end
end
```
