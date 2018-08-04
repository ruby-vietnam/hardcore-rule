## Problem 1

```ruby
def middle_node(head)
  array = []

  while (head)
    array << head
    head = head.next
  end

  array[array.length / 2]
end
```

## Problem 2

```ruby
 def SJF(jobs, idx)

   job_with_indexes = jobs.each_with_index.map do |job, index|
     [job, index]
   end.sort do |(job_1, index_1), (job_2, index_2)|
     if job_1 == job_2
       index_1 <=> index_2
     else
       job_1 <=> job_2
     end
   end

   sum = 0

   job_with_indexes.each do |job, index|
     sum += job
     break if job == jobs[idx] && idx == index
   end

   sum
 end
```
