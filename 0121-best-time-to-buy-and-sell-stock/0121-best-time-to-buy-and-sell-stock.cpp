class Solution {
public:
    int fun(vector<int>& prices, int n, int i, int k, vector<vector<int>>& dp){
        if(i == n) return 0;
        if(k == 0) return 0;
        //buy
        if(dp[i][k] != -1) return dp[i][k];
        if(k == 2){
            int c1 = fun(prices, n, i+1, k-1, dp) - prices[i];
            int c2 = fun(prices, n, i+1, k, dp);
            return dp[i][k] = max(c1, c2);
        }
        // sell
        else{
            int c1 = fun(prices, n, i+1, k-1, dp) + prices[i];
            int c2 = fun(prices, n, i+1, k, dp);
            return dp[i][k] = max(c1, c2);
        }
    }
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
                    int c1 = res[i+1][j-1] + prices[i];
                    int c2 = res[i+1][j];
                    res[i][j] = max(c1, c2);
                }
            }
        }
        return res[0][2];
    }
};