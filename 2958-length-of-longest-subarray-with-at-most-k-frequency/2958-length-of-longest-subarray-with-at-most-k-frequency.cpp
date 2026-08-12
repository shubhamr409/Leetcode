class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int i = 0;
        int max_len = INT_MIN;
        for(int j = 0; j < n; j++){
            mpp[nums[j]]++;

            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                i++;
            }
            max_len = max(max_len, j-i+1);
        }
        return max_len;
    }
};