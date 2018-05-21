# #1
``` js
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let unique = [...new Set(nums)];
    let c = -1;
    unique.forEach((n, i) => {
        const l = nums.filter(x => x === n).length;
        if (l > nums.length / 2)
            if (l > 0)
                c = i;
    });

    if (c > -1)
        return unique[c];
};
```

# #2
``` js
/**
 * @param {number} n
 * @return {number}
 */
var bulbSwitch = function (n) {
    return parseInt(Math.sqrt(n))
}

```

# #3
``` js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    const nums3 = nums1.concat(nums2).sort(sortNumber);
    const i = parseInt(nums3.length / 2);
    if (nums3.length % 2 === 0) {
        return (nums3[i] + nums3[i - 1]) / 2;
    } else {
        return nums3[i];
    }
};

var sortNumber = function (a, b) {
    return a - b;
}
```

# #4
``` js
/**
 * @param {number[]} nums
 */
var NumArray = function (nums) {
    this.nums = nums;
};

/** 
 * @param {number} i 
 * @param {number} val
 * @return {void}
 */
NumArray.prototype.update = function (i, val) {
    this.nums[i] = val;
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function (i, j) {
    let c = 0;
    for (let z = i, l = this.nums.length; z <= j; z++) {
        c += this.nums[z];
    }
    return c;
};
```
