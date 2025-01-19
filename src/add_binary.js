/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
function addBinary(a, b) {
  if (a.length !== b.length) {
    if (a.length < b.length) {
      a = a.padStart(b.length, "0");
    } else {
      b = b.padStart(a.length, "0");
    }
  }

  let carry = 0;
  let res = "";

  for (let i = a.length - 1; i >= 0; i--) {
    const sum = +a[i] + +b[i] + carry;
    const digit = Math.trunc(sum % 2);
    carry = Math.trunc(sum / 2);
    res = digit.toString().concat(res);
  }

  if (carry != 0) {
    res = carry.toString().concat(res);
  }

  return res;
}

export { addBinary };
