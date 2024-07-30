class Solution {
public:

    int minimumDeletions(string s) {
        int n = s.length();

        int a = count(s.begin(), s.end(), 'a');

        int ans = min(a, n - a);
        int b = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'b') b++;
            else a--;
            ans = min(ans, b + a);
        }
        return ans;
    }
};
