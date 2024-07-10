/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    temp = [];

    let i = 0, j = 0;

    while(1){
        if(i < m && j < n){
            if(nums1[i] < nums2[j]){
                temp.push(nums1[i]);
                i++;
            }else{
                temp.push(nums2[j]);
                j++;
            }
        }
        else if(i < m){
            while(i < m){
                temp.push(nums1[i]);
                i++;
            }
        }
        else if(j < n){
            while(j < n){
                temp.push(nums2[j]);
                j++;
            }
        }else{
            break
        }
    }

    for(let i = 0; i < n + m; i++){
        nums1[i] = temp[i];
    }

};