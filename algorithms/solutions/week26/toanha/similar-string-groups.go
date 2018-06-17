package main

func numSimilarGroups(A []string) int {
	var similarWords = map[string]string{}

	for i := 0; i < len(A); i++ {
		if _, ok := similarWords[A[i]]; ok {
			continue
		}
		similarWords[A[i]] = A[i]

		for j := 0; j < i; j++ {
			if isSimilar(A[i], A[j]) && similarWords[A[j]] != A[i] {
				root := getPreviousWord(similarWords, A[j])
				similarWords[root] = A[i]
				continue
			}
		}
	}

	var groupCount int
	for k, v := range similarWords {
		if k == v {
			groupCount++
		}
	}
	return groupCount
}

func getPreviousWord(words map[string]string, s string) string {
	if s == words[s] {
		return s
	}
	return getPreviousWord(words, words[s])
}

func isSimilar(a, b string) bool {
	if len(a) != len(b) {
		return false
	}

	var arrA []byte
	var arrB []byte
	var n int
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			n++
			arrA = append(arrA, a[i])
			arrB = append(arrB, b[i])
		}
	}

	return n == 0 || (n == 2 && (arrA[0] == arrB[1]) && (arrA[1] == arrB[0]))
}
