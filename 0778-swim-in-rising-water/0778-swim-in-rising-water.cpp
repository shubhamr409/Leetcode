class Solution {
public:
    bool valid(int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }
    bool possibleToReach(vector<vector<int>>& grid, int n, int m, int elevation){
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n);
        for(int i = 0; i < n; i++){
            vector<int> t(m, 0);
            vis[i] = t;
        }
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if(row == n-1 && col == m-1) return true;
            for(int k = 0; k < 4; k++){
                int r = row + x[k];
                int c = col + y[k];
                if(valid(r, c, n, m) && vis[r][c] == 0 && elevation >= grid[r][c]){
                    q.push({r, c});
                    vis[r][c] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = grid[0][0];
        int high = grid[0][0];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                high = max(high, grid[i][j]);
            }
        }
        int res = 0;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(possibleToReach(grid, n, m, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};