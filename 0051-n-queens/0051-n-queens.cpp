class Solution {
public:
vector<vector<string>> result;
unordered_set<int> cols;
unordered_set<int> diags;
unordered_set<int> antiDiags;


    void solve(vector<string>& board, int row){
        if(row == board.size()){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < board.size(); col++){
            int diag_const = row + col;
            int antidiag_const = row - col;

            if(cols.find(col) != cols.end() || diags.find(diag_const) != diags.end() || antiDiags.find(antidiag_const) != antiDiags.end()) continue;

            cols.insert(col);
            diags.insert(diag_const);
            antiDiags.insert(antidiag_const);
            board[row][col] = 'Q';

            solve(board, row+1);

            cols.erase(col);
            diags.erase(diag_const);
            antiDiags.erase(antidiag_const);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0) return {};
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};