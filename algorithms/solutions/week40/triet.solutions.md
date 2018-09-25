### Problem 1

```go
func merge(nums1 []int, m int, nums2 []int, n int) {
	i := m - 1
	j := n - 1
	k := m + n - 1

	for i >= 0 || j >= 0 {
		if j < 0 {
			break
		}

		if i < 0 {
			nums1[k] = nums2[j]
			j--
			k--
			continue
		}

		if nums1[i] < nums2[j] {
			nums1[k] = nums2[j]
			j--
		} else {
			nums1[k] = nums1[i]
			i--
		}

		k--
	}
}
```

### Problem 2
```ruby
# @param {Integer} n
# @return {Integer}
def num_squares(n)
  @min = -1
  square_root(n, 0) 
  @min
end

def square_root(n, count)
  if n == 1 || n == 0 # 1,0
    
    @min = n + count if @min > n + count || @min == -1
    return n+count
  end
  
  rounded_root = Math.sqrt(n).to_i # round
  res = rounded_root.downto(1).map do |r|
    nr = n
    nc = count
    while nr - r**2 >= 0 do
      nr = nr - r**2
      nc +=1
    end
    
    if @min == -1 || nc < @min
      square_root(nr, nc)
    else
      nc
    end
  end
  
  return res.min
end
```


### Problem 3
```go
func longestPalindrome(s string) string {
    longestS := ""
    for i, _ := range s {
        l, r := i, i
        for (l - 1 >= 0) && (s[l - 1] == s[l]) {
            l--
        }
        for (r + 1 < len(s)) && (s[r +1] == s[r]) {
            r++
        }
        
        for (l - 1>= 0) && (r+1 < len(s)) {
            if s[l-1] == s[r+1] {
               
                l--
                r++    
            } else {
                break
            }
        }
        
        if len(s[l:r+1]) > len(longestS) {
            longestS = s[l:r+1]
        }
    }
    return longestS
}
```
