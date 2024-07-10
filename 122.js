/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    
    let prev = prices[0];
    let ans = 0;
    let i = 1;
    let n = prices.length;

    while(1){
        while(i < n && prices[i] >= prices[i - 1]){
            i++;
        }
        if(i >= n){
            ans += prices[i - 1] - prev;
            break
        }else{
            ans += prices[i - 1] - prev;
            prev = prices[i];
            i++;
        }
    }

    return ans;
};