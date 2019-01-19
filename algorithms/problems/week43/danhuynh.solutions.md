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
