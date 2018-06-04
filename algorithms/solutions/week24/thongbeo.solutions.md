#Problem 1
``` Java
class Solution {
    public boolean judgeSquareSum(int c) {
        if (c == 0)
            return true; 
        int l = 0;
        int r = (int)Math.sqrt(c);
        while(l <= r){
            int cur = l * l + r * r;
            if (cur == c)
                return true;   
            if (cur > c)
                r--;
            else 
                l++;
        }
        return false;
    }
}
```

#Problem 2
``` Java
class Solution {
    public String largestNumber(int[] nums) {
        if (nums.length == 0)
            return "";
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; i++){
            strs[i] = String.valueOf(nums[i]);
        }
    
        Arrays.sort(strs, new Comparator<String>()
        {
            @Override
            public int compare(String s1, String s2)
            {
                return (s2 + s1).compareTo(s1 + s2);
            }
        });
        
        if (strs[0].equals("0"))
            return "0";
        
        StringBuilder sb = new StringBuilder();
        for(String str : strs){
            sb.append(str);
        }
        
        return sb.toString();
    }
}
```
