package main

func numSimilarGroups(A []string) int {
	var groupCount = len(A)
	for i := 0; i < len(A); i++ {
		for j := 0; j < i; j++ {
			if isSimilar(A[i], A[j]) {
				groupCount--
			}
		}
	}
	return groupCount
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
