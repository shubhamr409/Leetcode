class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(num < 10){
                if(num == i) return i;
                else continue;
            }
            else{
                int sum = 0;
                while(num){
                    int dig = num % 10;
                    num /= 10;
                    sum += dig;
                }
                if(sum == i) return i;
                else continue;
            }
        }
        return -1;
    }
};