# Season 4 - Week 4

### 1. Best Time to Buy and Sell Stock
- Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

```JS
var maxProfit = function(prices) {
    let min = prices[0];
    let profit = 0;
    for(let i = 0; i< prices.length; i++){
        min = Math.min(min,prices[i]);
        profit = Math.max(profit,prices[i]-min);
   
    }
    return profit;
};
```

### 2. Two Sum
- Problem: https://leetcode.com/problems/two-sum/
``` JS

var twoSum = function(nums, target) {
    let hashMap = {};
    const length = nums.length;
    for(let i = 0; i<length;i++){
    
        if(hashMap[nums[i]]!== undefined) return [hashMap[nums[i]],i];
        hashMap[target - nums[i]] = i;
    }
};
```

### 3. Merge Intervals
- Problem:  https://leetcode.com/problems/merge-intervals/
```JS

var merge = function(intervals) {
    const  length = intervals.length;
    let sortArr = intervals.sort((a,b)=>a[0]-b[0])
    const result = [sortArr[0]];
    for(let i = 1; i<length ; i++){
        const data = result.pop();
        if(data[1] >= sortArr[i][0]){
            const a = Math.min(data[0],sortArr[i][0]);
            const b = Math.max(data[1],sortArr[i][1]);
            result.push([a,b]);
        }
        else{
            result.push(data);
            result.push(sortArr[i]);
        }
    }
    return result;
};
```

### 4. Find First and Last Position of Element in Sorted Array
- Problem:  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
```JS

var searchRange = function(nums, target) {
    let i = 0 ;
    let result = [];
    let flag = false;
    while (i <nums.length){
       
        if(nums[i] === target && !flag){
            flag=true;
            result.push(i);
        }
        if(flag && nums[i] !== target  ){
            result.push(i-1);
            return result;
        }
        if(flag && nums[i] == target && i === nums.length-1  ){
            result.push(i);
            return result;
        }
        i++;
    };
    if(result.length === 0) return [-1,-1];
    return result;
};
```

### 5. Candy
- Problem:  Candy
```JS

var candy = function(ratings) {
    const length = ratings.length;
    let leftArr = new Array(length);
    let rightArr = new Array(length);
    
    let n = 1;
    for(let i = 0 ;i < length ; i++){
        if( ratings[i] >ratings[i-1]){
            n++;
            leftArr[i] = n;
        }else {
            n=1;
            leftArr[i] = n;
        }
    }
    n=1;
    let sum = 0;
    for(let i = length-1 ;i >=0 ; i--){
        if(ratings[i] >ratings[i+1]){
            n++;
            rightArr[i] = n;
        }else {
            n=1;
            rightArr[i] = n;
        }
        sum +=Math.max(leftArr[i],rightArr[i]);
    };

    return sum;
 
};
```
