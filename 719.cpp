class Solution {
public:

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        function<int(int)> func=[&](int mid){
            int cnt = 0;
            int l = 0, r = 0;
            while(r < n){
                while(nums[r] - nums[l] > mid){
                    l++;
                }
                cnt += r - l;
                r++;
            }
            return cnt >= k;
        };

        function<int(int, int)> bs =[&](int l, int r){

            int mid;

            while(r - l >= 2){
                mid = (l + r) >> 1;
                if(func(mid)) r = mid;
                else l = mid + 1;
            }

            if(func(l)) return l;
            return r;
        };

        int ans = bs(0, 1000000);
        return ans;
    }
};