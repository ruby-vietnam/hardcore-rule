# 1. Valid Anagram

https://leetcode.com/problems/valid-anagram/

## 1.1. Summary

- If 2 strings have different length, return false
- Use an object to store all character appearances
  - For every char in first string: plus one character
  - For every char in second string: minus one character
- The end result, the values should all be 0 (balanced)

## 1.2. Code

```js
const isAnagram = function (s, t) {
  if (s.length !== t.length) return false;

  const balanceMap = {};

  for (let i = 0; i < s.length; i++) {
    balanceMap[s[i]] = (balanceMap[s[i]] || 0) + 1;
    balanceMap[t[i]] = (balanceMap[t[i]] || 0) - 1;
  }

  return Object.values(balanceMap).every((val) => !val);
};
```

# 2. First Unique Character in a String

https://leetcode.com/problems/first-unique-character-in-a-string/

## 2.1. Summary

- Use an object to store all the char appearances
- Return the first char with only 1 apprearance

## 2.2. Code

```js
const firstUniqChar = function (s) {
  const timeAppearMap = {};

  for (let i = 0; i < s.length; i++) {
    timeAppearMap[s.charAt(i)] = (timeAppearMap[s.charAt(i)] || 0) + 1;
  }

  for (let i = 0; i < s.length; i++) {
    if (timeAppearMap[s.charAt(i)] === 1) return i;
  }

  return -1;
};
```

# 3.

## 3.1. Summary

## 3.2. Code

# 4. Making File Names Unique

https://leetcode.com/problems/making-file-names-unique/

## 4.1. Summary

- Use a store to keep all saved names
- For each name check if it exists, add an index to it

## 4.2. Code

```js
const getFolderNames = function (names) {
  const store = {};

  names.forEach((name) => {
    if (name in store) {
      let index = 1;
      let newName = `${name}(${index})`;
      while (newName in store) {
        index++;
        newName = `${name}(${index})`;
      }
      store[newName] = true;
    } else {
      store[name] = true;
    }
  });

  return Object.keys(store);
};
```
