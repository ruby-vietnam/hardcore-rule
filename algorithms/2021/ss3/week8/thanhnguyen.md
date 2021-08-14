# 3. (Medium) [146. LRU Cache](https://leetcode.com/problems/lru-cache/)
## Approach: Hash table and linked list
- hash table with dict in python for cache
- linked list for add and remove node quickly


### 1.1 Solution
- describe on the code

### 1.2 Code

```
21 / 21 test cases passed.
Status: Accepted
Runtime: 108 ms
Memory Usage: 74.6 MB
```

```python
class Node(object):
    """
    A note have key, value and
    belong to a linked list with the next and prev value
    """
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # the cache with capacity limit
        self.head = None  # head of the linked list
        self.tail = None  # tail of the linked list

    def addNode(self, node):
        if self.head is None:
            # first node, just insert to head
            self.head = node
        else:
            # then current head will become the next of the node
            node.next = self.head
            # then the prev of the current head is the node
            self.head.prev = node
            # node insert to replace the current head
            self.head = node

        # if not have any node yet, the tail is also the node
        if self.tail is None:
            self.tail = node


    def removeNode(self, node):
        # set the prev of the next become prev of the node
        if node.next is not None:
            node.next.prev = node.prev
        # set the next of the prev become the next of the node
        if node.prev is not None:
            node.prev.next = node.next
        # if node is the head then update to new head
        if self.head == node:
            self.head = node.next
        # if node is the tail then update to new tail
        if self.tail == node:
            self.tail = node.prev

        # remove node
        node.next = None
        node.prev = None

    def get(self, key: int) -> int:
        node = self.cache.get(key)

        # if node exist
        if node:
            # remove the current node
            self.removeNode(node)
            # add node become lastest head
            self.addNode(node)
            return node.value

        return -1

    def put(self, key: int, value: int) -> None:
        node = self.cache.get(key)

        if node:
            # have node in the cache
            # go update the cache new value
            node.value = value
            # remove the node in old position
            self.removeNode(node)
            # add the new node to new head
            self.addNode(node)

        else:
            # not have node in the cache

            # find space to add new node
            if self.capacity > 0:
                # check if have capacity, reduce the capacity
                self.capacity -= 1
            else:
                # not have enough capacity, delete the tail to have more space
                # delete from cache
                del self.cache[self.tail.key]
                # remove tail node it on linked list
                self.removeNode(self.tail)

            # add new node
            # create node
            node = Node(key, value)
            # add to cache
            self.cache[key] = node
            # link to the linked list
            self.addNode(node)





# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```