# 1046. Last Stone Weight
_https://leetcode.com/problems/last-stone-weight/_

## Brute-force Approach

**Algorithm:**
- While the vector has at least 2 elements:
    - Sort it (in the ascending order).
    - Choose the two heaviest stones (`x, y`) and smash them together.
    - Erase them from the vector.
    - If both of them have the same weights, they are totally destroyed. Otherwise, add a new stone to the vector with weights `x-y`.
- After the loop above, if we have 1 stone left in the vector, return its weight. Otherwise, return `0`.

**Analysis:**
- Time complexity: `O(n^2logn)`
- Space complexity: `O(1)`

**Submission Detail:**
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int len = stones.size();
            int smash = stones[len-1] - stones[len-2];
            stones.erase(stones.end() - 2, stones.end());
            if (smash > 0) {
                stones.push_back(smash);
            }
        }
        if (stones.empty() == true) {
            return 0;
        }
        return stones[0];
    }
};
```
```
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
Memory Usage: 7.6 MB, less than 69.19% of C++ online submissions for Last Stone Weight.
```

## Better Approach

Construct a `priority_queue` that all elements are always in non ncreasing order.

**Algorithm:**
- While the priority queue has at least 2 element:
    - Get 2 first elements of the queue, smash them together, and pop them out.
    - If both of them have the same weights, they are totally destroyed. Otherwise, add a new stone to the queue with weights `x-y`.
- After the loop above, if we have 1 stone left in the queue, return its weight. Otherwise, return `0`.

**Analysis:**
- Time complexity: `O(nlogn)`
- Space complexity: `O(n)`

**Submission Detail:**
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> gq(stones.begin(), stones.end());
        while (gq.size() > 1) {
            int top1 = gq.top();
            gq.pop();
            int top2 = gq.top();
            gq.pop();
            int smash = top1 - top2;
            if (smash > 0) {
                gq.push(smash);
            }
        }
        if (gq.empty() == true) {
            return 0;
        }
        return gq.top();
    }
};
```
```
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
Memory Usage: 7.6 MB, less than 23.19% of C++ online submissions for Last Stone Weight.
```
