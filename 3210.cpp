class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string s2(n, 'a');
        for(int i = 0; i < n; i++){
            s2[i] = s[(i + k) % n]; 
        }
        return s2;
    }
};