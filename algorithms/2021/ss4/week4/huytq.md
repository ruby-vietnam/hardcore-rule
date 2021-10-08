# Best Time to Buy and Sell Stock

## Summary

``` typescript
function maxProfit(prices: number[]): number {
    let min = prices[0]
    let result = 0
    for(let i = 0; i < prices.length; i++) {
        result = Math.max(result, prices[i] - min)
        min = Math.min(min, prices[i])
    }
    return result
};
```


# Two Sum

## Summary

``` typescript
function twoSum(nums: number[], target: number): number[] {
    let seen = new Map()
    for(let i = 0; i < nums.length; i++) {
        if(seen.has(target - nums[i])) {
            return [seen.get(target - nums[i]), i]
        }
        seen.set(nums[i], i)
    }
    return []
};
```
