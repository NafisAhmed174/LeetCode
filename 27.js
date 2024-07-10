/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */

"use strict";

var removeElement = function(nums, val) {
    let l = 0, n = nums.length;

    for(let i = 0; i < n; i++){
        if(nums[i] != val){
            nums[l] = nums[i];
            l++;
        }
    }
    return l;
};