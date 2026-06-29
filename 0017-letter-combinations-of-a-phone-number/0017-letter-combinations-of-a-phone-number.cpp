class Solution {
public:
    void fun(string& digits, int n, int idx, string& diary, vector<string>& res, unordered_map<int, string> mpp){
        if(idx == n){
            res.push_back(diary);
            return;
        }
        string choice = mpp[digits[idx] - '0'];
        for(int j = 0; j < choice.size(); j++){
            diary.push_back(choice[j]);
            fun(digits, n, idx+1, diary, res, mpp);
            diary.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<int, string> mpp;
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";

        string diary;
        vector<string> res;
        int n = digits.size();
        fun(digits, n, 0, diary, res, mpp);
        return res;
    }
};