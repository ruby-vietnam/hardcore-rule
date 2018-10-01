## Problem 1: [Single Number](https://leetcode.com/problems/single-number/description/)

 ```java
public int singleNumber(int[] nums) {
    List<Integer> checkDupList = new ArrayList<>();
    for (int num : nums) {
        if (checkDupList.contains(num)) {
            checkDupList.remove(Integer.valueOf(num));
        } else {
            checkDupList.add(num);
        }
    }
    return checkDupList.get(0);
}
```