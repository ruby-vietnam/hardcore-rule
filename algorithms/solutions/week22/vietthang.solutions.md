# Problem 1

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let temp = {}
    let result
    
    for (let i of nums) {
        temp[i] = temp[i] + 1 || 1
    }
    
    for (let i in temp) {
        if (temp[i] > nums.length / 2) result = parseInt(i)
    }
    
    return result
};
```
