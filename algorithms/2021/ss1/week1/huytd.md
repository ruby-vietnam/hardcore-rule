# Easy: Palindrome Linked List

Submission Details:
```
85 / 85 test cases passed.
Status: Accepted
Runtime: 164 ms
Memory Usage: 8.9 MB
```

```go
/**
 * Reverse a linked list
 *
 * While iterating the list, remove the connection between
 * the current node and its next node, connect it with the
 * previously visited node.
 *
 * Eventually, when finish connecting the last node, the
 * head of the reversed linked list is the last previously
 * visited node.
 */
func reverseLinkedList(head *ListNode) *ListNode {
  var prev *ListNode
  for head != nil {
    next := head.Next
    head.Next = prev
    prev = head
    head = next
  }
  return prev
}

/**
 * Check if a linked list is palindrome using O(1) space
 *
 * First, use slow/fast pointer technique to find the middle
 * of the linked list.
 *
 * Now split the linked list in two halves, one from the
 * middle will be reversed, so the two list should be identical
 * if they're a palindrome. One of the two lists might be longer
 * than the other, but it should only longer by 1 node, and we
 * can ignore the extra node.
 */
func isPalindromeLinkedList(root *ListNode) bool {
  slow := root
  fast := root
  for fast.Next != nil && fast.Next.Next != nil {
    slow = slow.Next
    fast = fast.Next.Next
  }

  first := root
  second := reverseLinkedList(slow)

  for first != nil && second != nil {
    if first.Val != second.Val {
      return false
    }
    first = first.Next
    second = second.Next
  }
  return true
}
```

# Medium: Permutation
https://leetcode.com/problems/permutations/

Submission Details:
```
25 / 25 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 7.7 MB
```

For this problem, we'll use backtracking to slowly build every possible permutation from each of the element in the initial array.

Whenever we pick a number to put it into the list (the `swap`), we spin off a new branch, and increase the current processing position (the `l` variable). When we're done with a branch (fully constructed a permutation), we track back to see if there is any alternative combination (the second `swap`).
 
For example, we start build the set from [1], then pick up either 2 or 3 for the next element, so we have [1,2] and [1,3], after this, we continue to have [1,2,3] and [1,3,2]. When we reach the end, we track back to see if there's any other option. In this example, the other option would be, pick either 2 or 3 as the initial value of the set, so we have [2], and [3], then continue to have [2,1], [2,3] and [3,1], [3,2]. Next level, pickup next element for each of the four pairs here: [2,1,3], [2,3,1] and [3,1,2], [3,2,1].

```
                        [ ]
         ________________|________________
        /                |                \
       [1]              [2]              [3]
       / \              / \              / \
   [1,2] [1,3]      [2,1] [2,3]      [3,1] [3,2]
     |     |          |     |          |     |
 [1,2,3] [1,3,2]  [2,1,3] [2,3,1]  [3,1,2] [3,2,1]   
```

Implementation:

```cpp
class Solution {
    public:
    void gen(vector<vector<int>>* ret, vector<int> s, int l, int r) {
        if (l == r) {
            ret->push_back(s);
        } else {
            for (int i = l; i <= r; i++) {
                swap(s[l], s[i]);
                gen(ret, s, l+1, r);
                swap(s[l], s[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret = {};
        gen(&ret, nums, 0, nums.size()-1);
        return ret;
    }
};
```

# Hard: Palindrome Pairs
https://leetcode.com/problems/palindrome-pairs/

Submission details:

```
134 / 134 test cases passed.
Status: Accepted
Runtime: 1012 ms
Memory Usage: 199.6 MB
```

The first approach is a bruteforce one, we run a nested for loop
to match every pair of words and check if the pair is palindrome
or not, this solution is a TLE one, but it's a good start:

```cpp
int i = 0; j = 0;
vector<vector<int>> ret = {};

for (auto a : words) {
  j = 0;
  for (auto b : words) {
    string s = a + b;
    if (isPalindrome(s)) {
      ret.push_back({ i, j });
    }
    j++;
  }
  i++;
}
```

Assuming the max length of a word is k, this solution has the
time complexity `of O(n^2 * k)`.

See that when we combine the two strings A and B:

```
S = A + B
```

If S is a palindrome, then the two halves of S must matched in
reversed order.

Let's find some connection between B and A here.

What if we could split the string A into two parts, one of
which has the same length as B?

```
S = A_LEFT + A_RIGHT + B
```

If S is a palindrome, then the range of `[A_LEFT : A_RIGHT / 2]` must
be the same as the reverse of `[A_RIGHT / 2 : B]`. In other words:

1. A_LEFT must be the same as the reverse of B
2. The two halves of A_RIGHT must matched in reversed order, or
   A_RIGHT must be a palindrome.

So, this will be the algorithm for the second approach.

1. First, build a hashmap of reversed words, from `words`, to keep track of the corresponding reversed word for each word.
2. Now, for each word `A` in `words` list, try to break it into the form of `A_left + A_right`
3. Check with the hashmap to see if there's any matching word with either `A_left` or `A_right`, if we found it, we can record it to the result list.

There will be a special case for empty string in the words list, if we see the empty string, we can just match it with whatever words we found.

```cpp
class Solution {
    public:
    bool isPalindrome(string s) {
        int len = s.length();
        for (int i = 0, j = len-1; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret = {};
        map<string, int> revhash;
        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            revhash[rev] = i + 1;
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (word == "") {
                for (int j = 0; j < words.size(); j++) {
                    if (i != j && isPalindrome(words[j])) {
                        ret.push_back({ j, i });
                    }
                }
            } else {
                for (int j = 1; j <= word.length(); j++) {
                    string left = word.substr(0, j);
                    string right = word.substr(j);

                    if (revhash[left] != 0 && isPalindrome(right)) {
                        int j = revhash[left] - 1;
                        if (i != j) {
                            ret.push_back({ i, j });
                        }
                    }

                    if (revhash[right] != 0 && isPalindrome(left)) {
                        int j = revhash[right] - 1;
                        if (i != j) {
                            ret.push_back({ j, i });
                        }
                    }
                }
            }
        }
        return ret;
    }
};
```
