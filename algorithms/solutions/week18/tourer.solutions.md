# Problem 1:
#### [Min Stack](https://leetcode.com/problems/min-stack/)
```
class MinStack {
    private List<Integer> data;
    private List<Integer> prefixMin;
    
    /** initialize your data structure here. */
    public MinStack() {
        data = new ArrayList<>();
        prefixMin = new ArrayList<>();
    }
    
    public void push(int x) {
        data.add(x);
        int index = data.size() - 1;
        if(index > 0) {
            prefixMin.add(Math.min(prefixMin.get(index-1), x));
        } else {
            prefixMin.add(x);
        }
    }
    
    public void pop() {
        if(data.size() > 0) {
            data.remove(data.size() - 1);
            prefixMin.remove(prefixMin.size() -1);
        }
    }
    
    public int top() {
        return data.get(data.size() - 1);
    }
    
    public int getMin() {
        return prefixMin.get(prefixMin.size() - 1);
    }
}
```
# Problem 2:
#### [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)
```
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        for(int i = 1, len = s.length(); i < len-2;i++) {
            String octet1 = s.substring(0,i);
            if(!validOctet(octet1)) break;
            for(int j = i+1; j < len-1; j++) {
                String octet2 = s.substring(i,j);
                if(!validOctet(octet2)) break;
                for(int k = j+1; k < len; k++) {
                    String octet3 = s.substring(j,k);
                    String octet4 = s.substring(k,len);
                    if(!validOctet(octet3)) break;
                    if(validOctet(octet4)) {
                        String ip = octet1 + "." + octet2 + "." + octet3 + "." + octet4;
                        res.add(ip);
                    }
                }
            }
        }
        
        return res;
    }
    
    private boolean validOctet(String octet) {
        return !"".equals(octet) && octet.length() < 4 && (octet.length() == 1 || octet.charAt(0) != '0') && Integer.parseInt(octet) < 256;
    }
}
```
# Problem 3:
#### [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)
```
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] f = new boolean[s.length()+1][p.length()+1];
        f[0][0] = true;
        for(int i = 0, len1 = s.length(); i <= len1; i++) {
            for(int j = 0, len2 = p.length(); j < len2; j++) {
                if(!f[i][j]) continue;
                if(p.charAt(j) == '*') {
                    for(int k = i; k <= len1; k++) {
                        f[k][j+1] = true;
                    }
                } else if(i < len1) {
                    f[i+1][j+1] |= s.charAt(i) == p.charAt(j) || p.charAt(j) == '?';
                }
            }
        }

        return f[s.length()][p.length()];
    }
}
```
# Problem bonus
#### [Edit Distance](https://leetcode.com/problems/edit-distance/)
```
class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int[][] f = new int[len1+1][len2+1];
        for(int i = 0; i <= len1; i++) {
            Arrays.fill(f[i], Integer.MAX_VALUE-2);
        }
        f[0][0] = 0;
        for(int i = 0; i <= len1; i++) {
            for(int j = 0; j <= len2; j++) {
                if(i < len1 && j < len2 && word1.charAt(i) == word2.charAt(j)) {
                    f[i+1][j+1] = Math.min(f[i+1][j+1],f[i][j]);
                }
                // delete
                if(i+1 <= len1) {
                    f[i+1][j] = Math.min(f[i+1][j],f[i][j] + 1);
                }
                // replace
                if(i+1 <= len1 && j+1 <= len2) {
                    f[i+1][j+1] = Math.min(f[i+1][j+1], f[i][j] + 1);
                }
                // insert
                if(j+1 <= len2) {
                    f[i][j+1] = Math.min(f[i][j+1],f[i][j] + 1);
                }
            }
        }
        
        return f[len1][len2];
    }
}
```
