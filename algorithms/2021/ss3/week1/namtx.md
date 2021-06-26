# 766. Toeplitz Matrix

### Approach

Bruteforce FTW!

### Submission

```java
public class Solution {
  public boolean isToeplitzMatrix(int[][] matrix) {
    int r = matrix.length;
    int c = matrix[0].length;
    for (int i = 0; i < r-1; i++) {
        for (int j = 0; j < c-1; j++) {
            if (matrix[i][j] != matrix[i+1][j+1])
                return false;
        }
    }

    return true;
  }
}
```

### Submission detail

483 / 483 test cases passed. Status: Accepted
Runtime: 1 ms

### Analyze

- Time complexity: O(n)
- Space complexity: O(1)

# 49. Group Anagrams

### Approach - Hashing

We use the simple hash function to hash the string, after that, all string have the same hash value are in the same anagram group.
We will create a 26-length array of primes:

```java
int [] primes = new int[] {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 67, 71, 83, 89, 101, 107, 109, 113, 127
        };
```

For each character in a string, it has a prime number corresponding, and we multiply all together.

### Submission

```java
public List<List<String>> groupAnagrams(String[] strs) {
  int [] primes = new int[] {
      2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 67, 71, 83, 89, 101, 107, 109, 113, 127
  };
  HashMap<Long, ArrayList<String>> h = new HashMap<>();
  for (String str : strs) {
      long val = 1;
      for (char c : str.toCharArray()) {
          val *= primes[c - 'a'];
      }
      ArrayList<String> anagrams = h.getOrDefault(val, new ArrayList<>());
      anagrams.add(str);
      h.put(val, anagrams);
  }

  List<List<String>> r = new ArrayList<>();

  for (Long k: h.keySet()) {
      r.add(h.get(k));
  }

  return r;
}
```

### Submission detail

Your runtime beats 99.94% of java submission.

114 / 114 test cases passed. Status: Accepted
Runtime: 4 ms

### Analyze

- Time comlexity: O(nk), with `k` is the length of each string
- Space complexity: O(n)

# 86. Partition List

### Approach

Our approach is very simple.
We traverse the List, and find the first Node which has value greater than `x`, and mark it as `current`. And then, we go next until we see the smaller than `x` Node and mark it as `smaller`, and the tail of `smaller` is `tail`.

The last node that greater or equal than `x` is marked as `greater`.

From here, we just reorder them into a correct order.

![drawing](https://user-images.githubusercontent.com/25602820/123518334-a03f2800-d6cf-11eb-9984-d08aa0c7251b.png)

### Submission

```java
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode current = head;
        ListNode previous = null;

        while (current.next != null) {
            if (current.val < x) {
                previous = current;
                current = current.next;
            } else {
                ListNode greater = current;
                while (greater.next != null && greater.next.val >= x) {
                    greater = greater.next;
                }
                if (greater.next == null)
                    return head;

                ListNode smaller = greater.next;
                ListNode tail = smaller.next;
                if (previous == null) {
                    smaller.next = current;
                    greater.next = tail;
                    previous = smaller;
                    head = previous;
                } else {
                    previous.next = smaller;
                    smaller.next = current;
                    greater.next = tail;
                    previous = smaller;
                }
            }
        }

        return head;
    }
}
```

### Submission detail

Runtime: 0 ms, faster than 100.00% of Java online submissions for Partition List.

168 / 168 test cases passed. Status: Accepted
Runtime: 0 ms

### Submission detail

- Time complexity O(n)
- Space complexity O(1)

