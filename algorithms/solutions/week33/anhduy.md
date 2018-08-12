# 876

```go
func middleNode(head *ListNode) *ListNode {
	var mid *ListNode
	mid = head
	for head.Next != nil {
		mid = mid.Next
		head = head.Next
		if head.Next != nil {
			head = head.Next
		}
	}
	return mid
}
```

# Problem 2

```ruby
def SJF(jobs, index)
  sum = 0
  i = 0
  while i < jobs.length do
    if i != index 
      if jobs[i] < jobs[index]
        sum += jobs[i]        
      end
      if jobs[i] == jobs[index] && i < index
        sum += jobs[i]        
      end
    end
    i += 1
  end
  sum += jobs[index]
  sum
end
```

# Problem 4

```ruby
def dbl_linear(n)
    first_linear = [1]
    second_linear = []
    count = 0
    while count < n do
      count += 1
      num = get_smaller(first_linear, second_linear)
      first_linear.push(num * 2 + 1)
      second_linear.push(num * 3 + 1)
    end
    get_smaller(first_linear, second_linear)
end

def get_smaller(first_linear, second_linear)
  x = first_linear[0] || 1000000000
  y = second_linear[0] || 1000000000
  z = [x,y].min
  if z == x
    first_linear.shift
  end
  if z ==y
    second_linear.shift
  end
  z
end
```
