class Solution {
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& image, int row, int col, int initialColor, int newColor, int n, int m){
        image[row][col] = newColor;
        for(int i = 0; i < 4; i++){
            int r = row + x[i];
            int c = col + y[i];
            if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == initialColor){
                dfs(image, r, c, initialColor, newColor, n, m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor == color) return image;
        int n = image.size();
        int m = image[0].size();
        dfs(image, sr, sc, initialColor, color, n, m);
        return image;
    }
};