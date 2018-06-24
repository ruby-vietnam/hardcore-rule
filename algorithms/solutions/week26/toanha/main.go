package main

import "fmt"

func main() {
	// // Problem 1
	// fmt.Println(findTheDifference("abc", "abcd"))

	// // Problem 2
	// var root = &TreeNode{
	// 	Val: 1,
	// 	Left: &TreeNode{
	// 		Val: 2,
	// 	},
	// 	Right: &TreeNode{
	// 		Val: 3,
	// 		Left: &TreeNode{
	// 			Val: 4,
	// 		},
	// 	},
	// }
	// fmt.Println(levelOrder(root))

	// Problem 3
	fmt.Println(numSimilarGroups([]string{"tars", "rats", "arts", "star"}) == 2)
	fmt.Println(numSimilarGroups([]string{"jvhpg", "jhvpg", "hpvgj", "hvpgj", "vhgjp"}) == 3)
	fmt.Println(numSimilarGroups([]string{
		"kccomwcgcs",
		"socgcmcwkc",
		"sgckwcmcoc",
		"coswcmcgkc",
		"cowkccmsgc",
		"cosgmccwkc",
		"sgmkwcccoc",
		"coswmccgkc",
		"kowcccmsgc",
		"kgcomwcccs",
	}) == 5)
	fmt.Println(numSimilarGroups([]string{"blw", "bwl", "wlb"}) == 1)
	fmt.Println(numSimilarGroups([]string{
		"qihcochwmglyiggvsqqfgjjxu",
		"gcgqxiysqfqugmjgwclhjhovi",
		"gjhoggxvcqlcsyifmqgqujwhi",
		"wqoijxciuqlyghcvjhgsqfmgg",
		"qshcoghwmglygqgviiqfjcjxu",
		"jgcxqfqhuyimjglgihvcqsgow",
		"qshcoghwmggylqgviiqfjcjxu",
		"wcoijxqiuqlyghcvjhgsqgmgf",
		"qshcoghwmglyiqgvigqfjcjxu",
		"qgsjggjuiyihlqcxfovchqmwg",
		"wcoijxjiuqlyghcvqhgsqgmgf",
		"sijgumvhqwqioclcggxgyhfjq",
		"lhogcgfqqihjuqsyicxgwmvgj",
		"ijhoggxvcqlcsygfmqgqujwhi",
		"qshcojhwmglyiqgvigqfgcjxu",
		"wcoijxqiuqlyghcvjhgsqfmgg",
		"qshcojhwmglyiggviqqfgcjxu",
		"lhogcgqqfihjuqsyicxgwmvgj",
		"xscjjyfiuglqigmgqwqghcvho",
		"lhggcgfqqihjuqsyicxgwmvoj",
		"lhgocgfqqihjuqsyicxgwmvgj",
		"qihcojhwmglyiggvsqqfgcjxu",
		"ojjycmqshgglwicfqguxvihgq",
		"sijvumghqwqioclcggxgyhfjq",
		"gglhhifwvqgqcoyumcgjjisqx",
	}) == 11)
}
