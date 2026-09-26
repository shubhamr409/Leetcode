class Solution {
public:
    int fun(vector<int>& nums, int n, int i, int free, vector<vector<int>> &dp){
        if(i > n) return 0;
        if(dp[i][free] != -1) return dp[i][free];
        if(free == 0) return dp[i][free] = fun(nums, n, i+1, 1, dp);
        int c1 = nums[i] + fun(nums, n, i+1, 0, dp);
        int c2 = fun(nums, n, i+1, 1, dp);
        return dp[i][free] = max(c1, c2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<vector<int>> dp1(n, vector<int>(2, -1));
        int ans1 = fun(nums, n-2, 0, 1, dp1);

        vector<vector<int>> dp2(n, vector<int>(2, -1));
        int ans2 = fun(nums, n-1, 1, 1, dp2);
        return max(ans1, ans2);
    }
};