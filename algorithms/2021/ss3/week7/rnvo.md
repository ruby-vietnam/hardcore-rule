# 1. Majority Element

https://leetcode.com/problems/majority-element/

## 1.1 Summary

- Same as reduce in javascript
- Counting appearance times of number, if `counting > length /2` then return its value

## 1.2. Code

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
  let length = nums.length;
  if (length === 0) return;
  if (length === 1) return nums[0];
  let m = {}
  for (let i = 0; i < length; i++) {
    if (!m[nums[i]]) m[nums[i]] = 1
    else {
      m[nums[i]] = m[nums[i]] + 1
      if (m[nums[i]] > length / 2) return nums[i]
    }
  }
};
```

# 2. Sort Array By Parity

https://leetcode.com/problems/sort-array-by-parity/

## 2.1 Summary

- Using `2 pointers` `left=0`and `right = length -1`
- if value at left is odd and value at right is even then swap  (odd: number %2 = 1, even -> number %2 = 0)
- if number at left is even -> left++
- if number at right is even -> right--

## 2.2. Code

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function (nums) {
  let length = nums.length;
  if (!nums) return [];
  if (length <= 1) return nums;

  function swap(source, target) {
    let tmp = nums[source];
    nums[source] = nums[target]
    nums[target] = tmp
  }

  let left = 0, right = length - 1;
  while (left < right) {
    if (nums[left] % 2 > nums[right] % 2) {
      swap(left, right);
    }
    if (nums[left] % 2 === 0) left++
    if (nums[right] % 2 === 1) right--
  }

  return nums;
};
```


# 3. 3Sum

https://leetcode.com/problems/3sum/

## 3.1 Summary

- Sort the array in ascending order
- Go through an array with 2 pointers: low: index+1 and high: length-1
  - If sum of values at low, high = *-*value at index -> push to result array, low++, high--
  - If sum of values at low, high > *-*value at index which means we need to `decrease the sum` then `high--`
  - Otherwise `low++`


## 3.2. Code

```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  let length = nums.length;
  if (length < 3) return []
  nums = nums.sort();
  let m = {}
  let arr = []
  let idx = 1, low = 0, high = length - 1;
  while (idx < length - 2) {
    if (nums[low] + nums[high] === -nums[idx]) {
      arr.push([nums[idx], nums[low], nums[high]])
      low++;
      high--;
    } else if (nums[low] + nums[high] > -nums[idx]) {
      high--;
    } else {
      low++;
    }
    if (low >= high) {
      idx++;
      low = idx + 1;
      high = length - 1;
    }
  }

  return arr;
}
```


# 4. 3Sum Closest

https://leetcode.com/problems/3sum-closest/

## 4.1 Summary

- Sort the array in ascending order
- Set initial result is `sum of numbers at 0,1,2`
- Go though the array from 0 to length -2 with 2 pointers: low: index +1 and high: length -1
  - Each step excecute code until `low < high`
    - sum = value at index + low + high
    - if `sum === target` return sum
    - if `sum < target` which means we need to decrease the sum then `high--`
    - else `low++` which meanswe need to increase the sum
    - Check if the gap `target-sum` and `target -res`, get the `lower`one


## 4.2. Code

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
  let length = nums.length;
  if (length < 3) return;
  nums = nums.sort((a, b) => a - b);
  let res = nums[0] + nums[1] + nums[2]

  for (let i = 0; i < length - 2; i++) {
    let low = i + 1;
    let high = length - 1;
    while (low < high) {
      let sum = nums[low] + nums[high] + nums[i]
      if (sum === target) return sum
      else if (sum > target) {
        high--;
      } else if (sum < target) {
        low++;
      }
      if (Math.abs(target - sum) < Math.abs(target - res)) res = sum
    }
  }

  return res;
};
```

# 5. Merge k Sorted Lists

https://leetcode.com/problems/merge-k-sorted-lists/

## 5.1 Summary

Traverse the array then merge 2 lists =))
    - Make a recursion with
        - Breakpoint are
          - If list1 === null | undefined return list2
          - If list2 === null | undefined return list1
        - Steps:
          - If value of list1 <= list2
            list1.next equal result of method with params list1.next and list2


## 5.2. Code

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {
  let length = lists.length;
  if (length === 0) return null
  if (length === 1) return lists[0];
  let res
  for (let i = 0; i < length; i++) {
    let tmp = lists[i]
    res = mergeTwoLists(res, tmp)
  }
  return res;
};

const mergeTwoLists = (l1, l2) => {
  if (!l1) return l2
  if (!l2) return l1
  if (l1.val <= l2.val) {
    l1.next = mergeTwoLists(l1.next, l2)
    return l1
  }
  l2.next = mergeTwoLists(l1, l2.next)
  return l2
}

```