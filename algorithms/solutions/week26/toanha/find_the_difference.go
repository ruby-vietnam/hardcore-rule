package main

import "fmt"

func findTheDifference(s string, t string) byte {
	var b byte
	for i := 0; i < len(s); i++ {
		b += t[i] - s[i]
	}
	return b + t[len(t)-1]
}

func main() {
	fmt.Println(findTheDifference("abc", "abcd"))
}
