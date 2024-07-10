class Solution {
public:
    string removeDigit(string s, char d) {
        
        int n = s.length();
        
        char mn = 'a';
        int pos = -1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == d){
                if(i + 1 < n){
                    if(d < s[i + 1]){
                        pos = i;
                        break;
                    }
                }
            }   
        }
        string res;
        

        
        if(pos != -1){
            for(int i = 0; i < pos; i++) res.push_back(s[i]);
            for(int i = pos + 1; i < n; i++) res.push_back(s[i]);
            return res;    
        }
        
        for(int i = 0; i < n; i++){
            if(s[i] == d){
                pos = i;
            }   
        }   
        if(pos == -1) pos = n - 1;
        for(int i = 0; i < pos; i++) res.push_back(s[i]);
        for(int i = pos + 1; i < n; i++) res.push_back(s[i]);
        return res;  

    }
};