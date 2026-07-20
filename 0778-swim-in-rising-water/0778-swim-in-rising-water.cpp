class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0, -1}};
    bool possibleToReach(vector<vector<int>>& grid, int n, int i, int j, int t, vector<vector<bool>>& visited){
        if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] == true || grid[i][j] > t){
            return false;
        }
        visited[i][j] = true;
        if(i == n-1 && j == n-1) return true;
        for(auto &dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(possibleToReach(grid, n, i_, j_, t, visited)){
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0];
        int r = n*n - 1;
        int res = 0;
        while(l <= r){
            int mid = l + (r-l) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(possibleToReach(grid, n, 0, 0, mid, visited)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};