/**
 * @param {number[]} citations
 * @return {number}
 */

"use strict";

var hIndex = function(citations) {

    let n = citations.length;
    citations.sort((a, b) => a-b);

    let ans = 0;

    for(let i = n; i >= 1; i--){
        if(citations[n - i] >= i){
            ans = i;
            break
        }
    }
    return ans;
};