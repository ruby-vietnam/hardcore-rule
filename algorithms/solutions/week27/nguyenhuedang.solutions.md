# Week 27

## Problem 1 - [Subdomain Visit Count] (https://leetcode.com/problems/subdomain-visit-count/)

```javascript
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
const getAllParents = (domain) => domain
  .split('.')
  .reverse()
  .reduce((results, current, index) => [
    ...results,
    index ? [current, results[index - 1]].join('.') : current
  ], []);

var subdomainVisits = function(cpdomains) {
  const hash = {};
  for (const cpdomain of cpdomains) {
    const [time, domain] = cpdomain.split(' ');
    getAllParents(domain).forEach((parent) => {
      hash[parent] = (hash[parent] || 0) + Number(time);
    });
  }
  return Object.keys(hash).map(key => `${hash[key]} ${key}`)
};
```

## Problem 2 - [Directions Reduction] (https://www.codewars.com/kata/directions-reduction)

```javascript
function dirReduc(arr){
  const direction = { NORTH: 1, SOUTH: -1, WEST: 2, EAST: -2 };

  const canReduce = (i, j) => {
    return direction[arr[i]] + direction[arr[j]] === 0;
  }

  let flag = true;
  let reduced = arr.map(_ => false);

  while (flag) {
    flag = false;
    for (let i = 0; i + 1 < arr.length; ++i) {
      if (reduced[i]) { continue; }
      for (let j = i + 1; j < arr.length; ++j) {
        if (!reduced[j]) {
          if (canReduce(i, j)) {
            reduced[i] = true;
            reduced[j] = true;
            flag = true;
          }
          break;
        }
      }
    }
  }

  return arr.filter((_, index) => reduced[index] === false);
}
```

## Problem 4 - [Directions Reduction] (https://www.codewars.com/kata/directions-reduction)

```javascript
function sumOfDivided(lst) {
  let p = 2;
  let flag = true;
  const results = [];
  const dList = lst.slice();
  let sum;
  while (flag) {
    flag = false;
    recorded = false;
    sum = 0;
    for (let i = 0; i < lst.length; ++i) {
      if (Math.abs(dList[i]) > 1) { flag = true; }
      if (dList[i] % p === 0) {
        recorded = true;
        while (dList[i] % p === 0) { dList[i] /= p };
        sum += lst[i];
      }
    }
    if (recorded) { results.push([p, sum]); }
    p++;
  }
  return results;
}

```
