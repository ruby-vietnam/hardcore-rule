#Problem 1
``` Java
class Solution {
    public String[] findWords(String[] words) {
        List<String> result = new ArrayList<String>();
        for (String word : words){
            boolean shouldAppen = true;
            char[] chars = word.toCharArray();  
            int row = getRow(chars[0]);
            for (int i = 1 ; i < chars.length ; i++){
                if (getRow(chars[i]) != row){
                    shouldAppen = false;
                    break;
                }
            }
            if (shouldAppen)
                result.add(word);
        }
        return result.toArray(new String[result.size()]);
    }
    
    private int getRow(char ch){
        String row1 = "qwertyuiopQWERTYUIOP";
        String row2 = "asdfghjklASDFGHJKL";
        String row3 = "zxcvbnmZXCVBNM";
        if (row1.indexOf(ch) != -1)
            return 1;
        if (row2.indexOf(ch) != -1)
            return 2;
        if (row3.indexOf(ch) != -1)
            return 3;
        return -1;
    }
}
```
