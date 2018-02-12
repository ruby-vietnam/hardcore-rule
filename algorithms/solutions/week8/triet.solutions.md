#problem 1

```
func longestWord(words []string) string {
	if len(words) == 0 {
		return ""
	}
	max := 0
	choose := ""

	for _, word := range words {
		count := 0
		// loop throught char

		cw := ""
		for _, c := range word {
			cw = cw + string(c)
			// find next word
			found := false
			for _, w := range words {
				if w == cw {
					found = true
					count++
					break
				}
			}
			if !found {
				break
			}
		}

		if cw == word {
			if count > max {
				max = count
				choose = word
			}

			if count == max {
				if choose == "" {
					choose = word
				} else if choose > word {
					choose = word
				}
			}
		}
	}

	return choose
}
```
