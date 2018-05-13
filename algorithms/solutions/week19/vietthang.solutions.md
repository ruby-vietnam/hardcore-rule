# Hamming Distance.

```erlang
hamming_distance(X, Y) ->
  BinaryStringValue = integer_to_list(X bxor Y, 2),
  count_difference(BinaryStringValue, 0).

count_difference([], Result) ->
  Result;
count_difference([H | T], Acc) ->
  if [H] == "1" -> count_difference(T, Acc + 1);
     true -> count_difference(T, Acc)
  end.
```
