defmodule MinStack do
  @max_int 2_147_483_647
  defstruct arr: [], min: @max_int

  def push(model = %__MODULE__{min: min}, value) when value > min do
    %{model | arr: [value | model.arr]}
  end

  def push(model = %__MODULE__{min: min}, value) when value <= min do
    %{model | arr: [value | model.arr], min: value}
  end

  def pop(model = %__MODULE__{arr: arr = [h | t]}) when length(arr) >= 2 do
    min = Enum.min(t)
    %{model | arr: t, min: min}
  end

  def pop(model = %__MODULE__{arr: arr}) when length(arr) < 2 do
    %MinStack{}
  end

  def top(model = %__MODULE__{arr: arr}) when length(arr) == 0 do
    0
  end

  def top(model = %__MODULE__{arr: arr = [h | t]}) when length(arr) > 0 do
    h
  end

  def get_min(model = %__MODULE__{arr: arr}) when length(arr) == 0 do
    0
  end

  def get_min(model = %__MODULE__{arr: arr, min: min}) when length(arr) > 0 do
    min
  end
end

defmodule Main do
  def run() do
    stack = %MinStack{}

    stack
    |> MinStack.push(-2)
    |> IO.inspect()
    |> MinStack.push(0)
    |> IO.inspect()
    |> MinStack.push(-3)
    |> IO.inspect()
    |> MinStack.pop()
    |> IO.inspect()
    |> MinStack.top()
    |> IO.inspect()

    # |> MinStack.get_min()
    # |> IO.inspect()
  end
end

Main.run()
