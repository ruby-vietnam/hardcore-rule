package main

import "fmt"

func inArray(c byte, arr string) bool {
	for i := 0; i < len(arr); i++ {
		if c == arr[i] {
			return true
		}
	}

	return false
}

func validWord(word string, arr string) bool {
	for i := 0; i < len(word); i++ {
		if !inArray(word[i], arr) {
			return false
		}
	}

	return true
}

var qwerty = "qwertyuiopQWERTYUIOP"
var asdf = "asdfghjklASDFGHJKL"
var zxcv = "zxcvbnmZXCVBNM"

func findWords(words []string) []string {
	results := []string{}
	for i := 0; i < len(words); i++ {
		if validWord(words[i], qwerty) || validWord(words[i], asdf) || validWord(words[i], zxcv) {
			results = append(results, words[i])
		}
	}

	return results
}

func main() {
	fmt.Println(findWords([]string{"Alaska", "Dad", "Peace"}))
}
