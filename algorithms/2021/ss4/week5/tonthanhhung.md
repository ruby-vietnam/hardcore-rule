## 1. [118] Pascal's Triangle

https://leetcode.com/problems/pascals-triangle/

### 1.1 Approach

- Straightforward, build the pascal triangle from the provided logic

### 1.2 Code

```js
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function (numRows) {
    if (numRows === 0) {
      return [];
    }
    let ret = [[1]];
    for (let i = 1; i < numRows; i++) {
      let row = []
      for (let j = 0; j <= i; j++) {
        row.push((ret[i - 1][j - 1] || 0) + (ret[i - 1][j] || 0))
      }
      ret.push(row)
    }
    return ret
  };
```

## 2.

### 2.1 Approach

### 2.2 Code

```js

```

## 1.

### 1.1 Approach

### 1.2 Code

```js

```

## 1.

### 1.1 Approach

### 1.2 Code

```js

```

