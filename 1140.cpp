#include<bits/stdc++.h>
int dp[2][101][101];
class Solution {
public:
    int n;
    int func(vector<int>& piles, int t, int i, int mx){
        if(i >= n) return 0;
        int &ret = dp[t][i][mx];
        if(ret != -1) return ret;
        int sum = 0;
        int ans = 0;
        if(t) ans = 1e8;
        for(int j = 0; j < 2 * mx; j++){
            if(i + j >= n) break;
            sum += piles[i + j];
            if(t){
                ans = min(ans, func(piles, t ^ 1, i + j + 1, min(n, max(mx, j + 1))));
            }
            else ans = max(ans, sum + func(piles, t ^ 1, i + j + 1, min(n, max(mx, j + 1))));
        }
        return ret = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[0][i][j] = dp[1][i][j] = -1;
            }
        }
        return func(piles, 0, 0, 1);
    }   
};