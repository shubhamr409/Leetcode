class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>> res(n+1, vector<int>(k+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                if(j == 2){
                    int c1 = res[i+1][j-1] - prices[i];
                    int c2 = res[i+1][j];
                    res[i][j] = max(c1, c2);
                }
                else{
                    int c1 = res[i+1][2] + prices[i];
                    int c2 = res[i+1][j];
                    res[i][j] = max(c1, c2);
                }
            }
        }
        return res[0][2];
    }
};