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

# Merge Intervals

## Summary

``` typescript
function merge(intervals: number[][]): number[][] {
    intervals.sort((a,b) => a[0] - b[0] || a[1] - b[1])
    let result = []
    for(let interval of intervals) {
        if(result.length && interval[0] <= result[result.length - 1][1]) {
            result[result.length - 1][1] = Math.max(result[result.length - 1][1], interval[1])
            continue
        } else {
            result.push(interval)
        }
    }
    return result
};
```

# Candy 

## Summary

``` typescript
function candy(ratings: number[]): number {
    let candies = Array(ratings.length).fill(1)
    for(let i = 1; i < ratings.length; i++) {
        if(ratings[i] > ratings[i-1] && candies[i] <= candies[i - 1]) {
            candies[i] = candies[i-1] + 1
        }
    }
    
    for(let i = ratings.length - 1; i >= 0; i--) {
        if(ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
            candies[i-1] = candies[i] + 1
        }
    }
    let result = 0
    for(let candy of candies) result += candy
    return result
};
```


