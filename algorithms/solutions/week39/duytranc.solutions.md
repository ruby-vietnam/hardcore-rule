# Problem 1
#### [ Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)
```cs
public class Solution {
    public int Reverse(int x) {
        long result = 0;
        var sign = 1;
        
        if(x < 0){
            sign = -1;
            x = -x;
        }
        
        
        var numbers = new List<long>();
        while(x > 0){
            var num = x % 10;
            numbers.Add(x % 10);
            x /= 10;
        }
        
        var k = 1;
        for(var i = numbers.Count - 1; i >=0; i--){
            result += numbers[i] * k;
            k *= 10;
        }
        
        result *=  sign;
        
        return result >= int.MinValue && result <= int.MaxValue ? (int)result : 0;
    }
}
```