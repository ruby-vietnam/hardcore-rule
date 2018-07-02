Problem 1:

https://leetcode.com/problems/non-decreasing-array/description/

```go
func checkPossibility(nums []int) bool {
    if len(nums) < 3 {
        return true
    }
    
    isFirst := false
    for index := 0; index < len(nums); index++ {
        if index >= len(nums) - 1 || nums[index] <= nums[index + 1] {
            continue
        }
        if isFirst {
            return false
        }
        isFirst = true
        if (index < len(nums) - 2 && nums[index] > nums[index + 2]) && 
            (index > 0 && nums[index - 1] > nums[index + 1]) {
            return false
        }
    }
    return true
}
```

Problem 2:

https://leetcode.com/problems/permutations/description/

```go
func permute(nums []int) [][]int {
    return permuteP([][]int{[]int{}}, nums) 
}

func permuteP(current [][]int, rest []int) (result [][]int) {
    if len(rest) == 0 {
        return current
    }
    for cIndex, _ := range current {
        for rIndex, _ := range rest {
            temp := append(current[cIndex], rest[rIndex])
            newRest := append([]int{}, rest[:rIndex]...)
            newRest = append(newRest, rest[rIndex+1:]...)
            result = append(result, permuteP([][]int{temp}, newRest)...)
        }
    }
    
    return result
}
```

Problem 3:

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

```go
public class Codec {
    public String serialize(TreeNode root) {
        return serialize(root, new StringBuilder()).toString();
    }

    private StringBuilder serialize(TreeNode root, StringBuilder stringBuilder) {
        if (root == null) {
            return stringBuilder.append("#####").append("@@@@@");
        }
        stringBuilder.append(root.val).append("@@@@@");
        serialize(root.left, stringBuilder);
        serialize(root.right, stringBuilder);
        return stringBuilder;
    }

    public TreeNode deserialize(String data) {
        return deserialize(new LinkedList<>(Arrays.asList(data.split("@@@@@"))));
    }

    private TreeNode deserialize(LinkedList<String> stack) {
        String cur = stack.pop();
        if (cur.equals("#####")) {
            return null;
        }
        TreeNode treeNode = new TreeNode(Integer.valueOf(cur));
        treeNode.left = deserialize(stack);
        treeNode.right = deserialize(stack);
        return treeNode;
    }
}
```
