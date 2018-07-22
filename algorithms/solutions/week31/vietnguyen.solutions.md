## [Problem 1: Two substrings](http://codeforces.com/contest/550/problem/A)

```python 
if __name__ == "__main__":
    s = input()
    # brute force: find AB, then find BA in the rest of the string --> O(N^2)
    # better: find the first AB from the left, the first BA from the right. Then compare index of these two.
    # also need to find the first BA from the left and the first AB from the right. 
    first_AB_index = -1
    first_BA_index = -1
    last_AB_index = -1
    last_BA_index = -1
    
    for i in range(len(s) - 1):
        if s[i:i+2] == 'AB':
            first_AB_index = i
            break

    for i in range(len(s) - 1):
        if s[i:i+2] == "BA":
            first_BA_index = i
            break

    for i in range(len(s)-1,-1,-1):
        if s[i:i+2] == "AB":
            last_AB_index = i
            break

    for i in range(len(s)-1,-1,-1):
        if s[i:i+2] == "BA":
            last_BA_index = i
            break

    if first_AB_index == -1 or first_BA_index == -1:
        print("NO")
        
    elif first_AB_index +2 <= last_BA_index or first_BA_index + 2 <= last_AB_index:
        print("YES")
    else:
        print("NO")

```

## [Problem 2: Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)

```python
  # Definition for a binary tree node.
  # class TreeNode:
  #     def __init__(self, x):
  #         self.val = x
  #         self.left = None
  #         self.right = None

  class Solution:
      
      def maxPathSum(self, root):
          """
          :type root: TreeNode
          :rtype: int
          """
          self.current_max_sum = root.val
          self.helper(root)
          return self.current_max_sum 
        
      # this recursive function finds the max path sum of all the paths that go through `node` and have `node` as the topmost node in the tree. 
      def helper(self, node):
          res = 0 
          if node == None: 
              return 0 
          maxPathSumLeft = self.helper(node.left)
          maxPathSumRight = self.helper(node.right)
          res = max(node.val, node.val + maxPathSumLeft, node.val + maxPathSumRight, node.val + maxPathSumLeft + maxPathSumRight)
          # need to update current_max_sum if found any larger value 
          if res > self.current_max_sum:
              self.current_max_sum = res 
          return max(node.val, node.val + maxPathSumLeft, node.val + maxPathSumRight) 

```

## [Problem 3: Shortest Subarray with Sum at least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)

The following code is my effort to pass Leetcode test cases. It has 3
solutions with gradually increased optimization, but the best one
still can only passed 79/93 test cases...

