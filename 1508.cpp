class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int M = 1e9 + 7;
        int sz = accumulate(nums.begin(), nums.end(), 0);
        vector<int> f(sz + 1);

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                f[sum]++;
            }
        }

        long long now = 0, ans = 0;

        for(int i = 0; i <= sz; i++){
            if(now >= right) break;
            
            if(now + f[i] < left){
                now += f[i];
            }
            else if(now >= left){
                if(now + f[i] < right){
                    now += f[i];
                    ans += f[i] * i;
                }else{
                    ans += (right - now) * i;
                    now = right;
                    break;
                }
            }else if(now + f[i] >= left){
                ans += (min(right + 0LL, now + f[i]) - left + 1) * i;
                now += f[i];
                if(now >= right) break;
            }
        }
        return ans % M;
    }   
};