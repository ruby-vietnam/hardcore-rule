# Find the Town Judge

``` typescript
function findJudge(n: number, trust: number[][]): number {
    let like = Array(n + 1).fill(0)
    let beLike = Array(n + 1).fill(0)
    for(let i = 0; i < trust.length; i++) {
        like[trust[i][0]]++
        beLike[trust[i][1]]++
    }
    for(let i = 1; i <= n; i++) {
        if(beLike[i] === n - 1 && like[i] === 0) return i
    }
    return -1
};
```