```python 
class Solution:
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        #  the first approach I can think of is to keep increasing the window size.
        # for each window size, check if its sum is greater than K.
        # when we find the first such window, we stop and return the size of that window
        # since we increase the window size, so this result will be the length of the shortest contiguous subarray with sum at least K 
        # how complex? For window size of i, need to check N - i + 1 windows 
        # worst case: O(N^2)
        # can reduce time a bit by avoiding calculating the sum all the time. 
#         ## --- code --- 
#         L = len(A) 
#         current_window_size = 1 
#         first_window_sum = A[0] 
#         current_window_start_idx = 0 
#         current_window_sum = A[0] 
#         while current_window_size <=L and current_window_sum <K: 
#             #print(current_window_size, current_window_sum,current_window_start_idx)
#             if current_window_start_idx + current_window_size == L: 
#                 current_window_start_idx = 0 
#                 current_window_size += 1 
#                 if current_window_size > L:
#                     break 
#                 current_window_sum = first_window_sum + A[current_window_size-1]
#                 first_window_sum += A[current_window_size-1]
#             else:
#                 current_window_sum = current_window_sum - A[current_window_start_idx] + A[current_window_start_idx + current_window_size]
#                 current_window_start_idx += 1 
            
#         if current_window_size > L:
#             return -1 
#         else:
#             return current_window_size 
#         ## --- end of code --- 
        ## this solution passed 83/93 test cases. The next one has Time Limit Exceeded. 
        
        # try to think of better solution 
        # the difficulty in this problem is that there's negative numbers, that makes a longer subarray not necessarily the one with larger sum 
        # find contiguous positive numbers? does it help 
        # [1,2,3,-1,-2, 4,3,2,-2,4] K = 7
        # the first block of positive numbers is [1,2,3]: it doesn't have any subarray with sum at least K = 7 
        # the second block of positive numbers is [4,3,2]: its sum is 9 > 7, so we can find the shortest subarray in here. 
        # so probably keep track of blocks of positive numbers
        # then check the shortest subarray within only blocks with sum at least K 
        # there is no such block? need to combine blocks, with the negative numbers in between? 
        # probably take sum of negative block too. 
        # Let S be the array of sums of blocks 
        # If S[i] >= 0 and  S[i] + S[i+1] < 0, then we can skip S[i], S[i+1]  
#         S = [] 
#         blocks = [] 
#         L = len(A)
#         block_start = 0 
#         block_end = 0 
#         i = 0 
#         current_sum = 0 
#         while i < L: 
#             current_sum += A[i] 
#             if i+1 == L:
#                 block_end = i 
#                 blocks.append((block_start, block_end))
#                 S.append(current_sum)
#                 current_sum = 0 
#             if i+1 < L and A[i] * A[i+1] < 0: 
#                 block_end = i 
#                 blocks.append((block_start, block_end))
#                 S.append(current_sum)
#                 block_start = block_end = i+1
#                 current_sum = 0 
#             i += 1 
#         #print(S)
#         #print(blocks)
        
#         res = -1 
#         for i in range(len(S)):
#             if S[i] < 0: 
#                 continue 
#             running_sum = 0 
#             for j in range(i, len(S)):
#                 running_sum += S[j]
#                 if running_sum >= K:
#                     current_shortest_array_len = self.find_shortest_array_length(A, blocks[i][0], blocks[j][1], K)
#                     res = current_shortest_array_len if res == -1 else min(res, current_shortest_array_len)
#                     break 
#         return res 
    
#     def find_shortest_array_length(self, A, start_idx, end_idx, K):
#         #print("find_shortest_array_length:", start_idx, end_idx)
#         L = end_idx - start_idx + 1 
#         current_window_size = 1 
#         first_window_sum = A[start_idx] 
#         current_window_start_idx = start_idx 
#         current_window_sum = A[start_idx] 
#         while current_window_size <=L and current_window_sum < K: 
#             #print(current_window_size, current_window_sum,current_window_start_idx)
#             if current_window_start_idx + current_window_size > end_idx: 
#                 current_window_start_idx = start_idx 
#                 current_window_size += 1 
#                 if current_window_size > L:
#                     break 
#                 current_window_sum = first_window_sum + A[start_idx + current_window_size-1]
#                 first_window_sum += A[start_idx + current_window_size-1]
#             else:
#                 current_window_sum = current_window_sum - A[current_window_start_idx] + A[current_window_start_idx + current_window_size]
#                 current_window_start_idx += 1 
            
#         print (current_window_size)
#         if current_window_size > L:
#             return -1 
#         else:
#             return current_window_size   
        
        ## this solution is better, it passed 77/93 test cases. Still Time Limit Exceeded. 
        ## note that if print statement turned on, that counts into the running time as well. So I turned off the print function. 
        # another improvement: if I already called self.find_shortest_array_length(A, blocks[i][0], blocks[j][1], K), that means I checked all the numbers from the start of i-th block to the j-th block. So I should move on to checking from the (j+1)-th block. 
        ## let's copy the second solution with the new improvement: 
        
        S = [] 
        blocks = [] 
        L = len(A)
        block_start = 0 
        block_end = 0 
        i = 0 
        current_sum = 0 
        while i < L: 
            current_sum += A[i] 
            if i+1 == L:
                block_end = i 
                blocks.append((block_start, block_end))
                S.append(current_sum)
                current_sum = 0 
            if i+1 < L and A[i] * A[i+1] < 0: 
                block_end = i 
                blocks.append((block_start, block_end))
                S.append(current_sum)
                block_start = block_end = i+1
                current_sum = 0 
            i += 1 
        #print(S)
        #print(blocks)
        
        res = -1 
        
        covered_j = -1 
        for i in range(len(S)):
            if S[i] < 0: 
                continue 
            running_sum = 0 
            for j in range(i, len(S)):
                running_sum += S[j]
                if running_sum >= K:
                    if j > covered_j: 
                        current_shortest_array_len = self.find_shortest_array_length(A, blocks[i][0], blocks[j][1], K)
                        res = current_shortest_array_len if res == -1 else min(res, current_shortest_array_len)
                        covered_j = j 
                        break
                    else:                  
                        break 
        return res 
    
    def find_shortest_array_length(self, A, start_idx, end_idx, K):
        #print("find_shortest_array_length:", start_idx, end_idx)
        L = end_idx - start_idx + 1 
        current_window_size = 1 
        first_window_sum = A[start_idx] 
        current_window_start_idx = start_idx 
        current_window_sum = A[start_idx] 
        while current_window_size <=L and current_window_sum < K: 
            #print(current_window_size, current_window_sum,current_window_start_idx)
            if current_window_start_idx + current_window_size > end_idx: 
                current_window_start_idx = start_idx 
                current_window_size += 1 
                if current_window_size > L:
                    break 
                current_window_sum = first_window_sum + A[start_idx + current_window_size-1]
                first_window_sum += A[start_idx + current_window_size-1]
            else:
                current_window_sum = current_window_sum - A[current_window_start_idx] + A[current_window_start_idx + current_window_size]
                current_window_start_idx += 1 
            
        #print (current_window_size)
        if current_window_size > L:
            return -1 
        else:
            return current_window_size           
    
    ## this solution still only passes 79/93 test cases. 
```
