/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
"use strict"

var kthSmallest = function(matrix, k) {

    let n = matrix.length;

    // const rowSearch = (rowNumber, target) =>{ 

    //     let mid, lo = 0, hi = n - 1;

    //     while(hi - lo >= 2){
    //         mid = Math.floor((lo + hi) / 2);
    //         if(matrix[rowNumber][mid] <= target){
    //             lo = mid;
    //         }else{
    //             hi = mid - 1;
    //         }
    //     }
    //     if(matrix[rowNumber][hi] <= target) return hi + 1;
    //     if(matrix[rowNumber][lo] <= target) return lo + 1;
    //     return 0;
    // }

    // const func = (mid) => { // extra binary search needed
    //     let tot = 0;
    //     for(let i = 0; i < n; i++){
    //         tot += rowSearch(i, mid);
    //     }
    //     return tot;
    // }

    const func = (mid) => { // optimized o(n)

        let row = n - 1, col = 0, cnt = 0;

        while(row >= 0 && col < n){
            if(matrix[row][col] <= mid){
                cnt += row + 1;
                col++;
            }else{
                row--;
            }
        }
        return cnt;
    }


    const binarySearch = (lo, hi) =>{  // O(log(1e9))
        let mid;
        while(hi - lo >= 2){
            mid = Math.floor((lo + hi) / 2);

            if(func(mid) >= k){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        if(func(lo) >= k) return lo;
        return hi;
    };

    let ans = binarySearch(-1000000000, 1000000000);
    return ans;
};