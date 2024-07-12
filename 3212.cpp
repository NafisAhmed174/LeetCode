template< class T >
struct CumulativeSum2D {
    vector< vector< T > > data;
    
    CumulativeSum2D(int W, int H) : data(W + 1, vector< T >(H + 1, 0)) {}
    
    void add(int x, int y, T z) {
        ++x, ++y;
        if(x >= data.size() || y >= data[0].size()) return;
        data[x][y] += z;
    }
    
    void build() {
        for(int i = 1; i < data.size(); i++) {
        for(int j = 1; j < data[i].size(); j++) {
            data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
        }
        }
    }
    
    T query(int sx, int sy, int gx, int gy) const {
        return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
    }
};

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> x(n, vector<int>(m, 0));
        // vector<vector<int>> y(n, vector<int>(m, 0));

        CumulativeSum2D<int> x(n, m);
        CumulativeSum2D<int> y(n, m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X'){
                    x.add(i, j, 1);
                    y.add(i, j, 0);
                }else if(grid[i][j] == 'Y'){
                    x.add(i, j, 0);
                    y.add(i, j, 1);
                }else{
                    x.add(i, j, 0);
                    y.add(i, j, 0);
                }
            }
        }
        x.build();
        y.build();
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(x.query(0, 0, i, j) && x.query(0, 0, i, j) == y.query(0, 0, i, j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};