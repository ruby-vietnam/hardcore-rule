## Bài 1: https://leetcode.com/problems/divide-two-integers/description

Có 2 cách cơ bản để biểu diễn một số
1. N = a1^b1 a2^b2 ... an^bn trong đó a1 .. an là các số nguyên tố
2. N = 2^0 * a0 + 2^1 * a1 + ...

Để tính giá trị của phép chia X / Y chẳng hạn. Ta giả sử giá trị này là Z, vì vậy X = Y * Z + số dư. 

Biểu diễn Z dưới dạng nhị phân Z = 2^0 * a0 + ... 2^n * an. Ta có: X = Y * (2^0 * a0 + ... + 2^n * an) + số dư.

Ở đây có điểm đáng chú ý là Y * 2^k * ak == (Y << k) là một phép dịch bit của số Y đi k bit nếu ak = 1. Nếu ak = 0 thì không xét.

Từ nhận xét trên, ta có thể xây dựng số Z bằng cách tìm các bit 1 của nó. Các bit 1 của nó tìm thế nào:
1. Dịch Y sang trái k bit, cho tới khi (Y << k) > X 
=> bit thứ k - 1 chắc chắn là bit 1 của số Z
2. Bật bit thứ k - 1 của số Z
3. X = X - (Y << (k-1)) để lấy phần dư tiếp theo
4. Quay lại bước 1

Source code:
```
func divide(dividend int, divisor int) int {
    if dividend > (1<<31 - 1) || dividend < (-1 << 31) {
        return (1<<31 - 1)
    }
    
    if divisor > (1<<31 - 1) || divisor < (-1 << 31) {
        return (1<<31 - 1)
    }
    
    if divisor == 0 {
        return (1<<31 - 1)
    } else if dividend == 0 {
        return 0
    } 
    
    // mark result is positive or negative interger
    positive := (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)
    
    // make it abs
    if dividend < 0 {
       dividend = -dividend 
    }
    if divisor < 0 {
        divisor = -divisor
    }
    
    // perform
    result := 0
    
    var bitK uint
    for dividend >= divisor {
        for bitK = 0; (dividend >> bitK) >= divisor; bitK++ {
        }
        bitK--
        
        result = result | (1 << bitK)
        dividend -= divisor << bitK
    }
    
    if !positive {
        result = -result
    }
    
    
    if result > (1<<31 - 1) || result < (-1 << 31) {
        return (1<<31 - 1)
    }
    
    return result
}
```

## Bài 2: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Để tìm thời điểm mua vào và bán ra sao cho chênh lệch là lớn nhất, ta có thể dễ dàng raise idea như sau:
* Tại một thời điểm bất kì i nào đó, nếu i là thời điểm bán ra, vậy thời điểm mua vào sẽ là thời điểm nào.

Từ idea này, ta có nhận xét sau: nếu i là thời điểm bán ra, vậy thời điểm mua vào sẽ là một trong những thời điểm từ 1 tới i-1, có value nhỏ nhất và không lớn hơn i.

Ta có thể dễ dàng xử lý trong O(N), lưu lại giá trị nhỏ nhất cứ mỗi lần xét thời điểm nào đó để tính toán cho bước tiếp theo.

Source code:

```
func maxProfit(prices []int) int {
    if prices == nil {
        return 0
    }
    
    n := len(prices)
    if n <= 1 {
        return 0
    }
    
    max, min := 0, prices[0]
    for ind := range prices {
        if prices[ind] - min > max {
            max = prices[ind] - min
        }
        
        if min > prices[ind] { // lưu lại giá trị nhỏ nhất để tính toán bước tiếp theo
            min = prices[ind]
        }
    }
    
    return max
}
```

## Bài 3: https://leetcode.com/problems/candy/description/

Ta có một nhận xét về đặc tính của một mảng như sau:
* Một mảng là một tập hợp của các dãy tăng rồi dãy giảm đang xen nhau (dễ dàng chứng minh)
Ví dụ ban đầu là một dãy con tăng thì chắc chắn kế đó là một dãy con giảm, rồi lại dãy con tăng, rồi lại giảm ...

Do tính chất của bài `Children with a higher rating get more candies than their neighbors.`
và mảng ratings cũng có cấu trúc về dãy tăng và giảm như trên, không làm mất tính tổng quát:

- Giả sử ta có dãy con của mảng ratings trông thế này: r(i) < r(i+1) < ... < r(k) > r(k+1) > r(k+2) ... > r(m)
trong đó r(x) là rating của đứa trẻ có vị trí là x.

Dễ dàng chứng minh rằng để số kẹo bỏ ra là tối thiểu thì:
* Candy(i) = 1, Candy(i+1) = 2, .., Candy(k-1) = k - i
* Candy(m) = 1, Candy(m-1) = 2, .., Candy(k+1) = m - k
* Candy(k) = Max(Candy(k-1), Candy(k+1)) + 1

Vậy mục tiêu là tìm điểm k - peak (gọi nó là peak vì dãy này tăng tới k rồi từ k lại giảm, trông như đỉnh núi ý)
, sau khi tìm điểm peak thì phân bố kẹo như trên.

Corner case của bài này là `higher rating get more candies`, tức là nếu 2 đứa trẻ có rating bằng nhau, đứng cạnh nhau,
thì đứa trẻ xếp sau hoàn toàn có thể chỉ có 1 cái kẹo mà thôi.

Source code

```
func candy(ratings []int) int {
    if ratings == nil || len(ratings) == 0 {
        return 0
    }
    
    n := len(ratings)
    if n == 1 {
        return 1
    }
    
    candies := make([]int, n)
    
    i, j, k, peak := 0, 0, 0, 0
    for i < n {
        j = i
        for j + 1 < n && ratings[j] < ratings[j + 1] {
            j++ 
        }
        
        // now j is peak
        peak = j
        
        for j + 1 < n && ratings[j] > ratings[j+1] {
            j++
        }
        
        if i == j {
            if candies[i] == 0 {
                candies[i] = 1
            }
            
            i++
            continue
        }
        
        if i == peak { // case 1: chỉ có dãy giảm
            candies[j] = 1
            for k := j-1; k >= i; k-- {
                candies[k] = candies[k+1] + 1
            }
        } else if j == peak { // case 2: chỉ có dãy tăng
            candies[i] = 1
            for k := i+1; k <= peak; k++ {
                candies[k] = candies[k-1] + 1
            }
        } else { // case 3: peak là đỉnh của đoạn tăng rồi đoạn giảm
            candies[j] = 1
            for k := j-1; k > peak; k-- {
                candies[k] = candies[k+1] + 1
            }
            
            candies[i] = 1
            for k := i+1; k < peak; k++ {
                candies[k] = candies[k-1] + 1
            }
            
            k = peak + 1
            if candies[peak-1] > candies[k] {
                k = peak - 1
            }
            
            candies[peak] = candies[k] + 1
        }
        
        i = j
    }
    
    sum := 0
    for i := range candies {
        sum += candies[i]
    }
    
    return sum
}
```
