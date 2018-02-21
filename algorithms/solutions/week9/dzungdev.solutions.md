Problem 1:

We will use the map to contain the number and the value of appear frequently of that number. Then we loop the the keySet of the Map and check if the map contains value which is current number plus 1. Then we calculate the currentLongest and compare it with answer, if currentLongest greater than answer then answer is currentLongest

For example: [1,3,2,2,5,2,3,7] will have map is below
1 : 1
3: 2
2: 3
5: 1
7: 1

so when we loop through the key of Map [1,3,2,5,7] we can see at the num is 2, map contains num 3 and current is map.get(2) + map.get(3) = 5 is longest so we return 5.

Time complexity is O(n) and space complexity is O(n)

```java
public int findLHS(int[] nums) {
    Map<Integer, Integer> countMap = new HashMap<>();
    
    for (int num: nums) {
      countMap.put(num, countMap.getOrDefault(num, 0) + 1);
    }
    
    int ans = 0;
    for (int num: countMap.keySet()) {
      if (countMap.containsKey(num+1)) {
        int curSubsequence = countMap.get(num) + countMap.get(num+1);
        if (curSubsequence > ans) ans = curSubsequence;
      }
    }
    return ans;
  }
```

Problem 2:
We can use recursion to loop all the nodes and make sum of 2 nodes if there are value, if one of node are null, then it is value 0. If 2 nodes are null, then we just return null.

The time complexity is O(n) as we loop all the nodes, space complexity is O(n) too.


```java
public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return null;
        TreeNode newNode = new TreeNode((t1 == null ? 0 : t1.val) + (t2 == null ? 0 : t2.val));
        newNode.left = mergeTrees(t1 == null ? null : t1.left, t2 == null ? null : t2.left);
        newNode.right = mergeTrees(t1== null ? null : t1.right, t2 == null ? null : t2.right);
        return newNode;
    }
```
