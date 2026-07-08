class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int max_range = -1;
        int sum = 0;
        for (int num : nums) {
            int original_num = num;
            int maxi = 0;
            int mini = 9;
            while (num > 0) {
                int dig = num % 10;
                num /= 10;
                if (dig > maxi) maxi = dig;
                if (dig < mini) mini = dig;
            }
            int current_range = maxi - mini;
            if (current_range > max_range) {
                max_range = current_range;
                sum = original_num; 
            } 
            else if (current_range == max_range) {
                sum += original_num;
            }
        }
        return sum;
    }
};