class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        int ans = -1;
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};