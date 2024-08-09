class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        int ans = 0;

        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 2; j++){
                set<int> st;
                for(int k = i; k < i + 3; k++){
                    for(int kk = j; kk < j+ 3; kk++){
                        st.insert(g[k][kk]);
                    }
                }
                if(st.size() != 9 || *st.begin() != 1 || *st.rbegin() != 9) continue;
                int a, b ,c , d , e, f;
                a = g[i][j] + g[i][j + 1] + g[i][j + 2];
                b = g[i + 1][j] + g[i + 1][j + 1] + g[i + 1][j + 2];
                c = g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2];
                if(a != b || b!= c) continue;

                d = g[i][j] + g[i + 1][j] + g[i + 2][j];
                e = g[i][j + 1] + g[i + 1][j + 1] + g[i + 2][j + 1];
                f = g[i][j + 2] + g[i + 1][j + 2] + g[i + 2][j + 2];
                if(d != e || e != f) continue;

                a = g[i][j] + g[i + 2][j + 2];
                b = g[i + 2][j] + g[i][j + 2];

                ans += a == b;

            }
        }
        return ans;
    }
};