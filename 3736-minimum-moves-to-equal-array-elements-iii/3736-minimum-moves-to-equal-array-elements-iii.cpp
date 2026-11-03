class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for(int num : nums){
            moves += (max_ele-num);
        }
        return moves;
    }
};