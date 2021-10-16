# Triangle

## Summary
- Save previous row for each row

``` typescript
function minimumTotal(triangle: number[][]): number {
    let previousRow = triangle[0]
    for(let row = 1; row < triangle.length; row++) {
        let currentRow = Array(triangle[row].length)
        for(let col = 0; col < triangle[row].length; col++) {
            let up = col >= previousRow.length ? Number.MAX_SAFE_INTEGER : previousRow[col]
            let left = col - 1 < 0 ? Number.MAX_SAFE_INTEGER : previousRow[col - 1]
            currentRow[col] = Math.min(up, left) + triangle[row][col]
        }
        previousRow = currentRow
    }
    
    return Math.min(...previousRow)
    
};
```

# Palindrome Partitioning

## Summary
- Backtrack with DP

``` typescript
function partition(s: string): string[][] {
    let result = []
    let dp = Array(s.length)
    let cacheCheck = Array(s.length).fill(0).map(() => Array(s.length))
        
    let isPalindrome = (start, end) => {
        if(cacheCheck[start][end] !== undefined) return cacheCheck[start][end]
        while(start < end) {
            if(s[start] !== s[end]) {
                cacheCheck[start][end] = false
                return false
            }
            start++
            end--
        }
        cacheCheck[start][end] = true
        return true
    }
    
    let dfs = (idx) => {
        if(idx >= s.length) {
            return [""]
        }
        let result = []
        for(let i = idx; i < s.length; i++) {
            if(isPalindrome(idx, i)) {
                let parts = dfs(i + 1)
                for(let part of parts) {
                    result.push([s.slice(idx, i + 1), ...part])
                }
            }
        }
        dp[idx] = result
        return result
    }
    return dfs(0)
};
```

