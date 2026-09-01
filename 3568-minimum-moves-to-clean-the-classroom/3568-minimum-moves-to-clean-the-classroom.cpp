class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int litterBit[20][20];
        int max_energy = energy;
        int litterCount = 0;
        int startRow = 0;
        int startCol = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                litterBit[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                } else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;
        if (litterCount == 0) 
            return 0;
        
        vector<vector<vector<vector<bool>>>> seen(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(max_energy+1, vector<bool>(1 << litterCount, false))));
        
        queue<tuple<int, int, int, int>> q;
        q.push({startRow, startCol, max_energy, 0});
        seen[startRow][startCol][max_energy][0] = true;

        int moves = 0;
        
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int currSize = q.size();
            while(currSize--){
                auto [r, c, e, mask] = q.front();
                q.pop();
                
                if(mask == allCollected) return moves;
                if(e == 0) continue;
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    
                    int next_e = e - 1;     
                    int next_mask = mask;

                    if (classroom[nr][nc] == 'R') {
                        next_e = energy;
                    } else if (classroom[nr][nc] == 'L') {
                        next_mask |= (1 << litterBit[nr][nc]);
                    }

                    if(!seen[nr][nc][next_e][next_mask]){
                            seen[nr][nc][next_e][next_mask] = true;
                            q.push({nr, nc, next_e, next_mask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};