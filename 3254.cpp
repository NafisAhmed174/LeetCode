class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> v(n);

        for(int i = 0; i < n; i++){
            if(i + 1 < n && nums[i] + 1 != nums[i + 1]){
                v[i] = 1;
            }
            if(i) v[i] += v[i - 1];
        }

        vector<int> res(n - k + 1);
        for(int i = 0; i < n - k + 1; i++){
            int now = v[i + k - 1];
            if(i) now -= v[i - 1];
            if(i + k - 1 != n - 1 && nums[i + k - 1] + 1!= nums[i + k]) now --;
            if(now) res[i] = -1;
            else res[i] = nums[i + k - 1];
        }
        return res;
    }
};