### Prolem 3 - Possible Bipartition
https://leetcode.com/problems/possible-bipartition/description/

```go

func possibleBipartition(N int, dislikes [][]int) bool {
    e := struct{}{}
    g1 := make(map[int]struct{})
    g2 := make(map[int]struct{})
    
    for _, dislike := range dislikes {
        
        if len(g1) == 0 && len(g2) == 0 {
            g1[dislike[0]] = e
            g2[dislike[1]] = e
        }
        
        d0, d1 := dislike[0], dislike[1]
        
        _, ok1 := g1[d0]
        _, ok2 := g1[d1]
        _, ok3 := g2[d0]
        _, ok4 := g2[d1]
        
        switch {
        case ok1 && ok2 || ok3 && ok4:
            return false
        case ok1:
            g2[d1] = e
        case ok2:
            g2[d0] = e
        case ok3:
            g1[d1] = e
        case ok4:
            g1[d0] = e
        }
        
    }
    return true
}

```
