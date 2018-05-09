## Problem 1 - [Nim Game](https://leetcode.com/problems/nim-game/description/)

Gọi n là số lượng viên đá, 2 người chơi là A và B, A có lượt bốc đầu tiên, số lượng viên đá có thể bốc là 1,2 hoặc 3. Ta dễ dàng nhận thấy rằng:
- Với n < 4: A luôn thắng
- Với n = 4: B luôn thắng dù cho số lượng viên đá A bốc được là bao nhiêu
- Với n = 5: A sẽ thắng nếu bốc 1 viên. Lúc này đến lượt B sẽ rơi vào trường hợp như khi n = 4
- Với n = 6: A sẽ thắng nếu bốc 2 viên
- Với n = 7: A sẽ thắng nếu bốc 3 viên
- Với n = 8: B luôn thắng. Dù cho A bốc 1,2 hoặc 3 thì B chỉ cần bốc ngược lại 3,2 hoặc 1 thì sẽ chiến thắng
.....
- Tổng quát với n viên đá, dễ dàng nhận thấy A chỉ thua khi số lượng viên đá n chia hết cho 4

```go
func canWinNim(n int) bool {
    return n % 4 != 0
}
```

## Problem 2 - [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/description/)

Gọi t1, t2 là thời điểm attack của Teemo (t1 < t2). T là thời điểm tối đa Ashe bị dính độc. Vì độc của Teemo không stack nên ta có thể thấy 2 trường hợp xảy ra:
- TH 1 `t2 > T` : tổng thời gian dính độc của Ashe cộng thêm `duration` giây
- TH 2 `t2 <= T` : tổng thời gian dính độc của Ashe chỉ cộng thêm `t2 - t1` giây do không bị stack

Lời giải sẽ như sau:

```go
func findPoisonedDuration(timeSeries []int, duration int) int {
    n := len(timeSeries)
    
    if timeSeries == nil || n == 0 {
        return 0
    }
    
    if n == 1 {
        return duration
    }
    
    totalTimePoisoned, maxTime := duration, timeSeries[0] + duration - 1
    for i := 1; i < n; i++ {
        if timeSeries[i] > maxTime {
            totalTimePoisoned += duration
        } else {
            totalTimePoisoned += timeSeries[i] - timeSeries[i-1]
        }
        maxTime = timeSeries[i] + duration - 1
    }
    return totalTimePoisoned
}
```
