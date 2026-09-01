class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int litter_id[20][20];
        memset(litter_id, -1, sizeof(litter_id));
        
        int sr = 0, sc = 0, k = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    sr = r; sc = c;
                } else if (classroom[r][c] == 'L') {
                    litter_id[r][c] = k++;
                }
            }
        }
        
        if (k == 0) return 0;
        int total_mask = (1 << k) - 1;
        
        // best_energy[r][c][mask] stores the max energy seen for this state
        vector<vector<vector<int>>> best_energy(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));
        
        // Queue elements: {row, col, mask, energy, moves}
        queue<tuple<int, int, int, int, int>> q;
        q.push({sr, sc, 0, energy, 0});
        best_energy[sr][sc][0] = energy;
        
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c, mask, e, moves] = q.front();
            q.pop();
            
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;
                
                int next_e = e - 1;
                if (next_e < 0) continue;
                
                int next_mask = mask;
                if (classroom[nr][nc] == 'R') {
                    next_e = energy;
                } else if (classroom[nr][nc] == 'L') {
                    next_mask |= (1 << litter_id[nr][nc]);
                }
                
                if (next_mask == total_mask) return moves + 1;
                
                if (next_e <= best_energy[nr][nc][next_mask]) continue;
                best_energy[nr][nc][next_mask] = next_e;
                
                q.push({nr, nc, next_mask, next_e, moves + 1});
            }
        }
        
        return -1;
    }
};