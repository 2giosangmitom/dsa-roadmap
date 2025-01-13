/**
 * @param {string[]} strs
 * @return {string}
 */
function longestCommonPrefix(strs) {
  let longestPrefix = strs[0];

  for (let i = 0; i < strs.length; i++) {
    while (strs[i].indexOf(longestPrefix) != 0) {
      longestPrefix = longestPrefix.slice(0, longestPrefix.length - 1);
      if (longestPrefix == "") {
        return "";
      }
    }
  }

  return longestPrefix;
}

export { longestCommonPrefix };
