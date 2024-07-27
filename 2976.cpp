class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        vector<pair<int,int>> adj[26];
        int n = original.size();

        int dist[26][26];

        const int inf = 1e9; 
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(i == j) dist[i][i] = 0;
                else dist[i][j] = inf;
            }
        }

        for(int i = 0; i < n; i++){
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        // Floyd Warshall
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][k] != inf && dist[k][j] != inf){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.length(); i++){
            if(dist[source[i] - 'a'][target[i] - 'a'] == inf){
                return -1;
            }
            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};