## Problem 1

```
/**
 * Time: O(n^2)
 */
const check = (s) => {
  for (let i = 0; i < s.length; i++) {
    for (let j = i + 2; j < s.length - 2; j++) {
      const wi = s[i] + s[i+1];
      const wj = s[j] + s[j+1];

      if ((wi === 'AB' && wj == 'BA') || (wi === 'BA' || wj === 'AB')) {
        return true;
      }
    }
  }

  return false;
};

/**
 * Time: O(n)
 */
const check2 = (s) => {
  let ab = -1;
  let ba = -1;

  for (let i = 0; i < s.length; i++) {
    const w = s[i] + s[i + 1];
    if (w === 'AB') {
      if (ab === -1) {
        ab = i;
      }

      if (ba !== -1 && i !== ba + 1 && i !== ba - 1) {
        return true;
      }
    }
    else if (w === 'BA') {
      if (ba === -1) {
        ba = i;
      }

      if (ab !== -1 && i !== ab + 1 && i !== ab - 1) {
        return true;
      }
    }
  }

  return false;
};
```
