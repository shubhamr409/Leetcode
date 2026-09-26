class Solution {
public:
int row_arr[3] = {-1, 0, 1};
int col_arr[3] = {1, 1, 1};
int m, n;

    bool isValid(int row, int col){
        if(row < 0 || col < 0 || row >= m || col >= n) return false;
        else return true;
    }
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c){
        if(dp[r][c] != -1) return dp[r][c];
        int max_moves = 0;
        for(int i = 0; i < 3; i++){
            int nr = r + row_arr[i];
            int nc = c + col_arr[i];
            if(isValid(nr, nc) && grid[nr][nc] > grid[r][c]) max_moves = max(max_moves, 1 + solve(grid, dp, nr, nc));
        }
        return dp[r][c] = max_moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans = max(ans, solve(grid, dp, i, 0));
        }
        return ans;
    }
};