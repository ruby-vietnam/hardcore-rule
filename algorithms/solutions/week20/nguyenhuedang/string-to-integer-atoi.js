/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  const INT_MAX_ABS = '2147483647';
  const INT_MIN_ABS = '2147483648';

  const fillZeros = (str, length) => {
    // Filling zero for str to reach the given length
    return '0'.repeat(length - str.length) + str;
  }

  const compare = (a, b) => {
    const length = Math.max(a.length, b.length);
    // Compare the filled zero string
    return fillZeros(a, length).localeCompare(fillZeros(b, length))
  }

  const [sign, digits] = str
    // Remove whitespces
    .trim()
    // A regex in which
    // [\-+]{0,1} is optional sign of number
    // [0-9]* is digits
    .split(/^([\-+]{0,1})([0-9]*)/)
    .slice(1);

  // Couldn't find any digits
  if (!digits) { return 0; }

  if (
    // The parsed number is smaller than -INT_MIN_ABS
    // Which means, its absolute value is bigger than INT_MIN_ABS
    sign === '-' &&
    compare(digits, INT_MIN_ABS) > 0
  ) { return Number(`-${INT_MIN_ABS}`); }

  if (
    // The parsed number is bigger than INT_MAX_ABS
    sign !== '-' &&
    compare(digits, INT_MAX_ABS) > 0
  ) { return Number(INT_MAX_ABS); }

  return Number(sign + digits);
};
