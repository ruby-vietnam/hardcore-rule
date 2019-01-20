# Problem 1
We have two solutions for this problem either we make push operation expensive
or we make pop operation expensive.

```ruby
class MyStack
  def initialize()
    @front_queue = Queue.new
    @back_queue = Queue.new
  end

  # Expensive push O(N)
  # We have to push top to a new queue
  # and push every thing in the current queue
  # to the new queue, and swap the two.
  # This way we can maintain a reverse queue
  # with the last inserted item in front of the queue
  def push(x)
    @back_queue.push(x)

    while !@front_queue.empty?
      @back_queue.push(@front_queue.pop)
    end

    @front_queue, @back_queue = @back_queue, @front_queue
  end

  def pop()
    @front_queue.pop
  end

  def top()
    ret = @front_queue.pop
    self.push(ret)
    ret
  end

  def empty()
    @front_queue.empty?
  end
end
```

```elixir
defmodule MyStack do
  defstruct front_queue: :queue.new(),
            back_queue: :queue.new()

  def push(%MyStack{} = stack, x) do
    Map.update!(stack, :front_queue, &:queue.in(x, &1))
  end

  @doc """
    Expensive pop O(N)
    Dequeue every item exept the rear item out of the front queue
    and queue them in to the back queue.
    Dequeue last item out of front queue and return it.
    The new stack gonna have front queue and back queue swapped.
  """
  def pop(%MyStack{front_queue: f_queue} = stack) do
    {{:value, front}, f_queue} = :queue.out(f_queue)
    pop(Map.put(stack, :front_queue, f_queue), front)
  end

  defp pop(%MyStack{front_queue: f_queue, back_queue: b_queue}, top) do
    case :queue.out(f_queue) do
      {{:value, front}, f_queue} ->
        pop(%MyStack{front_queue: f_queue, back_queue: :queue.in(top, b_queue)}, front)

      {:empty, f_queue} ->
        {top, %MyStack{front_queue: b_queue, back_queue: f_queue}}
    end
  end

  def top(%MyStack{} = stack) do
    {top, stack} = pop(stack)
    {top, push(stack, top)}
  end

  def empty(%MyStack{front_queue: f_queue} = stack) do
    :queue.is_empty(f_queue)
  end
end
```

# Problem 2

This solution used backtracking to try all possible mutation paths and return
the shortest one. The complexity at worse case (no path from start to end)
should be O(N!) which is the number of permutations with genes from bank.

```ruby
def diff_by_one(s1, s2)
  flag = false

  0.upto(7) do |i|
    if s1[i] != s2[i]
      return false if flag
      flag = true
    end
  end

  flag
end

def _min_mutation(start, stop, bank, depth, flag, ret)
  if start == stop
    ret << depth
  end

  0.upto(bank.size - 1) do |i|
    next if flag[i]
    if diff_by_one(start, bank[i])
      flag[i] = true
      _min_mutation(bank[i], stop, bank, depth + 1, flag, ret)
      flag[i] = false
    end
  end
end

# @param {String} start
# @param {String} end
# @param {String[]} bank
# @return {Integer}
def min_mutation(start, stop, bank)
  flag = []
  ret = []
  _min_mutation(start, stop, bank, 0, flag, ret)

  ret.min || -1
end
```

This problem can actually be solved better by imagining the mutation paths
as a graph with each mutation point to other mutations if they differ by one character.
This problem now became the classic problem: Find shortest path from node A to node B.
Which can be solved using BFS with a queue
```elixir
defmodule MySolution do
  def min_mutation(start, stop, bank) do
    _min_mutation(stop, bank, :queue.from_list([{start, 0}]))
  end

  defp _min_mutation(stop, bank, queue) do
    case :queue.out(queue) do
      {{:value, {current_gene, mutations}}, queue} ->
        if current_gene == stop do
          mutations
        else
          {rem, queue} =
            Enum.reduce(bank, {[], queue}, fn gene, {rem, queue} ->
              if diff_by_one(current_gene, gene) do
                {rem, :queue.in({gene, mutations + 1}, queue)}
              else
                {[gene | rem], queue}
              end
            end)

          _min_mutation(stop, rem, queue)
        end

      {:empty, queue} ->
        -1
    end
  end

  defp diff_by_one(s1, s2) do
    diff_by_one(String.graphemes(s1), String.graphemes(s2), 0)
  end

  defp diff_by_one([c1 | tail_1], [c2 | tail_2], diff_count) do
    if c1 != c2 do
      diff_by_one(tail_1, tail_2, diff_count + 1)
    else
      diff_by_one(tail_1, tail_2, diff_count)
    end
  end

  defp diff_by_one([], [], diff_count) do
    diff_count == 1
  end
end
```

# Problem 3

O(1) to calculate sum range
```ruby
class NumArray

  def initialize(nums)
    @sums = nums.empty? ? [] : [nums[0]]
    1.upto(nums.size - 1) do |i|
      @sums[i] = @sums[i - 1] + nums[i]
    end
  end

  def sum_range(i, j)
    @sums[j] - (i.zero? ? 0 : @sums[i - 1])
  end
end
```
