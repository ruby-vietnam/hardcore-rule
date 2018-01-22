## Problem 2: Valid Parenthesis String
- **Leetcode URL**: https://leetcode.com/problems/valid-parenthesis-string/description/
- **Language**: Java
- **Source**:
```
class Solution {
    public boolean checkValidString(String s) {
        if (s == null || s.length() == 0) {
            // An empty string is also valid.
            return true;
        }
        
        int length = s.length();
        ArrayList<Character> queue = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            Character current = s.charAt(i);
            if (current == ')') {
                int size = queue.size();
                if (size == 0) {
                    return false;
                } else {
                    int removeIndex = size - 1;
                    for (int j = removeIndex; j >= 0; j--) {
                        if (queue.get(j) == '(') {
                            removeIndex = j;
                            break;
                        }
                    }

                    queue.remove(removeIndex);
                }
            } else {
                queue.add(current);
            }
        }

        length = queue.size();
        if (length == 0) {
            return true;
        } else {
            int starSize = 0;
            for (int i = length - 1; i >= 0; i--) {
                Character current = queue.get(i);
                if (current == '(') {
                    if (starSize > 0) {
                        starSize--;
                    } else {
                        return false;
                    }
                } else {
                    starSize++;
                }
            }
        }

        return true;
    }
}
```
