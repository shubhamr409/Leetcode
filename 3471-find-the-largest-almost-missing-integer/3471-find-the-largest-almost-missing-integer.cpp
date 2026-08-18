class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        int max_ele = INT_MIN;
        for(int num : nums){
            mpp[num]++;
            max_ele = max(max_ele, num);
        } 
        if(k == n){
            return max_ele;
        }
        else if(k == 1){
            for (auto it = mpp.rbegin(); it != mpp.rend(); ++it){
                if (it->second == 1){
                    return it->first;
                }
            }
        }
        else if(k > 1 && k < n){
            int ele1 = nums[0];
            int ele2 = nums[n-1];
            if(ele1 > ele2){
                if(mpp[ele1] == 1) return ele1;
                else if(mpp[ele2] == 1) return ele2;
                else return -1;
            }
            else{
                if(mpp[ele2] == 1) return ele2;
                else if(mpp[ele1] == 1) return ele1;
                else return -1;
            }
        }
        return -1;
    }
};