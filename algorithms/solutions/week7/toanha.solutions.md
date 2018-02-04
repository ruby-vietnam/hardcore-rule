## Problem 1

https://leetcode.com/problems/first-unique-character-in-a-string/description/

B1. Khởi tạo 1 mảng ban đầu với mỗi vị trí trong mảng tương ứng 1 kí tự ví dụ 97 -> a.
B2. Duyệt chuổi và tăng kí tự tương ứng trong mảng trên lên 1 để đếm lần xuất hiện của kí tự đó
B3. Duyệt lại mảng 1 lần nữa để xem phần tử đầu tiên xuất hiện ở vị trí nào

```golang
func firstUniqChar(s string) int {
	var arr [256]int
	for i := 0; i < len(s); i++ {
		arr[s[i]] += 1
	}

	for i := 0; i < len(s); i++ {
		if arr[s[i]] == 1 {
			return i
		}
	}

	return -1
}
```

## Problem 2

https://leetcode.com/problems/symmetric-tree/description/

Đệ quy kiểm tra xem có cập left right nào không đối xứng không bằng cách check node phải trái

```golang
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}

	return isSymmetricChilds(root.Left, root.Right)
}

func isSymmetricChilds(left *TreeNode, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}

	if left == nil || right == nil {
		return false
	}

	return (left.Val == right.Val) && isSymmetricChilds(left.Left, right.Right) && isSymmetricChilds(left.Right, right.Left)
}

```
