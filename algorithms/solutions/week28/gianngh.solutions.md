# Problem 1

```javascript
var checkPossibility = function(nums) {
  if (nums.length == 0 || nums.length > 10000) {
    return false;
  }
  if (nums.length == 1) {
    return true;
  }
  return helper(nums);
};

function helper(a) {
  var bool = false;
  var max = Number.MIN_SAFE_INTEGER;
  for (var i = 0; i < a.length; i++) {
    if (i < a.length - 1 && a[i] > a[i + 1]) {
      if (bool) {
        return false;
      }
      bool = true;
      if (a[i + 1] < max) {
        if (a[i] > max) {
          a[i + 1] = a[i];
        } else {
          a[i + 1] = max;
        }
      } else {
        a[i] = a[i + 1] - 1;
      }
    }
    if (a[i] >= max) {
      max = a[i];
    } else if (i < a.length - 1) {
      return false;
    }
  }
  return true;
}
```
