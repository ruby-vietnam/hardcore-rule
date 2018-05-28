package main

import (
	"strings"
)

func simplifyPath(path string) string {
	var dirs = strings.Split(path, "/")
	var l = len(dirs)
	for i := 0; i < l; i++ {
		if dirs[i] == "." || dirs[i] == "" {
			dirs = append(dirs[:i], dirs[i+1:]...)
			i--
			l--
		} else {
			if dirs[i] == ".." {
				if i > 0 {
					dirs = append(dirs[:i-1], dirs[i+1:]...)
					i -= 2
					l -= 2
				} else {
					dirs = append(dirs[:i], dirs[i+1:]...)
					i--
					l--
				}
			}
		}
	}

	return "/" + strings.Join(dirs, "/")
}
