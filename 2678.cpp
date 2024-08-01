class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &s: details){
            ans += s[11] > '6' || s[11] == '6' && s[12] >='1'; 
        }
        return ans;
    }
};