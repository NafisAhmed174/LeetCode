class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> last(256, -1);
        int l = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int now = s[i];
            l = max(l, last[now] + 1);
            last[now] = i;

            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};