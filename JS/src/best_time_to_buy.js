/**
 * @param {number[]} prices
 * @return {number}
 */
function maxProfit(prices) {
  if (prices.length <= 1) {
    return 0;
  }

  let res = 0;
  let buy = prices[0];

  for (let i = 1; i < prices.length; i++) {
    if (prices[i] > buy) {
      const profit = prices[i] - buy;
      res = Math.max(profit, res);
    } else {
      buy = prices[i];
    }
  }

  return res;
}

export { maxProfit };
