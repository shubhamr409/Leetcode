class Solution {
public:
    int fun(vector<int>& nums, int n, int i, vector<int> &dp){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int c1 = nums[i] + fun(nums, n, i+2, dp);
        int c2 = fun(nums, n, i+1, dp);
        return dp[i] = max(c1, c2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int ans1 = fun(nums, n-2, 0, dp1);
        int ans2 = fun(nums, n-1, 1, dp2);

        return max(ans1, ans2);
    }
};