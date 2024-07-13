class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<pair<int,int>> v(n);
        
        for(int i = 0; i < n; i++){
            v[i] = {rating[i], i};
        }
        sort(v.begin(), v.end());

        vector<int> res(n, 1);

        auto update = [&] (int i){
            if(i && rating[i] > rating[i - 1]){
                res[i] = max(res[i], res[i - 1] + 1);
            }
            if(i + 1 < n && rating[i] > rating[i + 1]){
                res[i] = max(res[i], res[i + 1] + 1);
            }
        };

        for(auto p: v){
            update(p.second);
        }
        return accumulate(res.begin(), res.end(), 0LL);
    }       
};