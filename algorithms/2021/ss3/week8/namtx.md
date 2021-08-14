# 242. Valid Anagram

### Approach

Use an array `alphabets` to count the number of occurences of a character in `s`.
For each character in `t`, we decrease the value of this character in `alphabets`. If there is a `alphabets[i]` equals to zero, it would be an invalid anagram.

### Submission

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;

        int[] alphabets = new int[26];

        for (int i = 0; i < s.length(); i++) {
            alphabets[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (alphabets[t.charAt(i) - 'a'] == 0)
                return false;
            alphabets[t.charAt(i) - 'a']--;
        }

        return true;
    }
}
```

### Submission detail

35 / 35 test cases passed.
	Status: Accepted
Runtime: 7 ms
Memory Usage: 40.5 MB

### Analyze

- Time complexity: O(n)
- Space complexity: O(1), as we always use a constant length array.

# 387. First Unique Character in a String

### Approach

Our approach is as the same with above problem.

### Submission

```java
class Solution {
    public int firstUniqChar(String s) {
        int[] alphabets = new int[26];
        
        for (int i = 0; i < s.length(); i++) {
            alphabets[s.charAt(i) - 'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (alphabets[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
}
```

### Submission detail

104 / 104 test cases passed.
	Status: Accepted
Runtime: 12 ms
Memory Usage: 45.6 MB

### Analyze

- Time comlexity: O(n)
- Space complexity: O(1)

# 146. LRU Cache

### Approach

We present the `key` and `value` by wrap them inside a `Node`, we also add the `prev` and `next` nodes, to build a DoublyLinkedList:

```java
class Node {
    int key;
    int value;
    Node prev;
    Node next;

    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}
```

We use a HashMap<Integer, Node> to keep the reference.

So, we can archive O(1) for `get` operation, and O(1) for `put` as HashMap, and also O(1) for remove and add a Node to LinkedList.

### Submission

```java
class LRUCache {
    HashMap<Integer, Node> map;
    int capacity, count;
    Node head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;

        count = 0;
    }

    public void deleteNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public void addToHead(Node node) {
        node.next = head.next;
        node.next.prev = node;
        node.prev = head;
        head.next = node;
    }

    public int get(int key) {
        if (!map.containsKey(key))
            return -1;

        Node node = map.get(key);
        deleteNode(node);
        addToHead(node);

        return node.value;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value = value;

            deleteNode(node);
            addToHead(node);
        } else {
            Node node = new Node(key, value);
            map.put(key, node);
            if (count < capacity) { // not full yet
                addToHead(node);
                count++;
            } else {
                map.remove(tail.prev.key);
                deleteNode(tail.prev);
                addToHead(node);
            }
        }
    }
}

class Node {
    int key;
    int value;
    Node prev;
    Node next;

    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```

### Submission detail

21 / 21 test cases passed.
	Status: Accepted
Runtime: 172 ms
Memory Usage: 171.1 MB

### Analyze

- Space comlexity: O(n)
- Time comlexity: O(1)
