#Problem 1 
``` Java 
class Solution {
    public String countAndSay(int n) {
        String[] arrs = new String[n];
        arrs[0] = "1"; // first
        for(int i = 1; i < n ; i++){
            String s = arrs[i-1];
            char[] chars = s.toCharArray();
            int count = 0;
            char cur = chars[0];
            StringBuilder sb = new StringBuilder();
            for (char ch : chars){
                if (ch == cur){
                    count++;
                }else{
                    sb.append(count);
                    sb.append(cur);
                    count = 1;
                    cur = ch;
                }
            }
            sb.append(count);
            sb.append(cur);
            
            arrs[i] = sb.toString();
        }
        return arrs[n -1];
    }
}
```
