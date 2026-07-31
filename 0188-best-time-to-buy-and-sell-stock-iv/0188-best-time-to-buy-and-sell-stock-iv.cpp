class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = k * 2;
        int z = k;
        vector<vector<int>> res(n+1, vector<int>(k+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                if(j % 2 == 0){
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
        return res[0][z];
    }
};