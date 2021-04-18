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
