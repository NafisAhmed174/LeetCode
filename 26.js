/**
 * @param {number[]} nums
 * @return {number}
 */

"use strict";

var removeDuplicates = function(nums) {
    let k = 0, n = nums.length;
    for(let i = 1; i < n; i++){
        if(nums[i] != nums[k]){
            k++;
            nums[k] = nums[i];
        }
    }
    return k + 1;
};