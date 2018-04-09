Problem 1:

https://leetcode.com/problems/isomorphic-strings

```go
func isIsomorphic(s string, t string) bool {
    if s == t {
        return true
    }
    if len(s) != len(t) {
        return false
    }
    
    checking := make(map[byte]byte)
    checking2 := make(map[byte]byte)
    for index, _ := range s {
        source := s[index]
        destination := t[index]
        
        checkingDestination, existed := checking[source];
        
        if !existed {
            checking[source] = destination
        } else if existed && destination != checkingDestination {
            return false
        }
        
        checkingSource, existed := checking2[destination];
        if !existed {
            checking2[destination] = source
        } else if existed && source != checkingSource {
            return false
        }
    }
    return true
}
```
