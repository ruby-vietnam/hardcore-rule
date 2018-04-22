# Problem 1: Isomorphic Strings

```sh
class Solution {
    private char currentChar = 'a';
    
    private char getNextChar() {
        return currentChar++;
    }
    
    private String transform(String s) {
        currentChar = 'a';
        Map<Character,Character> map = new HashMap<>();
        char[] a = s.toCharArray();
        for(int i = 0; i < a.length; i++) {
            if(!map.containsKey(a[i])) {
                map.put(a[i], getNextChar());
            }
            a[i] = map.get(a[i]);
        }
        
        return new String(a);
    }
    
    public boolean isIsomorphic(String s, String t) {
        return transform(s).equals(transform(t));
    }
}
```

# Problem 2: Rotate List

```
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode tail = head;
        ListNode current = head;
        int length = 0;
        while(current != null) {
            length++;
            tail = current;
            current = current.next;
        }
        if (length == 0) return head;
        int move = k % length;
        int index = length - move;
        int i = 1;
        current = head;
        while(i < index) {
            current = current.next;
            i++;
        }
        tail.next = head;
        ListNode newHead = current.next;
        current.next = null;
        
        return newHead;
    }
}
```

# Problem 4: Trapping Rain Water

```
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] maxLeft = new int[n];
        int[] maxRight = new int[n];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = Math.max(maxLeft[i-1], height[i-1]);
        }
        for (int i = n-2; i >= 0; i--) {
            maxRight[i] = Math.max(maxRight[i+1], height[i+1]);
        }
        int result = 0;
        for(int i = 1; i < n-1; i++) {
            result += Math.max(0, Math.min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return result;
    }
}
```

