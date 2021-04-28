## 1048. Last Stone Weight

https://leetcode.com/problems/last-stone-weight/

The requirement is trivial:

```
1 <= stones.length <= 30
1 <= stones[i] <= 1000
```

We don't need any optimization or fancy algorithm for this problem. Loop, sort, reduce, and repeat until there is one element. We need to loop exactly length - 1 times.

```ruby
def last_stone_weight(stones)
  stones.tap { |s| 1.upto(s.length - 1) { s.push(s.sort!.pop(2).reduce(&:-).abs) } }.first
end
```

```
Runtime: 48 ms, faster than 90.48% of Ruby online submissions for Last Stone Weight.
Memory Usage: 209.9 MB, less than 52.38% of Ruby online submissions for Last Stone Weight.
```

## 1049. Last Stone Weight II

https://leetcode.com/problems/last-stone-weight-ii/

Starting with 1 stone [s1], the result is of course s1.
If there are two stones [s1, s2], the result is s1 - s2 or s2 - 21
If there are three stones [s1, s2, s3], the result is either s1 - (s2 + s3) or s2 - (s1 + s3) or s3 - (s1 + s2) or (s1 + s2) - s3 or (s1 + s3) - s2 or (s2 + s3) - s1.
If there are four stones [s1, s2, s3, s4], the result is s1 - (s2 + s3 + s4) or (s1 + s2) - (s3 + s4) or (s1 + s3) - (s2 + s4) etc.
If we keep going and generalize the each case, the result of the set of S = [s1, s2, s3, ... sn] is (t1 + t2 + t3 + ... + tn) - (u1 + u2 + u3 + ... +um), in which (t1..tn) is a subset of S, (u1..um) is a subset of S, and (t1..tn) does not interset with (u1..um).

Optimizing the result means that the difference between sum(t1..tn) and sum(u1..um) must be smallest. The problem becomes splitting a set into two subsets with minimum difference, aka 0-1 knapsack.

Implement a full knapsack algorithm is ... troublesome. I would love to suggest another simpler one.

Considering `sums` is a flagging array from 0 to sum(stones) / 2. At each iterating each stone in the array, we loop from sum(stones) / 2 down to 0; flag the current sum if sums[sum - stone(i)] is true. Finally, loop from sum(stones)/2 back to 0, and return the first flagged sum. Backward iteration is the key to prevent duplication flagging.

We can optimize more by maintaing a max sum to loop from there instead of the maximum sum.

```ruby
def last_stone_weight_ii(stones)
  sum = stones.sum
  target = sum / 2
  sums = Array.new(target) { false }
  sums[0] = true

  max_sum = 0

  stones.each do |stone|
    max_sum += stone
    [target, max_sum].min.downto(1) do |t|
      break if t < stone

      sums[t] = true if sums[t - stone]
    end
  end

  target.downto(0) do |t|
    return (sum - 2 * t).abs if sums[t]
  end
end
```

```
Runtime: 48 ms, faster than 100.00% of Ruby online submissions for Last Stone Weight II.
Memory Usage: 209.8 MB, less than 100.00% of Ruby online submissions for Last Stone Weight II.
```
