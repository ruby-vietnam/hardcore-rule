# 1. Implement Stack using Queues
https://leetcode.com/problems/implement-stack-using-queues/

## 1.1. Summary
- We can use double-end queue to push front, pop end
- Push O(n) we need to change order of current elements
- Pop O(1)

## 1.2. Code

``` python
class Deque():
    def __init__(self):
        self._arr = []
            
    def push(self, x):
        self._arr.append(x)
    
    def top(self):
        return self._arr[0]
    
    def pop(self):
        item = self._arr[0]
        self._arr.pop(0)
        return item
        
    def __len__(self):
        return len(self._arr)
            
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """        
        self.queue = Deque()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.push(x)
        size = len(self.queue)
        while size > 1:
            self.queue.push(self.queue.pop())
            size -= 1

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue.pop()
        
    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue.top()        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```

# 2.  Implement Queue using Stacks

https://leetcode.com/problems/implement-queue-using-stacks/

## 2.1. Summary

- Stack is only one direction so we need to 2 stacks for reverse and reverse of reverse
- Push O(n)
- Pop O(1)

## 2.2. Code

```python

class Stack():
    def __init__(self):
        self._arr = []
    
    def push(self, x):
        self._arr.append(x)
    
    def peek(self):
        if self._arr:
            return self._arr[-1]
    
    def pop(self):
        item = self.peek()
        self._arr.pop()
        return item
    
    def size(self, ):
        return len(self._arr)

class MyQueue:

    def __init__(self):
        self.fw_stack = Stack()
        self.bw_stack = Stack()
        

    def push(self, x: int) -> None:
        
        while self.bw_stack.size() > 0:
            self.fw_stack.push(self.bw_stack.pop())
        
        self.fw_stack.push(x)
            
        while self.fw_stack.size() > 0:
            item = self.fw_stack.pop()
            self.bw_stack.push(item)
                    
    def pop(self) -> int:
        return self.bw_stack.pop()
        
    def peek(self) -> int:
        return self.bw_stack.peek()

    def empty(self) -> bool:
        return self.bw_stack.size() == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

```

# 3. Reveal Cards In Increasing Order

https://leetcode.com/problems/reveal-cards-in-increasing-order/

## 3.1. Summary

- Tricky problem: We can think like reverse of operation. Original orders is followed by: pop left element, pop left and push right element. We reverse it: pop element right and push left element, push left element

- Example
    - Original: [17,13,11,2,3,5,7]
    - Sorted: [17,13,11,7,5,3,2]
    - Given: [13,17]
    - New element is 11. First, we pop right and push left => [17,13]. Push new element => [11,17,13]

## 3.2. Code

```python
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        from collections import deque
        
        sorted_deck = sorted(deck, reverse=True)
        
        res = deque()
        
        res.append(sorted_deck[0])
        
        for i in range(1,len(deck)):
            item = res.pop()
            
            res.appendleft(item)
            res.appendleft(sorted_deck[i])
        
        return res                    
```

# 4. Design circular queue

https://leetcode.com/problems/design-circular-queue/

## 4.1. Summary

- We use two points for navigating where head and tail is
- Every time we push new element, we increase tail in round-robin style
- Every time we pop element, we increase head in round-robin style

## 4.2. Code

```python
class MyCircularQueue:

    def __init__(self, k: int):
        self._arr = [-1] * k
        self.head = 0
        self.tail = -1
        self.size = 0
        self.limit = k
        

    def enQueue(self, value: int) -> bool:
        if self.size == self.limit:
            return False
        
        self.tail = (self.tail + 1) % self.limit
        
        self._arr[self.tail] = value
        self.size += 1
        
        return True

    def deQueue(self) -> bool:
        if self.size == 0:
            return False
        
        self.head = (self.head + 1) % self.limit
        self.size -= 1
        return True
        
    def Front(self) -> int:
        if self.size == 0:
            return -1
        
        return self._arr[self.head]
        
    def Rear(self) -> int:
        if self.size == 0:
            return -1
        
        return self._arr[self.tail]
        
    def isEmpty(self) -> bool:
        return self.size == 0
        
    def isFull(self) -> bool:
        return self.size == self.limit

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
```

# 5. Max Value of Equation

https://leetcode.com/problems/max-value-of-equation/submissions/

## 5.1. Summary

- Brute force => TLE (:cry:)

## 5.2 Code

```python
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        max_ = -1E9
        
        i, j = 0, 1
        
        def dist(a, b):
            xi, yi = a
            xj, yj = b
            
            return yi + yj + abs(xi - xj)
        
        while i < len(points) - 1: 
            # print(i)
            a = points[i]
            
            for j in range(i+1, len(points)):
                b = points[j]
                
                if abs(a[0] - b[0]) > k:
                    break

                # print(a,b)
                max_ = max(max_ , dist(a,b))
                
            i += 1
            
        return max_
        
```