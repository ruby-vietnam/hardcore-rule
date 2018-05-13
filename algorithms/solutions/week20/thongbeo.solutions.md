#Problem 2
``` Java
class Solution {
    public int myAtoi(String str) {
        if (str == null || str.length() == 0){
            return 0;
        }
        
        char[] chars = str.toCharArray();
        int i = 0;
        double num = 0;
        // trim
        while (i < chars.length && chars[i] == ' '){ i++;}
        
        //mark
        boolean negative = false;
        if (i < chars.length && (chars[i] == '-' || chars[i] == '+')){
            negative = chars[i] == '-';
            i++;
        }
        
        while( i < chars.length){ 
             int digit = chars[i] - '0';
            if (digit < 0 || digit > 9){
                break;
            }
            num = num*10 + digit;
             if(num > Integer.MAX_VALUE || (num*-1) < Integer.MIN_VALUE){ 
                if(negative) {
                    return Integer.MIN_VALUE;
                }
                return Integer.MAX_VALUE;
            }
            i++;
        }
        return negative? (int)(num*-1) : (int)num;
    }
}
```
