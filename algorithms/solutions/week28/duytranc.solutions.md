# Problem 1
#### [Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/description/)
```cs
public class Solution {
    public bool CheckPossibility(int[] nums) {
        var wrongPos = -1;
        var len = nums.Length;
        for(var i = 0 ; i < len; ++i)
        {
            if(i + 1 < len && nums[i] > nums[i + 1])
            {
                if(wrongPos == -1)
                {
                    wrongPos = i;
                }
                else
                {
                    return false;    
                }
            }
        }
        return wrongPos == -1 
            || wrongPos == 0 
            || nums[wrongPos - 1] <=  nums[wrongPos + 1] 
            || wrongPos == len - 2 
            || nums[wrongPos] <=  nums[wrongPos + 2];
       
    }
}
```

# Problem 2
#### [Permutations](https://leetcode.com/problems/permutations/description/)
```cs
public class Solution {
    private IList<IList<int>> Result { get; set; }
    
    public IList<IList<int>> Permute(int[] nums) {
        Result = new List<IList<int>>();
        GeneratePermutation(nums, nums.Length);
        return Result;
    }
    
    private void GeneratePermutation(int[] nums, int n)
    {
        if(n == 1)
        {
            Result.Add(nums.ToList());
            return;
        }
        
        for(var i = 0; i < n - 1; ++i)
        {
            GeneratePermutation(nums, n - 1);
            
            if((n & 1) == 0)
            {
                Swap(nums, i, n - 1);
            }
            else
            {
                Swap(nums, 0, n - 1);
            }
        }
        GeneratePermutation(nums, n - 1);
    }
    
    private void Swap(int[] nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
}
```

