# Problem 1 : Middle of the Linked List

URL: https://leetcode.com/problems/middle-of-the-linked-list/description/


Status:
```
  ✔ Accepted
```
Codes:
```ruby
def middle_node(head)
  fast = head
  while fast = fast&.next do
    fast = fast.next
    head = head.next
  end
  head
end
```

# Problem 2 : Scheduling (Shortest Job First or SJF)

URL: https://www.codewars.com/kata/scheduling-shortest-job-first-or-sjf/ruby


Status:
```
  ✔ Accepted
```
```ruby
def SJF(jobs, index)
  queues = {}
  total_time = 0

  jobs.each_with_index do |e, index|
    queues[index] = e
  end

  queues.sort_by { |k,v| v}.each do |k,v|
    total_time += v
    break if k == index
  end
  total_time
end
```