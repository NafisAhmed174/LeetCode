class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int, double>>> g(n);

        for(int i = 0; i < edges.size(); i++){
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double,int>> p;
        vector<double> d(n, 0.);

        d[start_node] = 1.;
        p.push({1, start_node});

        while(!p.empty()){
            
            auto it = p.top();
            p.pop();

            double dist = it.first;
            int node = it.second;

            if(dist < d[node]) continue;

            for(auto x: g[node]){
                int child = x.first;
                double weight = x.second;
                if(d[child] < dist * weight){
                    d[child] = dist * weight;
                    p.push({d[child], child});
                    // cout << child << " " << d[child] << "\n";
                }
            }
        } 
        return d[end_node];
    }
};