# Problem 1
``` java
class MinStack {

    /** initialize your data structure here. */
    private static class Node {
        int value;
        int min;
        Node next;
        
        public Node(int value, int min, Node next){
            this.value = value;
            this.min = min;
            this.next = next;
        }
    }
    
    Node head;
    
    public MinStack() {
         
    }
    
    public void push(int x) {
        if (head == null){
            head = new Node(x, x, null);
        }else {
            head = new Node(x, Math.min(x, head.min), head);
        }
    }
    
    public void pop() {
        if (head != null){
            head = head.next;
        }  
    }
    
    public int top() {
        return head.value;
    }
    
    public int getMin() {
        return head.min;
    }
}
```

# Problem 2
``` java
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        int len = s.length();
        
        if (len == 0){
            return result;
        }
        
        for (int i = 1; i < 4; i++){
            if ( i > len){
                break;
            }
            
           int lenRemind = len - i; 
            if (lenRemind > 9){
                continue;
            } 
            
            String first = s.substring(0, i);
            if (!isValidNum(first)){
                continue;
            }
            
            for (int j =  1 ; j < 4 ; j++){
                if (i + j > len){
                    break;
                }
                
                lenRemind = len - i - j; 
                if (lenRemind > 6 || lenRemind < 2){
                    continue;
                }
                
                String second = s.substring(i, i + j);
                if (!isValidNum(second)){
                    continue;
                }
                
                for (int k =  1 ; k < 4; k++){
                    if (i + j  + k > len){
                        break;
                    }
                    
                    lenRemind = len - i - j - k;  
                    if (lenRemind > 3 || lenRemind < 1){
                        continue;
                    } 
                    
                    String third = s.substring(i + j, i + j + k);
                     if (!isValidNum(third)){
                         continue;
                    }
                    
                    String four = s.substring(i + j + k,len);
                    if (!isValidNum(four)){
                         continue;
                    }
                    
                    String ip = first + "." + second +"." + third  +"." +  four;
                    result.add(ip);
                }
            }
        }
        return result;
    }
    
    private boolean isValidNum(String num){
        if (num.length() == 1){
            return true;
        }
        
        int n = Integer.valueOf(num);
        return n <= 255 && !num.substring(0,1).equals("0"); 
    }
}

```
