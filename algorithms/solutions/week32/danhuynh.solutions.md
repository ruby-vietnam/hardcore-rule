# [Problem 1](https://leetcode.com/problems/leaf-similar-trees/description/)
```ruby
# Traverse all nodes in the tree and return all leaf nodes
def leaves(root)
  return [] unless root
  return [root.val] if root.left.nil? && root.right.nil?

  leavesLeft = leaves(root.left)
  leavesRight = leaves(root.right)

  leavesLeft + leavesRight
end

# compare 2 trees
def leaf_similar(root1, root2)
  leaves(root1) == leaves(root2)
end
```

# [Problem 2](https://leetcode.com/problems/most-frequent-subtree-sum/description/)
```ruby
# traverse all nodes in the tree and calculate the sum of each subtree
# start from each node. Keep track of the frequencies of each sum and
# the most frequent sum using a hash .
def sums(root, frequencies)
  return 0, 0 unless root

  total_left, max_freq_left = sums(root.left, frequencies)
  total_right, max_freq_right = sums(root.right, frequencies)

  sum_node = total_left + total_right + root.val
  frequencies[sum_node] += 1
  [sum_node, [max_freq_left, max_freq_right, frequencies[sum_node]].max]
end

# @param {TreeNode} root
# @return {Integer[]}
def find_frequent_tree_sum(root)
  frequencies = Hash.new(0)
  _, max_freq = sums(root, frequencies)

  # select all sums with the same frequency as max frequency
  # these sums are guaranteed to be unique because they are keys
  # of a hashmap
  frequencies.reduce([]) do |ret, pair|
    sum, freq = pair
    ret << sum if freq == max_freq
    ret
  end
end
```

# [Problem 3](https://codeforces.com/problemset/problem/117/A)
Because the elevator always start at floor 1 then go up to floor m and then go
back, we can easily calculate the time that a person can enter the elevator.

For example:

There are 4 floors, people at floor 2 can only enter the elevator at time = (1, 5, 7, 11, 13, ...).
If a person want to go from floor 2 to floor 4 and wait before the elevator at time = 4.
While he can enter the elevator at the 5th second, because the elevator is going down at that time,
he should wait til the 7th second to enter the elevator.
We can simplify this pattern to: `(lapse * number of lapses) + (start floor - 1)`
with number of lapses go from 0 to Infinity and a `lapse = 2 * (number of floor - 1)`

Follow the same reasoning above, we can calculate the time that a person can enter the elevator
**to go down** using this pattern: `lapse - (start floor - 1) + (lapse * number of lapses)`.


After we know the time a person can enter the elevator, we can add the distance between start and destination
to get the final result.

```ruby
def solve(s, f, t, m)
  lapse = 2 * (m - 1)

  # if a person is already at his destination
  # then we just return the time when he start waiting
  return t if s == f

  if s < f
    ret = s - 1
    ret += ((t - ret) / lapse.to_f).ceil * lapse if ret < t
    # same as this
    # while ret < t
    #   ret += lapse
    # end
    ret += f - s
  else
    ret = lapse - (s - 1)
    ret += ((t - ret) / lapse.to_f).ceil * lapse if ret < t
    # same as this
    # while ret < t
    #   ret += lapse
    # end
    ret += s - f
  end
  ret
end

n, m = gets.strip.split(' ').map(&:to_i)

n.times do
  s, f, t = gets.strip.split(' ').map(&:to_i)
  puts solve(s, f, t, m)
end
```

# [Problem 4](https://codeforces.com/problemset/problem/354/C)
The requirement is to find the max GCD (let's call it `g`) where for each number a[i] in the array,
after subtracting `a value <= k` can be divisible by g, which require `a[i] mod g` to be smaller or equal to k.

We know that the GCD of the array can not exceed the minimum number in the array (let's call it `min`), because
`min` can not be divisible by g if g is bigger than `min`. We also know that the remain of a division have
to be smaller than the divisor (`a mod g <= g - 1`), which means if `min - 1 <= k`(`=> a mod min <= min - 1 <= k`)
then the max GCD is `min`.

If `min - 1 > k`, then `g` have to be in this range `k+1 <= g <= min`. We can check every possible `g` in this range,
and return the first `g` where for every a[i] in a, `a[i] mod g <= k`. But checking the correctness of `g` like that
isn't optimized enough to pass the test, the better way would be checking if the sum of `cnt[i*g] + .. + cnt[i*g+k]`
(with `i go from 1 to max/g` and `cnt[i] is count of numbers <= i we have in array a`) is equal to `n` or not.
(Further explanation [here](http://codeforces.com/blog/entry/8672))

```ruby
# This solution only pass 34 test cases
# due to the slowness of ruby
def is_g?(g, max, n, k, sum)
  limit = max / g
  ret = 0
  1.upto(limit) do |j|
    sum[j * g + k] ||= 0
    sum[j * g - 1] ||= 0
    # The sum of cnt[i*g] + .. + cnt[i*g+k] is
    # sum of every cnt til cnt[ j * g + k ] - sums of every cnt before
    # cnt[i*g]
    ret += sum[j * g + k] - sum[j * g - 1]
  end
  return ret == n
end

def solve
  min = Float::INFINITY
  max = 0

  n, k = gets.strip.split.map(&:to_i)
  a = []
  # Sums array for DP
  sum = []

  gets.strip.split.each do |x|
    x = x.to_i
    a << x
    min = [x, min].min
    max = [x, max].max
    sum[x] ||= 0
    sum[x] += 1
  end

  min.upto(max+k) do |i|
    sum[i] ||= 0
    sum[i-1] ||= 0
    sum[i] += sum[i-1]
  end

  if min <= k+1
    puts min
    return
  end
  min.downto(k+1) do |i|
    if is_g?(i, max, n, k, sum)
      puts i
      return
    end
  end
end

solve
```
