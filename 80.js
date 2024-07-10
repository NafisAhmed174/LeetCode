/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {

    let k = 0, f = false;

    for(let i = 1; i < nums.length; i++){
        if(nums[i] != nums[k]){
            k++;
            nums[k] = nums[i];
            f = false;
        }
        else if(f == false){
            k++;
            nums[k] = nums[i];
            f = true;
        }
    }

    return k + 1;
    
};