/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
"use strict";

var rotate = function(nums, k) {

    let n = nums.length;
    if(k == 0) return;

    let newAr = new Array(n);

    for(let i = 0; i < n; i++){
        newAr[(i + k) % n] = nums[i];
    }
    
    for(let i = 0; i < n; i++){
        nums[i] = newAr[i];
    }
};