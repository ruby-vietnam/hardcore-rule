Problem 1:

https://leetcode.com/problems/intersection-of-two-linked-lists/description/

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        
        int numA = 0, numB = 0;
        ListNode nA = headA, nB = headB, longList = null, shortList = null, commonNode = null;
        while(nA != null){
            numA++;
            nA = nA.next;
        }
        while(nB != null){
            numB++;
            nB = nB.next;
        }

        longList = (numA >= numB ? headA : headB);
        shortList = (numA >= numB ? headB : headA);
        for (int i = 0; i < Math.abs(numA - numB); i++){
            longList = longList.next;
        }
        while(longList != null){
            if (commonNode == null && longList == shortList){
                commonNode = longList;
            }
            if (commonNode != null && longList != shortList)
                return null;
            longList = longList.next;
            shortList = shortList.next;
        }

        return commonNode;
    }
}
```

Problem 2:

https://leetcode.com/problems/simplify-path/description/

```go

// Get from https://github.com/golang-collections/collections/blob/master/stack/stack.go

type (
	Stack struct {
		top *node
		length int
	}
	node struct {
		value interface{}
		prev *node
	}	
)
// Create a new stack
func New() *Stack {
	return &Stack{nil,0}
}
// Return the number of items in the stack
func (this *Stack) Len() int {
	return this.length
}
// View the top item on the stack
func (this *Stack) Peek() interface{} {
	if this.length == 0 {
		return nil
	}
	return this.top.value
}
// Pop the top item of the stack and return it
func (this *Stack) Pop() interface{} {
	if this.length == 0 {
		return nil
	}
	
	n := this.top
	this.top = n.prev
	this.length--
	return n.value
}
// Push a value onto the top of the stack
func (this *Stack) Push(value interface{}) {
	n := &node{value,this.top}
	this.top = n
	this.length++
}

func simplifyPath(path string) string {
    s := New()
    for _, part := range strings.Split(path, "/") {
        if part == "" || part == "." {
            continue
        }
        if part == ".." {
            if s.Len() > 0 {
                s.Pop()
            }
            continue
        }
        s.Push(part)
    }
    
    r := ""
    for s.Len() > 0 {
        r = "/" + s.Pop().(string) + r
    } 
    if len(r) == 0 {
        return "/"
    }
    return r
}
```
