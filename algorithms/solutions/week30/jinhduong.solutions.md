# #1 Mini-Max Sum
```c#
using System;

namespace week30
{
    class Program
    {
        // Complete the miniMaxSum function below.
        static void miniMaxSum(int[] arr)
        {
            long total = 0;
            foreach (var n in arr) total += n;
            Array.Sort(arr);
            Console.WriteLine($"{total - arr[arr.Length - 1]} {total - arr[0]}");
        }
    }
}
```
