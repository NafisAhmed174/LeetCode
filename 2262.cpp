class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        long long tot = 0;
        for(long long i = 1; i <= n; i++){
            tot += i * (n - i + 1);
        }

        vector<long long> f(26,0);
        vector<long long> pf(26,0);
        vector<long long> last(26, -1);
        vector<long long> sum(26, 0);

        for(int i = 0; i < n; i++){
            int now = s[i] - 'a';
            tot -= f[now];
            int lst = last[now];
            last[now] = i;
            sum[now] += i - lst;
            pf[now] = f[now];
            f[now] += sum[now];
            
            for(int j = 0; j < 26; j++){
                if(j == now) continue; 
                tot -= pf[j];
            }
        }
        return tot;
    }
};