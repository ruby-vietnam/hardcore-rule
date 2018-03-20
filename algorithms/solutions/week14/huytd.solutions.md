# Problem 1: Power of Four

URL: https://leetcode.com/problems/power-of-four/description/

Status:

```
  ✔ Accepted
  ✔ 1060/1060 cases passed (128 ms)
  ✔ Your runtime beats 32.81 % of javascript submissions
```

Approach: If a number is a power of four, the logarithm base 4 of this number should be an integer.

In JavaScript, we don't have any built in function to calculate logarithm of any base, we only have logarithm of base 2, 10 and e.

There's a math trick that can do the job, is to change the base:

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/2501990f5b076a3985574629027fff0e71e73e4d)

We can generalize it to calculate logarithm of any base:

![](http://www.purplemath.com/modules/logs/logrul09.gif)

See more details [here](http://www.purplemath.com/modules/logrules5.htm) and [here](https://en.wikipedia.org/wiki/Common_logarithm#Numeric_value)

To check if a number is integer or not, we use the nature of JavaScript, that it will convert any type of number into Int32 when we apply a bitwise operator on that number.

```javascript
var isPowerOfFour = function(num) {
    let lg4 = Math.log(num) / Math.log(4);
    return lg4 === (~~lg4);
};
```
