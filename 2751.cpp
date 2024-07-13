class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        auto compress = [&] (vector<int> &v){
            vector<int> vv = v;
            sort(vv.begin(), vv.end());
            for(auto &x: v){
                x = lower_bound(vv.begin(), vv.end(), x) - vv.begin();
                // cout << x << " ";
            }
            
        };

        compress(positions);

        int n = positions.size();
        stack<pair<int,int>> st;

        vector<int> h(n, 0), res(n,0), rankHolder(n, 0);
        for(int i = 0; i < n; i++){
            rankHolder[positions[i]] = i;
        }

        for(int i = 0; i < n; i++){
            if(directions[rankHolder[i]] == 'L'){
                int now = healths[rankHolder[i]];
                while(!st.empty() && now){
                    auto x = st.top();
                    st.pop();
                    if(x.first > now){
                        x.first --;
                        if(x.first) st.push(x);
                        now = 0;
                    }
                    else if(x.first == now){
                        now = 0;
                    }else{
                        now --;
                    }
                }
                if(now){
                    res[rankHolder[i]] = now;
                }
            }else{
                st.push({healths[rankHolder[i]], rankHolder[i]});
            }
        }

        while(!st.empty()){
            auto x = st.top();
            st.pop();
            res[x.second] = x.first;
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(res[i]) ans.push_back(res[i]);
        }
        return ans;
    }
};