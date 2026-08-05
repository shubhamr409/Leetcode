class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0;
        int res = INT_MIN;
        unordered_map<char, int> mpp;
        for(int high = 0; high < n; high++){
            mpp[s[high]]++;
            int k = high - low + 1;
            while(mpp.size() < k){
                mpp[s[low]]--;
                low++;
                if(mpp[s[low-1]] == 0) mpp.erase(s[low-1]);
                k = high - low + 1;
            }
            res = max(res, k);
        }
        return res == INT_MIN ? 0 : res;
    }
};