/**
 * @param {number[]} nums
 * @return {boolean}
 */

"use strict";

var jump = function(nums) {
    
    let n = nums.length;

    let dp = new Array(n);

    dp[n - 1] = 0;

    for(let i = n - 2; i >= 0; i--){
        dp[i] = Infinity;
        for(let j = 1; j <= nums[i] && i + j < n; j++){
            dp[i] = Math.min(dp[i], 1 + dp[i + j]);
        }
    }
    return dp[0];
};