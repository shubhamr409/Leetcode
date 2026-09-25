class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 2*n-1; i >= 0; i--){
            int idx = i % n;
            int currEle = nums[idx];
            while(!st.empty() && st.top() <= currEle) st.pop();
            if(i < n) st.empty() ? ans[i] = -1 : ans[i] = st.top();
            st.push(currEle);
        }
        return ans;
    }
};