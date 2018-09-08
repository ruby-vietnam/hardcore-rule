## Problem 1

```ruby
def path_sum(root, sum)
  if root.nil?
    0
  else
    _, count = path_sum_of_tree(root, sum)
    count
  end
end

def path_sum_of_tree(root, sum)
  if root.left && root.right
    left_sums, left_count = path_sum_of_tree(root.left, sum)
    right_sums, right_count = path_sum_of_tree(root.right, sum)

    sums = left_sums + right_sums
    count = left_count + right_count
  elsif root.left
    sums, count = path_sum_of_tree(root.left, sum)
  elsif root.right
    sums, count = path_sum_of_tree(root.right, sum)
  else
    sums = []
    count = 0
  end

  result = [root.val] + sums.map { |sum| sum + root.val }
  count += result.inject(0) { |total, item| item == sum ? total + 1 : total }

  [result, count]
end
```
