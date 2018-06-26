## Problem 2

```python
D = {
    "NORTH": "SOUTH",
    "SOUTH": "NORTH",
    "EAST": "WEST",
    "WEST": "EAST"
}

def dirReduc(arr):
    stack = []
    for item in arr:
        if stack:
            last_item = stack[-1]
            if item ==  D[last_item]:
                stack.pop()
                continue
        stack.append(item)
    return stack 
```