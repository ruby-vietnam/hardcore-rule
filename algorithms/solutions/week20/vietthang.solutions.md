# Problem 1

```erlang
plus_one(Input) when is_list(Input) ->
  [H|T] = lists:reverse(Input),
  Result = if H + 1 > 9 -> plus_one([H|T], [], 1);
              T == []   -> plus_one([H + 1], [], 0);
              true      -> plus_one([H|T], [], 0)
  end,
  lists:reverse(Result).

plus_one([_], Result, 1) ->
  Result ++ [0, 1];
plus_one([Last], Result, _) ->
  Result ++ [Last];
plus_one([H|T], Acc, 1) ->
  if (H + 1) > 9 -> plus_one(T, Acc ++ [0], 1);
     true -> plus_one(T, Acc ++ [H + 1], 0)
  end;
plus_one([H|T], Acc, 0) ->
  plus_one(T, Acc ++ [H], 0).
```
