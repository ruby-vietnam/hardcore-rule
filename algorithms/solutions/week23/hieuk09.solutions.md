## Problem 1

```js
var getIntersectionNode = function(headA, headB) {
  var iter = headA;
  var check = {};

  while (iter) {
    check[iter.val] = 1;
    iter = iter.next;
  }

  iter = headB;

  while (iter) {
    if (check[iter.val] == 1) {
      return iter;
    }

    iter = iter.next;
  }

  return null;
};
```

## Problem 2

```
def simplify_path(path)
  folders = path.split('/')
  result = []

  folders.each do |folder|
    if folder == '' || folder == '.'
      next
    elsif folder == '..'
      result.pop
    else
      result.push(folder)
    end
  end

  if result.empty?
    '/'
  else
    ([''] + result).join('/')
  end
end
```
