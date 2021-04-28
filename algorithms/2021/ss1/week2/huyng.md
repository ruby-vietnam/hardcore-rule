## 1. Last Stone Weight
### 1.1. Summary
You'll need a data structure that maintain two maximum elements.
Then, just follow what the statement said.

I used [priority_queue](https://www.cplusplus.com/reference/queue/priority_queue/) in C++, it also known as [Heap (data structure)](https://en.wikipedia.org/wiki/Heap_(data_structure)).

### 1.2. Solution summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 7.6 MB   | 68.14%    |

### 1.3. Source code
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int stone : stones) {
            q.push(stone);
        }

        while (q.size() > 1) {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            q.push(abs(x - y));
        }

        return q.top();
    }
};
```

## 2. Last Stone Weight II
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 7.9 MB   | 92.44%    |

### 2.2. Solution summary
The idea is that you split the array *stones* into two array *A* and *B*.
It is required that the difference of sum of *A* and sum of *B*
is **smallest**.

To do that, let *maximumWeight* of each set is *totalWeight / 2*.
We need to find the subset of the *stones* array which have the total
not greater than *maximumWeight*.

Suppose we found that subset, and the total is *weight*.
The rest would have the total is *totalWeight - weight*. So that,
the result is the difference of the total of two subsets. It can be
written as *totalWeight - 2 * weight*.

Take an example:
```
stones = [31,26,33,21,40]
```

*totalWeight* = 151 and *maximumWeight* = 151 / 2 = 75

You only can find the subset have maximum total which not greater
than maximumWeight is `[33, 40]`. Its total is 73.

So that, the total of the second (aka the rest) subset
is 151 - 73 = 78. Then the result will be 78 - 73 = 5.

It also can be calculated by 151 - 73 * 2 = 5 because we can easily
see that 151 can be divided into 73 + 73 + 5.

### 2.3. Source code
```cpp
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int totalWeight = accumulate(stones.begin(), stones.end(), 0);
    int maxWeightEach = totalWeight >> 1;

    vector<bool> f(maxWeightEach + 1);

    f[0] = 1;
    int maxWeight = 0;
    for (int i = 0; i < n; ++i) {
      for (int weight = maxWeightEach; weight >= stones[i]; --weight) {
        if (f[weight - stones[i]]) {
          f[weight] = 1;
          maxWeight = max(maxWeight, weight);
        }
      }
    }

    return totalWeight - 2 * maxWeight;
  }
};
```

## 3. Find K-th Smallest Pair Distance
### 3.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 12ms     | 77.78%      | 10.1 MB  | 35.32%    |

### 3.2. Solution summary
My very first approach is that I try to count all distance
of pairs then find the k-th smallest distance. But living not
dreaming. It is very easy to guess that the solution was TLE.

To that, I think what if I have *X* as a k-th smallest
distance, it is easier now because you can binary search the
*X* and you will find the smallest *X* whose the amount of
pairs is equal or greater than *k*.

***Alert:** Don't ask me how I come up with this approach, it
is experience.*

Besides that, how you count the amount of pairs have
distance is less or equal to *k*. I suggest using [Sliding 
Window Technique](https://www.geeksforgeeks.org/window-sliding-technique/).

By sorting the given list, you need to try to keep the most
left position *L* that the distance between current number
*nums[i]* and *nums[L]* is less or equal to *X*. If is greater,
try to move the *L* to the next position where it satisfies the
condition. Then, the amount of pairs at position *i* has
distance is less or equal to *X* is *i - L*. Do the same with
all positions then you have an amount of satisfying pair.

### 3.3. Source code
```cpp
const int MAGIC = 1000000;

class Solution {
public:
    int countPair(vector<int>& nums, const int& d) {
        int n = nums.size(), cnt = 0, j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && abs(nums[i] - nums[j + 1]) <= d) j++;
            cnt += j - i;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int lo = 0, hi = MAGIC, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (countPair(nums, mid) < k) {
                lo = mid + 1;
            } else {
                res = mid;
                hi = mid - 1;
            }
        }

        return res;
    }
};
```

## 4. Extra problem: Greatest Sum Divisible by Three
### 4.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 72ms     | 39.12%      | 25 MB    | 79.02%    |

### 4.2. Solution summary
I used [Dynamic Programming](https://vnoi.info/wiki/translate/topcoder/dynamic-programming.md)
for this problem.

#### Very-first approach:
Let *f[i][mod]* is the greatest sum that have the module of
dividing by 3 is *mod* in the sub-array *[1..i]*.

Then I came up with the recursive equation:

```
mod_a = a[i] % 3;

f[i][mod] = max(
    f[i - 1][mod],
    f[i][(mod - mod_a + 3) % 3])
```

The result is *f[n][0]* with *n* is the length of the array and
it is also mean that the greatest sum that divisible by 3 in the
sub-array *[1..n]*.

#### Memory-optimized approach
It easily to see that we only use the current state for
calculating the next state. Then, we can reduce by use
two vectors: the first one for storing the current state and
the second one for calculating the next state.

You can see the implementation below.

### 4.3. Source code
```cpp
class Solution {
public:
  int maxSumDivThree(vector<int>& a) {
    int n = a.size();

    vector<int> f(3), f_next(3);
    for (int i = 1; i <= n; i++) {
      // use f_next for saving the next state of f
      f_next = f;

      for (int mod = 0; mod < 3; mod++) {
        int mod_need = (mod - (a[i - 1] % 3) + 3) % 3;
        if (f[mod_need] % 3 != mod_need) continue;
        f_next[mod] = max(f[mod], f[mod_need] + a[i - 1]);
      }

      // assign f to the next state
      f = f_next;
    }

    return f[0];
  }
};
```
