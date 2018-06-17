#Problem 1
``` Java 
class Solution {
    public char findTheDifference(String s, String t) {
        char[] arrs = s.toCharArray();
        char[] arrt = t.toCharArray();
       
        int sum = 0; 
        for (int i = 0 ; i < arrs.length ; i++){
            sum += (arrt[i] - arrs[i]);   
        }
        return (char)(arrt[arrt.length -1] + sum);
    }
}
```
