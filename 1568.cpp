class Solution {
public:
    int minDays(vector<vector<int>>& grid) {

        int n , m;

        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        function<void(int, int)> dfs = [&] (int i, int j){
            if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0 || vis[i][j]) return;
            vis[i][j] = 1;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        int component = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !vis[i][j]){
                    component++;
                    if(component == 2) return 0;
                    dfs(i, j);
                }
            }
        }
        if(component == 0) return 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    vis = vector<vector<int>> (n, vector<int>(m, 0));
                    grid[i][j] = 0;
                    component = 0;

                    for(int k = 0; k < n; k++){
                        for(int l = 0; l < m; l++){
                            if(grid[k][l] && !vis[k][l]){
                                component++;
                                if(component == 2) return 1;
                                dfs(k, l);
                            }
                        }
                    }
                    if(component == 0) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};