Problem1: https://leetcode.com/problems/isomorphic-strings/

We use the map to contain the source character map to destination character. If the map contains the source character, we need to check the value must be same.
If the map doesn't contain the source character, we need to get the list of current destination and check whether it contains the destination character.

For example: aba and baa are wrong because a map to b and a
             ab and aa are wrong because a and b map to same a
             
Space complexity is O(n) and Time complexity is O(n)

```java
  public boolean isIsomorphic(String s, String t) {
    if (s == null || t == null || s.length() != t.length())
      return false;
    char[] sc = s.toCharArray();
    char[] tc = t.toCharArray();
    Map<Character, Character> map = new HashMap<>();
    for (int i = 0; i < sc.length; i++) {
      if (map.containsKey(sc[i])) {
        if (map.get(sc[i]) != tc[i])
          return false;
      } else {
        if (map.values().contains(tc[i]))
          return false;
        map.put(sc[i], tc[i]);
      }
    }
    return true;
  }
```

Problem2: https://leetcode.com/problems/rotate-list/

We use the concept that the rotate index = length - k % length (I readed in Discusstion).
So the step to do is:
1. Loop through the list to know the length of linked list. We should keep the tail at end of this loop, we call oldTail
2. calculate rotate_index = length - k % length
3. Make the node at rotate_index become new Head
4. Keep the node before rotate_index as it is newTail
5. assign oldTail.next = oldHead
5. newTail.next = null

I run fail some round and then added some edge case like linkedlist has 1 node only, or [ 1 ,2 ] and k = 0

Time complexity is O(n) and space O(1)

```java
public ListNode rotateRight(ListNode head, int k) {
    if (head == null || head.next == null)
      return head;
    ListNode temp = head;
    int l = 0;
    ListNode oldTail = null;
    while (temp != null) {
      l++;
      if (temp.next == null)
        oldTail = temp;
      temp = temp.next;
    }
    int rotateIndex = l - k % l;
    if (rotateIndex == l) return head;//for special case: [1,2] va k = 0
    int i = 0;
    temp = head;
    ListNode prev = null;
    ListNode newTail = null;
    ListNode newHead = null;

    while (temp != null) {
      if (i == rotateIndex) {
        newTail = prev;
        newHead = temp;
        break;
      }
      i++;
      prev = temp;
      temp = temp.next;
    }
    oldTail.next = head;
    newTail.next = null;

    return newHead;
  }
```
