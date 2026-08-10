class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> freq;
       long long tSum = 0;
       for(auto &it: nums){
        tSum+=it;
        freq[it]++;
       }

       int ans = INT_MIN;
       for(int i = 0 ; i < n ; i++){
         int out = tSum - (2*nums[i]);
         if(freq.find(out) != freq.end()){
            if(out != nums[i] || freq[nums[i]] >= 2){
                ans = max(ans , out);
            }
         }
       }
       return ans;
    }
};