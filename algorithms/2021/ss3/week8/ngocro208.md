# 1. Valid Anagram

https://leetcode.com/problems/valid-anagram/

## 1.1 Summary

- Inputs contain Unicode characters
- Create an array which have length = 127 (total unicode characters), will with 0
- Everytime character is appeared
  - In string s then plus 1
  - In string t then minus 1
- Check all elements in array are equal 0

## 1.2. Code

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) return false;
    let arr = new Array(127).fill(0)
    for (let i = 0; i < s.length; i++) {
        arr[s[i].charCodeAt(0)]++;
        arr[t[i].charCodeAt(0)]--;
    }

    return arr.every(e => e === 0)
};

```

# 2. First Unique Character in a String

https://leetcode.com/problems/first-unique-character-in-a-string/

## 2.1 Summary

- The unique character means its only appear 1 time in the array
- Loop through an array
  - Check indexOf character at index i equal i and indexOf character from index i+1 to length-1 does not exists => character at i is the first character unieuq

## 2.2. Code

```js
/**
* @param {string} s
* @return {number}
*/
var firstUniqChar = function (s) {
    for (let i = 0; i < s.length; i++) {
        if (s.indexOf(s[i]) === i && s.indexOf(s[i], i + 1) === -1) return i
    }
    return -1
}
```


# 3. LRU Cache

https://leetcode.com/problems/lru-cache/

## 3.1 Summary

The Map object in javascript holds key-value pairs and remembers the original insertion order of the keys
    - When we get value -> reset order ( remove and add again)
    - When we put value
      - Reset order
      - Delete the first key of Map if size is greater than capacity


## 3.2. Code

```js
/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
    this.capacity = capacity;
    this.map = new Map();
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
    if (this.map.has(key)) {
        const value = this.map.get(key)
        this.map.delete(key)
        this.map.set(key, value)
        return value;
    }
    return -1;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
    if (this.map.has(key)) this.map.delete(key)
    this.map.set(key, value)
    if (this.map.size > this.capacity) this.map.delete(this.map.keys().next().value)
};


/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```


# 4. Making File Names Unique

https://leetcode.com/problems/making-file-names-unique/

## 4.1 Summary

Using map memorize the name and appearance times
- If name does not exist -> put name, appearance times = 1
- Else 
  - Generate new name
  - Increase appearance times and generate new name if the new name is already exist in the map
  - Set newName with appearance times = 1
  - Set name with appearance times = current + 1

## 4.2. Code

```js
/**
 * @param {string[]} names
 * @return {string[]}
 */
var getFolderNames = function (names) {
    if (names.length < 2) return names;
    const nameMap = new Map()
    let i = 0;
    while (i < names.length) {
        const name = names[i];
        if (!nameMap.has(name)) nameMap.set(name, 1)
        else {
            let times = nameMap.get(name)
            let newName = `${name}(${times})`
            while (nameMap.has(newName)) {
                times = times + 1;
                newName = `${name}(${times})`
            }
            names[i] = newName
            nameMap.set(newName, 1)
            nameMap.set(name, times + 1)
        }
        i++;
    }
    return names;
};
```