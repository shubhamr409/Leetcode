class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int minIdx = -1;
        int maxIdx = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIdx = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                minIdx = i;
            }
        }
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        return min({left+1+n-right, right + 1, n-left});
    }
};