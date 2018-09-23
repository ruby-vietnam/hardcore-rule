```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  let i;
  let j = m;
  for (i= 0; i < n; i++) {
    nums1[j] = nums2[i]
    j++;
  }
  InsertionSort(nums1);
  console.log(nums1);
};

function InsertionSort(arr) {

  let len     = arr.length,
	    value,                      
	    i,                          
	    j;                          
	
	for(i = 1; i < len; i++) {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = value
	}

	return arr
}
```
