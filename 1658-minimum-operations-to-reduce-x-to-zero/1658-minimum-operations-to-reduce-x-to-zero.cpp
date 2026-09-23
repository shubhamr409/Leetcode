class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        mpp[0] = -1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            mpp[sum] = i;
        }
        if(sum < x) return -1;
        int restSum = sum - x;
        int longest = INT_MIN;
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mpp.count(sum - restSum)){
                longest = max(longest, i - mpp[sum-restSum]);
            }
        }
        return longest == INT_MIN ? -1 : n-longest;

    }
};