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
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return fun(prices, n, 0, k, dp);
    }
};