# Easy
> https://leetcode.com/problems/palindrome-linked-list/

### Solution using Stack (Time: O(N), Space: O(N))
Idea:
1. Traverse the list and push every node to the stack.
2. Traverse the list again, get the pop node from stack and compare the value with the visited node.
3. If all nodes matched return true, else false.

```swift
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */

class Solution {
    func isPalindrome(_ head: ListNode?) -> Bool {
			var head = head
			var stack = [Int]()
			var slow = head

			// 1
			while slow != nil {
				stack.append(slow?.val ?? 0)
				slow = slow?.next
			}

			// 2
			while head != nil {
				let value = stack.popLast() ?? 0
				if head?.val != value {
					// 3
					return false
				}
				head = head?.next
			}
			return true
		}
}
```
```
Runtime: 920 ms, faster than 44.04% of Swift online submissions for Palindrome Linked List.
Memory Usage: 31.6 MB, less than 42.24% of Swift online submissions for Palindrome Linked List.
```

### Follow up: Solution with O(N) time and O(1) space

1. Use fast & slow pointers to find middle of the LinkedList first.
   - Because fast pointer is always twice the nodes ahead of the slow pointer. When the fast pointer reaches the end of the LinkedList, the slow pointer will be pointing at the middle node.
2. Once we have the middle of the LL, we will reverse the second half.
3. Then, compare the first half with the reverse second half. If all nodes matched return true, else false.

```swift
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */

class Solution {
    func isPalindrome(_ head: ListNode?) -> Bool {
        var head = head
        var slow = head
        var fast = head

        // 1
        while fast != nil && fast?.next != nil {
            slow = slow?.next
            fast = fast?.next?.next
        }

        // 2
        var headSecondHalf = reverse(slow)
        let copyHeadSecondHalf = headSecondHalf

        // 3
        while head != nil && headSecondHalf != nil {
            if head?.val != headSecondHalf?.val {
                return false
            }
            head = head?.next
            headSecondHalf = headSecondHalf?.next
        }

        return true
    }

    private func reverse(_ head: ListNode?) -> ListNode? {
        var prev: ListNode?
        var head = head
        while head != nil {
            let next = head?.next
            head?.next = prev
            prev = head
            head = next
        }
        return prev
    }
}
```
```
Runtime: 924 ms, faster than 42.60% of Swift online submissions for Palindrome Linked List.
Memory Usage: 26 MB, less than 80.51% of Swift online submissions for Palindrome Linked List.
```

# Medium

> https://leetcode.com/problems/permutations/submissions/

### Time O(N * N!), Space O(N * N!)

Base on Subsets pattern, but must contain all the numbers
1. We will take all existing permutations and add the current number to create new permutations
2. Create a new permutation by adding the current number at every position

```cpp
#include <iostream>
#include <vector>
#include <queue>
// I wish that Swift has a built-in `Queue` library

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    queue<vector<int>> permutations;
    permutations.push(vector<int>());

    for (auto num : nums) {
      // 1
      int n = permutations.size();

      for (int i = 0; i < n; ++i) {
        vector<int> oldPermutation = permutations.front();
        permutations.pop();

        // 2
        for (int j = 0; j <= oldPermutation.size(); ++j) {
          vector<int> newPermutation(oldPermutation);
          newPermutation.insert(newPermutation.begin() + j, num);
          if (newPermutation.size() == nums.size()) {
            result.push_back(newPermutation);
          } else {
            permutations.push(newPermutation);
          }
        }
      }
    }

    return result;
  }
};
```
```
Runtime: 4 ms, faster than 71.38% of C++ online submissions for Permutations.
Memory Usage: 8.1 MB, less than 23.33% of C++ online submissions for Permutations.
```

3. Hard
> https://leetcode.com/problems/palindrome-pairs/

### Time O(NL^2), Space O(NL + L^2)

Writing: WIP

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    int lo = words.size();
    vector<vector<int>> result;

    unordered_map<string, int> map;

    for (int i = 0; i < lo; ++i) {
      string hi = words[i];
      reverse(hi.begin(), hi.end());
      map[hi] = i;
    }

    for (int i = 0; i < lo; ++i) {
      // empty string case
      if (map.find("") != map.end() && map[""] != i && isPalindrome(words[i])) {
        result.push_back({i, map[""]});
      }

      for (int j = 1; j <= words[i].size(); ++j) {
        string left = words[i].substr(0, j);
        string right = words[i].substr(j, words[i].size() - 1);

        // Special case
        // Example: "llsss", "sll"
        // When j = 2, left = "lls", and right = "ss"; m["lls"] is exist,
        // so if right is palindrome, the pair is palindrome
        if (map.find(left) != map.end() && map[left] != i &&
            isPalindrome(right)) {
          result.push_back({i, map[left]});
        }

        // Example: "lls", "sssll"
        // When j = 2, left = "ss", and right = "sll"; m["lls"] is exist,
        // if right is palindrome, the pair is palindrome
        if (map.find(right) != map.end() && map[right] != i &&
            isPalindrome(left)) {
          result.push_back({map[right], i});
        }
      }
    }

    return result;
  }

private:
  bool isPalindrome(string s) {
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
      if (s[lo++] != s[hi--]) {
        return false;
      }
    }
    return true;
  }
};
```
```
Runtime: 228 ms, faster than 53.17% of C++ online submissions for Palindrome Pairs.
Memory Usage: 54.1 MB, less than 64.46% of C++ online submissions for Palindrome Pairs.
```