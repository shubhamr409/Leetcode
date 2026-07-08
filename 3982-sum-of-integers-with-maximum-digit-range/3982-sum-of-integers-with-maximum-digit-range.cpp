class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int> range;
        for(int i = 0; i < n; i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            int num = nums[i];
            while(num){
                int dig = num % 10;
                num /= 10;
                maxi = max(maxi, dig);
                mini = min(mini, dig);
            }
            range.push_back(maxi-mini);
        }
        int max_range = range[0];
        for(int i = 1; i < n; i++){
            if(range[i] > max_range) max_range = range[i];
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(range[i] == max_range) sum += nums[i];
        }
        return sum;
    }
};