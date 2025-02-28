/**
 * @param {number} x
 * @return {number}
 */
function mySqrt(x) {
  if (x <= 1) return x;

  let res = 1;

  for (let i = 1; i <= x / 2; i++) {
    if (i * i <= x) {
      res = i;
    } else {
      break;
    }
  }

  return res;
}

export { mySqrt };
