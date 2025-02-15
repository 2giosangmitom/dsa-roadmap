/**
 * @param {number} n
 * @return {boolean}
 */
function canAliceWin(n) {
  if (n < 10) return false;

  n -= 10;

  let temp = 9;
  let res = true;

  while (n - temp >= 0) {
    n -= temp--;
    res = !res;
  }

  return res;
}

export { canAliceWin };
