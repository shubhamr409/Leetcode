class Solution {
bool valid(int i, int j, int n, int m){
    if(i < 0 || i >=n or j < 0 || j >= m) return false;
    return true;
}
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

void dfs(vector<vector<int>>&a, int n, int m, int i, int j){
    a[i][j] = 0;
    for(int k = 0; k < 4; k++){
        int row = i + x[k];
        int col = j + y[k];
        if(valid(row, col, n, m) && a[row][col] == 1){
            dfs(a, n, m, row, col);
        }
    }
    return;
}
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int j = 0; j < m; j++){
            if(board[0][j] == 1) dfs(board, n, m, 0, j);
        }
        for(int i = 0; i < n; i++){
            if(board[i][0] == 1) dfs(board, n, m, i, 0);
        }
        for(int j = 0; j < m; j++){
            if(board[n-1][j] == 1) dfs(board, n, m, n-1, j);
        }
        for(int i = 0; i < n; i++){
            if(board[i][m-1] == 1) dfs(board, n, m, i, m-1);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};