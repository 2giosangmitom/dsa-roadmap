/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
function combine(n, k) {
  const nums = Array.from({ length: n }, (_v, k) => k + 1);
  const memo = new Map();

  return helper(nums, k, 0, memo);
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} headIndex
 * @param {Map} memo
 * @returns {number[][]}
 */
function helper(nums, k, headIndex, memo) {
  const key = `${k}-${headIndex}`;
  if (memo.has(key)) return memo.get(key);

  if (k === 0) return [[]];
  if (nums.length - headIndex < k) return [];

  let combinations = [];
  const head = nums[headIndex];
  const tailStart = headIndex + 1;

  const tailCombinations = helper(nums, k - 1, tailStart, memo);
  for (const tailCombination of tailCombinations) {
    combinations.push([head, ...tailCombination]);
  }
  combinations = combinations.concat(helper(nums, k, tailStart, memo));

  memo.set(key, combinations);

  return combinations;
}

/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
function combine2(n, k) {
  const result = [];
  const combination = new Array(k).fill(0);

  let i = 0;
  while (i >= 0) {
    combination[i]++;

    if (combination[i] > n) {
      i--; // Backtrack
    } else if (i === k - 1) {
      result.push(Array.from(combination)); // It's now the end of the combination
    } else {
      i++; // Move to next position of the combination
      combination[i] = combination[i - 1];
    }
  }

  return result;
}

export { combine, combine2 };
