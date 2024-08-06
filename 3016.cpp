class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26, 0);
        int n = word.length();

        for(int i = 0; i < n; i++){
            f[word[i] - 'a']++;
        }

        sort(f.rbegin(), f.rend());

        int ans = 0;

        for(int i = 0; i < 26; i++){
            if(!f[i]) break;
            ans += f[i] * (i / 8 + 1);
        }
        
        return ans;
    }
};