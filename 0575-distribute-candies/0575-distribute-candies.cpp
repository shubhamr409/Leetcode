class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st(candyType.begin(), candyType.end());
        int ans = min(n/2, (int)st.size());
        return ans;
    }
};