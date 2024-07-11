/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    
    let zeroCount = 0;
    let prod = 1;

    for(let i = 0; i < nums.length; i++){
        if(nums[i] == 0){
            zeroCount++;
        }else{
            prod *= nums[i];
        }
    }

    for(let i = 0; i < nums.length; i++){
        if(zeroCount > 1){
            nums[i] = 0;
        }else if(nums[i] == 0){
            nums[i] = prod;
        }
        else if(zeroCount == 1){
            nums[i] = 0;
        }else{
            nums[i] = prod / nums[i];
        }
    }
    return nums;
};