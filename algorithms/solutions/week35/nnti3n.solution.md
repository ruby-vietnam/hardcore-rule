# Problem 2
 ```javascript
/**
 * @param {number} R
 * @param {number} C
 * @param {number} r0
 * @param {number} c0
 * @return {number[][]}
 */
var spiralMatrixIII = function(R, C, r0, c0) {
  let maxstep = R*C;
  let sqr = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  let array = [[r0,c0]];
  let x = r0;
  let y = c0;
  let t = 0;
  let edge = 0;
  let step = 1;
  while (step < maxstep) {
    if (t == 0 || t == 2 ) {
      edge++;
    }
    for (let i= 0; i < edge; i++) {
      x += sqr[t][0];
      y += sqr[t][1];
      if (x >= 0 && x < R && y >= 0 && y < C) {
        array[step] = [x,y]);
        step ++;
      }
    }
    t = (t + 1) %4;
  }
  return array;
};
```
