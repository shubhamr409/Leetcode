class Solution {
public:
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int n, int m, int row, int col, vector<vector<bool>>& vis){
        vis[row][col] = 1;
        for(int k = 0; k < 4; k++){
            int r = row + x[k];
            int c = col + y[k];
            if(valid(r, c, n, m) && grid[r][c] == '1' && vis[r][c] == 0){
                dfs(grid, n, m, r, c, vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid, n, m, i, j, vis);
                    res++;
                }
            }
        }
        return res;
    }
};