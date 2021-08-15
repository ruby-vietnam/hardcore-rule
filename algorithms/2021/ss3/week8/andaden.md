# 1. Valid Anagram

https://leetcode.com/problems/valid-anagram

## 1.1. Summary

- If their length is different, they won't be anagram.
- Sort the array then compare one by one.

## 1.2. Code

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
  if (s.length !== t.length) return false;
  const s1 = s.split("").sort();
  const s2 = t.split("").sort();
  return s1.every((el, idx) => el === s2[idx]);
};
```

# 2. First Unique Character in a String

https://leetcode.com/problems/first-unique-character-in-a-string/

## 2.1. Summary

- Use hashmap to store the character as key and the letter count as value.
- Loop through string `s` and set the count of each leter.
- Loop through string `s` again, and return the first character which has counter = 1

## 2.2. Code

```js
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
  const map = new Map();
  const N = s.length;
  for (let i = 0; i < N; i++) {
    map.set(s[i], (map.get(s[i]) || 0) + 1);
  }
  for (let i = 0; i < N; i++) {
    if (map.get(s[i]) === 1) return i;
  }
  return -1;
};
```

# 3. LRU Cache

https://leetcode.com/problems/lru-cache/

## 3.1. Summary

- User a hashmap to store the data and it's keys as the list of recent used keys.
- On get: Delete and set key again to push the key to the end of the keys list.
- On put: If the key is new and the number of keys reaches the capacity, the evicted key is the first key of the list.

## 3.2. Code

```js
/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
  this.capacity = capacity;
  this.data = new Map();
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
  if (!this.data.has(key)) return -1;
  const value = this.data.get(key);
  this.data.delete(key);
  this.data.set(key, value);
  return value;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
  if (this.data.has(key)) {
    this.data.delete(key);
    this.data.set(key, value);
    return;
  }
  if (this.data.size == this.capacity) {
    const evictedKey = this.data.keys().next().value;
    this.data.delete(evictedKey);
  }
  this.data.set(key, value);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```
