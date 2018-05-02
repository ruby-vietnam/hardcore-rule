/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  const { length } = digits;

  // Stop condition
  if (length === 0) { return [1]; }

  // [1, 2, 4] => leads = [1, 2] and unit = 4
  const leads = digits.slice(0, length - 1);
  const unit = digits[length - 1];

  return (unit < 9)
    // Easy case
    ?  [...leads, unit + 1]
    // Recursive call
    : [...plusOne(leads), 0];
};
