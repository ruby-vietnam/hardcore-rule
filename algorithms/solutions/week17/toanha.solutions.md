# Problem 1

Approach 1 O((n-1)^2)

```golang
func isIsomorphic(s string, t string) bool {
    for i:=0; i<len(s)-1; i++{
        for j:=i+1; j<len(s); j++{
            if s[i] == s[j] {
                if t[i] == t[j] {
                    continue
                } else {
                    return false
                }
            } else {
                if t[i] == t[j] {
                    return false
                } else {
                    continue
                }
            }
        }
    }

    return true
}
```

Approach 2 O(n)

```golang
func isIsomorphic(s string, t string) bool {
    var charArrayS = [256]byte{}
    var charArrayT = [256]byte{}

    for i:=0; i<len(s); i++ {
        if charArrayS[s[i]] != 0 || charArrayT[t[i]] != 0 {
            if charArrayS[s[i]] != t[i] || charArrayT[t[i]] != s[i] {
                return false
            }
        } else {
            charArrayS[s[i]] = t[i]
            charArrayT[t[i]] = s[i]
        }
    }
    return true
}
```

# Problem 2

```golang
func getTailAndLength(head *ListNode) (tail *ListNode, length int) {
    for head != nil {
        length++
        tail = head
        head = head.Next
    }

    return
}

func getNodeAt(head *ListNode, k int) (node *ListNode, pre *ListNode) {
    var count int
    node = head

    for count < k {
        count++
        pre = node
        node = node.Next
    }

    return
}

func rotateRight(head *ListNode, k int) *ListNode {
    tail, l := getTailAndLength(head)

    if l < 2 {
        return head
    }

    k = k % l // I failed in case k > l :(

    if k == 0 {
        return head
    }

    node, pre := getNodeAt(head, l - k)
    tail.Next = head
    pre.Next = nil

    return node
}
```


# Problem bonus

```golang
func trap(height []int) int {
    var sum, left, maxLeft, maxRight int
    var right = len(height) - 1

    for left < right {
        if height[left] > height[right] {
            if height[right] > maxRight {
                maxRight = height[right]
            } else {
                sum += maxRight - height[right]
            }
            right--
        } else {
            if height[left] > maxLeft {
                maxLeft = height[left]
            } else {
                sum += maxLeft - height[left]
            }
            left++
        }
    }
    return sum
}
```
