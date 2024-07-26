class Solution {
public:
    const int inf = 1e9;
    vector<int> dist;
    vector<pair<int, int>> adj[100];
    int n;

    int dijkstra(int src, int distanceThreshold){
        for(int i = 0; i < n; i++) dist[i] = inf;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        dist[src] = 0;
        q.push({0, src});


        while(!q.empty()){

            auto p = q.top();
            q.pop();

            int vertex = p.second;
            int vertex_dist = p.first;

            if(vertex_dist > dist[vertex] || vertex_dist >= distanceThreshold) continue;

            for(auto c: adj[vertex]){
                int child = c.first;
                int weight = c.second;
                if(vertex_dist + weight < dist[child]){
                    dist[child] = vertex_dist + weight;
                    q.push({dist[child], child});
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i != src && dist[i] <= distanceThreshold) cnt++;
        }
        return cnt;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this -> n = n;
        dist.resize(n);
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
        for(auto e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int mn = inf, node = -1;

        for(int i = 0; i < n; i++){
            int now = dijkstra(i, distanceThreshold);
            if(now <= mn){
                mn = now;
                node = i;
            }
        }
        return node;
    }
};