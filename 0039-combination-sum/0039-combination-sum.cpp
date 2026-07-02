class Solution {
public:
    void fun(vector<int>& candidates, int n, int idx, vector<int>& diary, vector<vector<int>>& res, int sum, int target){
        if(idx == n){
            if(sum == target) res.push_back(diary);
            return;
        }
        fun(candidates, n, idx+1, diary, res, sum, target);
        if(candidates[idx] + sum <= target){
            diary.push_back(candidates[idx]);
            sum += candidates[idx];
            fun(candidates, n, idx, diary, res, sum, target);
            diary.pop_back();
            sum -= candidates[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<int> diary;
        vector<vector<int>> res;
        int idx = 0;
        fun(candidates, n, idx, diary, res, sum, target);
        return res;
    }
};