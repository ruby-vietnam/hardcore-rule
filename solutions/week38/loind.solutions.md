# Problem 2

```ruby
def search_matrix(matrix, target)
  if matrix.empty?
    return false
  end
  n = matrix.size-1
  m = matrix[0].size-1
  i = 0
  is_exists = false
  while i <= n && !is_exists
    is_exists = binary_search(matrix[i], target, 0, m)
    i+=1
  end
  return is_exists
end

def binary_search(array, target, l, r)
  if l > r
    return false
  end
  mid = (l+r)/2
  e = array[mid]
  if e == target
    return true
  end
  if target > e
    binary_search(array, target, mid+1, r)
  else
    binary_search(array, target, l, mid-1)
  end
end
```
