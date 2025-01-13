/**
 * @param {string} s
 * @return {number}
 */
function myAtoi(s) {
  const MIN = -(2 ** 31);
  const MAX = -MIN - 1;
  s = s.trim();

  let i = 0;
  let sign = 1;
  if (s[i] == "-" || s[i] == "+") {
    sign = s[i] == "-" ? -1 : 1;
    i++;
  }

  let result = 0;
  while (i < s.length && s[i].match(/[0-9]/)) {
    const digit = Number(s[i]);
    result = result * 10 + digit;

    if (
      sign * result > MAX / 10 ||
      (sign * result == Math.trunc(MAX / 10) && digit > 7)
    )
      return MAX;

    if (
      sign * result < MIN / 10 ||
      (sign * result == Math.trunc(MIN / 10) && digit < -8)
    )
      return MIN;

    i++;
  }

  return sign * result;
}

export { myAtoi };
