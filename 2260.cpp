class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        
        int l = 0, r = 0;
        int n = v.size();
        int mx = n + 1;
        
        map<int,int> m;
        while(r < n){
            m[v[r]]++;
            while(m.size() < r - l + 1 && l < r){
                mx = min(mx, r - l + 1);
                m[v[l]]--;
                if(m[v[l]] == 0){
                    m.erase(v[l]);
                }
                l++;
            }
            r++;
        }
        if(mx == n + 1) return -1;
        return mx;
    }
};