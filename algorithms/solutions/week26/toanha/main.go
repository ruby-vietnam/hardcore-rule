package main

func main() {
	// fmt.Println(findTheDifference("abc", "abcd"))

	var root = &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val: 2,
		},
		Right: &TreeNode{
			Val: 3,
			Left: &TreeNode{
				Val: 4,
			},
		},
	}

	levelOrder(root)
}
