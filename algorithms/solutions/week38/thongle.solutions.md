## Problem 4 - [Basic Calculator](https://leetcode.com/problems/basic-calculator/description/)

```python
def solution(s):
    import string

    is_digit = lambda x: x in string.digits
    is_integer = lambda x: type(x) == int
    is_operator = lambda x: x in '+-'
    val = lambda op, x: x if op == '+' else -x

    s = s.replace(' ', '')

    stack = []

    for i in s:
        if stack.__len__() == 0:
            stack.append(int(i) if is_digit(i) else i)
        else:
            if is_operator(i):
                if is_integer(stack[-1]):
                    if stack.__len__() <= 2:
                        stack.append(i)
                        continue

                    if is_integer(stack[-3]):
                        tmp = stack.pop()
                        operator = stack.pop()
                        stack[-1] += val(operator, tmp)
                        stack.append(i)
                    else:
                        stack.append(i)

                elif stack[-1] is '(':
                    stack.append(i)

                elif stack[-1] == '-' and i == '-':
                    stack[-1] = '+'

            elif is_digit(i):
                if is_integer(stack[-1]):
                    stack[-1] = stack[-1] * 10 + int(i)

                elif stack[-1] == '(':
                    stack.append(int(i))

                elif stack.__len__() > 1:
                    if is_integer(stack[-2]):
                        if is_operator(stack[-1]):
                            stack.append(int(i))
                    elif stack[-2] == '(':
                        if is_operator(stack[-1]):
                            stack[-1] = int(i)

            elif i == '(':
                stack.append('(')

            elif i == ')':
                if stack[-2] == '(':
                    stack[-1] = stack.pop()
                elif is_operator(stack[-2]):
                    tmp = stack.pop()
                    operator = stack.pop()
                    stack[-1] += val(operator, tmp)
                    if stack[-2] == '(':
                        stack[-1] = stack.pop()

    if stack.__len__() == 1:
        return stack[0]

    return stack[0] + val(stack[1], stack[2])
```
