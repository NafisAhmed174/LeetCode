/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    let sum = 0, l = 0;

    let res = 0;

    for(let i = 0; i < nums.length; i++){
        sum += nums[i];
        while(sum >= target){
            if(res == 0) res = i - l + 1;
            else{
                res = Math.min(res, i - l + 1);
            }
            sum -= nums[l];
            l++;
        }
    }
    return res;
};