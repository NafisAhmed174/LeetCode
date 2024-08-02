class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int oneCount = count(nums.begin(), nums.end(), 1);

        int l = 0, r = oneCount - 1, currCount = 0, maxCount = 0;

        currCount = count(nums.begin(), nums.begin() + oneCount, 1);
        maxCount = currCount;

        while(l < n - 1){
            currCount -= nums[l];
            l++;
            r++;
            if(r >= n) r -= n;
            currCount += nums[r];
            maxCount = max(maxCount, currCount);
        }
        return oneCount - maxCount;
    }
};