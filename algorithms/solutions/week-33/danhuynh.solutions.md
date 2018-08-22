# Problem 1
```ruby
# @param {ListNode} head
# @return {ListNode}
def middle_node(head)
  fast = head

  while fast.next && fast.next.next
    head = head.next
    fast = fast.next.next
  end

  return head.next if fast.next
  head
end
```

# Problem 2
```ruby
def SJF(jobs, index)
  int_job = jobs[index]
  result = int_job
  jobs.each_with_index do |job, i|
    if job < int_job || job == int_job && i < index
      result += job
    end
  end
  result
end
```
