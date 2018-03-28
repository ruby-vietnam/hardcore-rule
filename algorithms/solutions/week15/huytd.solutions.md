# Problem 1: Move Zeroes

I did this on my own, I'm not copy from @qcam

```javascript
const moveZeroes = (nums) => {
    let target = 0;
    for (let i = 0; i < nums.length; i++) {
        let num = nums[i];
        if (num !== 0) {
            nums[i] = 0;
            nums[target] = num;
            target++;
        }
    }
};
```
