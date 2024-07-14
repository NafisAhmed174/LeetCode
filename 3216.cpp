class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        
        for(int i = 0; i < n - 1; i++){
            if(s[i] > s[i + 1] && (s[i] - '0') % 2 == (s[i + 1] - '0') % 2){
                swap(s[i], s[i + 1]);
                break;
            }
        }
        
        return s;
    }
};