/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  const INT_MAX = Math.pow(2, 31) - 1;
  const INT_MIN = -Math.pow(2, 31);
  const result = Number(str
    // Remove whitespces
    .trim()
    // A regex in which
    // [\-+]{0,1} is optional sign of number
    // [0-9]* is digist
    .split(/^([\-+]{0,1}[0-9]*)/)[1]
  ) || 0;

  if (result < INT_MIN) { return INT_MIN; }
  if (result > INT_MAX) { return INT_MAX; }
  return result;
};
