/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {

    let ans = 0;
    let mn = prices[0];

    for(let i = 1; i < prices.length; i++){
        ans = Math.max(ans, prices[i] - mn);
        if(prices[i] < mn) mn = prices[i];
    }

    return ans;
};