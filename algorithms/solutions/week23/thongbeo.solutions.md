#Problem 1
``` Java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode curA = headA;
        ListNode curB = headB;
        
        while(curA != curB){
            curA  = curA == null ? headB : curA.next;
            curB  = curB == null ? headA : curB.next;
        }
        
        return curA;
    }
}
```

#Problem 2
``` Java
class Solution {
    public String simplifyPath(String path) { 
        String[] strs = path.split("/");
        StringBuilder sb = new StringBuilder();
        for (String str : strs){
            if (str.equals("") || str.equals(".")){
                continue;
            }
            if (str.equals("..")){
                while (sb.length() > 0 && sb.charAt(sb.length() - 1) != '/') {
                        sb.deleteCharAt(sb.length() - 1);
                    }
                    if (sb.length() > 0) {
                        sb.deleteCharAt(sb.length() - 1);
                    }
                continue;
            }
            sb.append("/");
            sb.append(str);
        }
        if (sb.length() == 0){
            return "/";
        }
        return sb.toString();
    }
}
```
