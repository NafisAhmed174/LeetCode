#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points[0].size();

        vector<ll> dp(n, 0);

        for(auto &vec: points){
            vector<ll> newDp(n, 0);
            ll currMax = 0;
            for(int i = 0; i < n; i++){
                currMax--;
                currMax = max(currMax, dp[i]);
                newDp[i] = vec[i] + currMax;
            }
            currMax = 0;
            for(int i = n - 1; i >= 0; i--){
                currMax--;
                currMax = max(currMax, dp[i]);
                newDp[i] = max(newDp[i], vec[i] + currMax);
            }
            dp = newDp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};