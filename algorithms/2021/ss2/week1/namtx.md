# 997. Find the Town Judge

### Approach

As a naive approach, we create 2 array to track the number of trust and trusted people of one person in town.
For each pair from the input, we will increase the number of trust and trusted.

Finally, we find out the town judge by checking. A judge will have no trust people and trusted by everyone (except him/herself)

### Submission

```java
class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] trusts = new int[n + 1];
        int[] trusted = new int[n + 1];

        for (int[] pair : trust) {
            trusts[pair[0]]++;
            trusted[pair[1]]++;
        }

        for (int i = 1; i < n + 1; i++) {
            if (trusts[i] == 0 && trusted[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
}
```

### Submission detail

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 3ms         | 45.6 MB  | java      |

### Analyze

- Time complexity: O(n)
- Space complexity: O(n)

# 863. All Nodes Distance K in Binary Tree

### Approach

We will examine the example input:

![example](https://user-images.githubusercontent.com/25602820/119230843-1b994100-bb48-11eb-995a-bd2968cb8ab3.png)

Our approach is calculate the distance from the all parent nodes of `target` node and save these values into a map for further calculations. Notice that the distance from the `target` to itself is 0.

After calculated distances we have a map as following:

![map](https://user-images.githubusercontent.com/25602820/119230853-28b63000-bb48-11eb-8307-52b4610d35ad.png)
And finally, we just have to search through all `target` parents and the `target` itself to find appropriate distance.

### Submission

```java
public class Solution {
    Map<TreeNode, Integer> map = new HashMap<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> result = new ArrayList<>();

        findTarget(root, target);
        search(root, target, k, map.get(root), result);

        return result;
    }

    public int findTarget(TreeNode root, TreeNode target) {
        if (root == null)
            return -1;

        if (root == target) {
            map.put(root, 0);
            return 0;
        }

        int left = findTarget(root.left, target);
        if (left >= 0) {
            map.put(root, left + 1);
            return left + 1;
        }

        int right = findTarget(root.right, target);
        if (right >= 0) {
            map.put(root, right + 1);
            return right + 1;
        }

        return -1;
    }

    public void search(TreeNode root, TreeNode target, int k, int distance, List<Integer> result) {
        if (root == null) return;

        if (map.containsKey(root))
            distance = map.get(root);

        if (distance == k)
            result.add(root.val);

        search(root.left, target, k, distance + 1, result);
        search(root.right, target, k, distance + 1, result);
    }
}
```

### Submission detail

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 18ms        | 39.1 MB  | java      |

### Analyze

- Time complexity: O(n)
- Space complexity: O(n)
