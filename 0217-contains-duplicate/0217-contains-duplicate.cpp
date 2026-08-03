class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        for (const auto& [key, value] : mpp) {
        if (value > 1) return true;
        }
        return false;
    }
};