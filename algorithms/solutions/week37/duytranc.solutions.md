# Problem 2
#### [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/)
```cs
public class Solution {
    private static readonly int MAX = 20001;
    private static readonly int BASE = 10000;
    
    public IList<int> FindClosestElements(int[] arr, int k, int x) {
        var positions = new int[MAX];

            foreach (var item in arr)
            {
                positions[item + BASE]++;
            }

            var results = new int[k];
            var index = 0;

            var midIndex = x + BASE;
            var leftIndex = x + BASE;
            var rightIndex = x + BASE;

            while (k > 0)
            {
                while (leftIndex >= 0 && positions[leftIndex] == 0) leftIndex--;
                while (rightIndex < MAX && positions[rightIndex] == 0) rightIndex++;

                
                var isLeftValid = leftIndex >= 0 && positions[leftIndex] > 0;
                var isRightValid = rightIndex < MAX && positions[rightIndex] > 0;
                
                if (isLeftValid && isRightValid)
                {
                    if(midIndex - leftIndex <= rightIndex - midIndex)
                    {
                        results[index++] = leftIndex - BASE;
                        positions[leftIndex]--;
                        k--;
                    }
                    else
                    {
                        results[index++] = rightIndex - BASE;
                        positions[rightIndex]--;
                        k--;
                    }
                }
                else if (isLeftValid)
                {
                    results[index++] = leftIndex - BASE;
                    positions[leftIndex]--;
                    k--;
                }
                else if (isRightValid)
                {
                    results[index++] = rightIndex - BASE;
                    positions[rightIndex]--;
                    k--;
                }
            }

            Array.Sort(results);
            return results;
    }
}
```