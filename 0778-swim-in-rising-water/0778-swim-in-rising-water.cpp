class Solution {
public:
    bool valid(int i, int j, int n){
        if(i < 0 || i >= n || j < 0 || j >= n) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++){
            vector<int> t(n, INT_MAX);
            res[i] = t;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        res[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int currTime = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if (row == n - 1 && col == n - 1)
                return currTime;
            
            if(currTime > res[row][col]) continue;
            for(int k = 0; k < 4; k++){
                int r = row + x[k];
                int c = col + y[k];
                if(!valid(r, c, n)) continue;
                int nextTime = max(currTime, grid[r][c]);
                if(nextTime < res[r][c]){
                    res[r][c] = nextTime;
                    pq.push({nextTime, {r, c}});
                }
            }
        }
        return -1;
    }
};