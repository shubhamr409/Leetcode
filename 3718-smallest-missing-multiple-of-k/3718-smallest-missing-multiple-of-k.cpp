class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());

        for(int i = 1; i <= 101; i++){
            if(set.find(k*i) == set.end()){
                return k*i;
                break;
            } 
        }
        return -1;
    }
};