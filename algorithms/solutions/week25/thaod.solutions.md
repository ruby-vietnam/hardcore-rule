## Problem 1

```javascript
const testRows = ([row1, row2, row3]) =>
  (row1 && !row2 && !row3)
  || (!row1 && row2 && !row3)
  || (!row1 && !row2 && row3);

const testWord = testRowFns => word => testRows(testRowFns.map(fn => fn(word)));

const findWords = words => {
  const testRowFns = [
    /[qwertyuiop]/gi,
    /[asdfghjkl]/gi,
    /[zxcvbnm]/gi,
  ].map(r => w => {
    r.lastIndex = 0;
    return r.test(w);
  });

  return words.filter(testWord(testRowFns));
};
```
