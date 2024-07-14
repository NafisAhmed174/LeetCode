class Solution {
public:
    vector<int> h, v;
    int n, m;

    int dp[21][21][21][21];

    int func(int r1, int c1, int r2, int c2){
        if(r1 == r2 && c1 == c2) return 0;

        int &ret = dp[r1][c1][r2][c2];
        if(ret != -1) return ret;

        int ans = 1e9;

        for(int i = r1; i < r2; i++){
            ans = min(ans, h[i] + func(r1, c1, i, c2) + func(i + 1, c1, r2, c2));
        }

        for(int i = c1; i < c2; i++){
            ans = min(ans, v[i] + func(r1, c1, r2, i) + func(r1, i + 1, r2, c2));
        }   
        return ret = ans;
    }

    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        h = horizontalCut, v = verticalCut;
        this->n = n;
        this->m = m;
        memset(dp, -1, sizeof dp);
        int ans = func(0, 0, m-1, n-1);
        return ans;
    }
};