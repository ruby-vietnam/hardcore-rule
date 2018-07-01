# Problem 1: #665 - Non decreasing Array

```
Status: Accepted
325 / 325 test cases passed.
Runtime: 68 ms
```

```
var checkPossibility = function(nums) {
    let n = nums.length;
    let count = 0;
        
    for (let i = 0; i + 1 < n; i++) {
        if (nums[i] > nums[i + 1]) {
            count++;
            if (i > 0 && nums[i + 1] < nums[i - 1]) nums[i + 1] = nums[i];
            else nums[i] = nums[i + 1];
        }
    }

    return count <= 1;
};
```
