## 1. [997] Find the Town Judge

https://leetcode.com/problems/find-the-town-judge/description/

### 1.1 Approach

- Loop through trust, sumup the trust count, if it's a truster then don't count it a jugde by set negative MAX_NUM to it. If it reaches n-1, then it's a judge

### 1.2 Code

```js
/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function (n, trust) {
    const h = {}
    const max = 0;

    if (n === 1 && trust.length === 0) {
        return 1;
    }
    for (let i = 0; i < trust.length; i++) {
        const t = trust[i];
        h[t[1]] = (h[t[1]] ?? 0) + 1
        h[t[0]] = -Number.MAX_SAFE_INTEGER;
    }
    const keys = Object.keys(h)
    for (let i = 0; i < keys.length; i++) {
        if(h[keys[i]] === n-1) return keys[i]
    }
    
    return -1;
};
```

## 2. [1046] Last Stone Weight

https://leetcode.com/problems/find-the-town-judge/description/

### 2.1 Approach

- Sort the stones DESC, remove 2 first item, insert back the result of substraction (if the result >0) via `insertValueToDESCSortedArray`

### 2.2 Code

```js
/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeight = function(stones) {
    stones.sort((b,a)=>a-b)
    // console.log(stones)
    while(stones.length > 1) {
        const d = stones[0] - stones[1];
        stones.splice(0, 2);
        if (d > 0){
            insertValueToDESCSortedArray(stones, d);
        }
    }
    return stones.length === 0 ? 0 : stones[0];
};

function insertValueToDESCSortedArray(arr, val) {
    let i = 0;
    while (i < arr.length && arr[i] > val) {
        i++;
    }
    arr.splice(i, 0, val);
}
```

