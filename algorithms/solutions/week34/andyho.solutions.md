### Problem 1: https://leetcode.com/problems/house-robber/description/ 

```Scala
import scala.math.max

def rob(nums: Array[Int]): Int = {
    object Solution {
        val result = nums.foldLeft((0,0)) { case ((useLastOne, dontUseLastOne), value) =>
            (dontUseLastOne + value, max(useLastOne, dontUseLastOne))
        }
        max(result._1, result._2);
    }
}
```
