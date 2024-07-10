/**
 * @param {number[]} nums
 * @return {boolean}
 */

"use strict";

var canJump = function(nums) {
    
    let n = nums.length;

    let lowestPossiblePosition = n - 1;

    for(let i = n - 2; i >= 0; i--){
        if(i + nums[i] >= lowestPossiblePosition){
            lowestPossiblePosition = i;
        }
    }

    return lowestPossiblePosition == 0;
};