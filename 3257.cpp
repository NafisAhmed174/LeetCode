#include<bits/stdc++.h>
#define ll long long

class Solution {
public:
    
    long long maximumValueSum(vector<vector<int>>& v) {
        
        int n = v.size(), m = v[0].size();
        vector<pair<ll,pair<ll,ll>>> vv;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vv.push_back({v[i][j],{i,j}});
                // cout << i << " " << j << " " << v[i][j] << endl;
            }
        }
        
        sort(vv.rbegin(), vv.rend());

        ll mx = -1e16;

        ll N = 400;
        if(vv.size() < N) N = vv.size();

        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(vv[i].second.first == vv[j].second.first) continue;
                if(vv[i].second.second == vv[j].second.second) continue;
                for(int k = j + 1; k < N; k++){
                    if(vv[i].second.first == vv[k].second.first) continue;
                    if(vv[i].second.second == vv[k].second.second) continue;
                    if(vv[k].second.first == vv[j].second.first) continue;
                    if(vv[k].second.second == vv[j].second.second) continue;
                    mx = max(mx, vv[i].first + vv[j].first + vv[k].first);
                }
            }
        }
        return mx;
    }
};