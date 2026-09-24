class Solution {
public:
    bool countSum(vector<int>& nums, int mid, int k, int n){
        int subArr = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                subArr++;
                sum = nums[i];
            }
        }
        return subArr <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(countSum(nums, mid, k, n)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};