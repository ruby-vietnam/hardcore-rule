# 88. Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/

### Approach

We try compare each number in `nums1` and `nums2`, from the greatest down to the smallest. Get the greater one and place it to the end of `nums1`.
You can follow our approach by the following pic:

![88](https://user-images.githubusercontent.com/25602820/121770278-a0e5a380-cb92-11eb-9af6-3129adab667a.png)


If in case, we traversed all nums in `nums1`, but there are some numbers in `nums2` we just place it to the start of `nums1`

### Submission

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index = m + n - 1;
        m--;
        n--;
        while (n >= 0 && m >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[index--] = nums1[m--];
            } else {
                nums1[index--] = nums2[n--];
            }
        }
        while (n >= 0) {
            nums1[index--] = nums2[n--];
        }
    }
}
```

### Submission detail

59 / 59 test cases passed.
Runtime: 0 ms
Memory Usage: 38.5 MB

### Analyzing

- Time complexity O(m+n)
- Space complexity O(1)

# 384. Shuffle an Array

https://leetcode.com/problems/shuffle-an-array/

### Approach

We follow the Fisher-Yates algorithm as following pic:

![384](https://user-images.githubusercontent.com/25602820/121779912-26377b00-cbc8-11eb-9236-966215ef6f8a.jpeg)

### Submission

```java
class Solution {
    int[] original;

    Random rand = new Random();

    public Solution(int[] nums) {
        original = Arrays.copyOf(nums, nums.length);
    }

    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        int[] shuffled = Arrays.copyOf(original, original.length);
        for (int i = 1; i < shuffled.length; i++) {
            int randIndex = rand(i+1);
            // swap
            int tmp = shuffled[i];
            shuffled[i] = shuffled[randIndex];
            shuffled[randIndex] = tmp;
        }

        return shuffled;
    }

    // Get a random number in range 0..range by XORShift generator
    private int rand(int range) {
        return rand.nextInt(range);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
```

### Submission detail

10 / 10 test cases passed.
Runtime: 75 ms
Memory Usage: 47.6 MB

### Analyzing

- Time complexity O(n)
- Space complexity O(n)
