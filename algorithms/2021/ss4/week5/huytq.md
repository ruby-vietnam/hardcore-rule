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