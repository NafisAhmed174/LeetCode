class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        for(int mask = 0; mask < (1LL<<n); mask++){
            string s(n, '0');
            bool ok = 1;
            for(int i = 0; i < n; i++){
                if(mask & (1LL<<i)){
                    s[i] = '1';
                }
                if(i){
                    if(s[i] == '0' && s[i - 1] == '0'){
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok) res.push_back(s);
        }
        return res;
    }
};