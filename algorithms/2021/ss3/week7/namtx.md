# 169. Majority Element

https://leetcode.com/problems/majority-element/

### Approach

We use a `curr` and `count` to keep track the majority and its count respectively, the initial value is the first element.

For each number in `nums`:
- If `nums[i] == curr`, we increase the count by 1.
- If not, we decrease the `count` by 1

If the `count` value is reset to `0`, it means we have to reassign the `curr` to the current checking number.

### Submission

```java
class Solution {
    public int majorityElement(int[] nums) {
        int curr = nums[0];
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (count == 0) {
                curr = nums[i];
                count++;
            } else {
                if (nums[i] == curr) {
                    count++;
                } else {
                    count--;
                }
            }

        }

        return curr;
    }
}
```

### Submission detail

47 / 47 test cases passed.
	Status: Accepted
Runtime: 1 ms
Memory Usage: 42.3 MB

### Analyze

- Time complexity O(n)
- Space complexity O(1)

# 905. Sort Array By Parity

https://leetcode.com/problems/sort-array-by-parity/

### Approach - Two pointers

We use two pointers `l` and `h`, those initial value are `0` and `nums.length -1` respectively.

Move `l` and `h` through the array. We skip numbers which is in correct position already. 
Whenever we found the incorrect position number, we swap them.
And finally, we get the array with all numbers in correct place.

### Submission

```java
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int N = nums.length;
        int l = 0;
        int h = N - 1;

        while (l < h) {
            if (nums[l] % 2 == 0) {
                l++;
            } else if (nums[h] % 2 != 0) {
                h--;
            } else {
                int tmp = nums[l];
                nums[l] = nums[h];
                nums[h] = tmp;
            }
        }

        return nums;
    }
}
```

### Submission detail

285 / 285 test cases passed.
	Status: Accepted
Runtime: 1 ms
Memory Usage: 40.1 MB

### Analyze

- Time complexity O(n)
- Space complexity O(1) since we don't use any extra place.

# 15. 3Sum

https://leetcode.com/problems/3sum/

### Approach - Two pointers

The approach we have is the same with [Two Sum](https://leetcode.com/problems/two-sum/)

Firstly, we sort the `nums` by ascending order.

For each `nums[i]`, we will check the range `nums[i+1..nums.length-1]`, by using two pointer `l` and `h`. And in order to fulfill the expectation: `nums[i] + nums[l] + nums[h] == 0`, we have to find the `l` and `h` with `nums[l] + nums[h] = - numbs[i]`.

To skip the duplicated pair, we will skip all `nums[i]` which has the same value with `nums[i-1]`.

### Submissiono

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int N = nums.length;
        List<List<Integer>> r = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < N - 2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) { // already checked
                continue;
            }
            int target = -nums[i];
            int l = i+1;
            int h = N - 1;
            while (l < h) {
                int s = nums[l] + nums[h];
                if (s > target) {
                    h--;
                } else if (s < target) {
                    l++;
                } else {
                    List<Integer> item = new ArrayList<>();
                    item.add(nums[i]);
                    item.add(nums[l]);
                    item.add(nums[h]);

                    r.add(item);
                    while (l < h && nums[l] == nums[l+1])
                        l++;

                    while (l < h && nums[h] == nums[h-1])
                        h--;
                    
                    l++;
                    h--;
                }
            }
        }

        return r;
    }
}
```

### Submission detail

318 / 318 test cases passed.
	Status: Accepted
Runtime: 28 ms
Memory Usage: 57.2 MB

### Analyze

- Time complexity: O(n^2)
- Space complexity: O(1)
