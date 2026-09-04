class Solution {
public:
int n;
    int findMaximum(vector<int>& nums, int i){
        int maxi = INT_MIN;
        for(int j = 0; j <= i; j++) maxi = max(maxi, nums[j]);
        return maxi;
    }
    int findMinimum(vector<int>& nums, int i){
        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            mini = min(mini, nums[j]);
        }
        return mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        n = nums.size();
        for(int i = 0; i < n; i++){
            int maxi = findMaximum(nums, i);
            int mini = findMinimum(nums, i);
            if((maxi - mini) <= k) return i;
        }
        return -1;
    }
};