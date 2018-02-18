# Problem set 1

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var findLHS = function(nums) {
    let map = {}, max = 0
    for (ele of nums) map[ele] = map[ele] + 1 || 1

    for (key in map) {
      if (map[key] + map[key - 1] > max) max = map[key] + map[key - 1]
      if (map[key] + map[parseInt(key) + 1] > max) max = map[key] + map[parseInt(key) + 1]
    }

    return max
};
```
