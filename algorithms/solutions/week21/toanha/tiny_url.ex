defmodule TinyUrl do
  def encode(long_url) do
    short_url = :os.system_time()
    :ets.insert(:cache, {short_url, long_url})
    short_url
  end

  def decode(short_url) do
    :ets.lookup(:cache, short_url)
    |> List.first()
    |> elem(1)
  end
end

:ets.new(:cache, [:set, :protected, :named_table])

short_url = TinyUrl.encode("sdfdsfdsfdfdsf")
IO.inspect(short_url)
long_url = TinyUrl.decode(short_url)
IO.inspect(long_url)
