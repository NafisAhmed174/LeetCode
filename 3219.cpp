class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<long long, long long>> cuts;
        for(int i = 0; i < m - 1; i++){
            cuts.push_back({horizontalCut[i], 0});
        }
        for(int i = 0; i < n - 1; i++){
            cuts.push_back({verticalCut[i], 1});
        }

        sort(cuts.rbegin(), cuts.rend());

        long long hcut = 0, vcut = 0, ans = 0;
        for(auto p: cuts){
            if(p.second == 0){
                ans += p.first * (vcut + 1);
                hcut++;
            }else{
                ans += p.first * (hcut + 1);
                vcut++;
            }
        }
        return ans;
    }
};