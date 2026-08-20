class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> ans;
        int last1 = nums[0];
        int last2 = nums[1];
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2; i < n; i++){
            if(last1 > last2){
                arr1.push_back(nums[i]);
                last1 = nums[i];
            }
            else{
                arr2.push_back(nums[i]);
                last2 = nums[i];
            }
        }

        for(auto it : arr1){
            ans.push_back(it);
        }
        for(auto it : arr2){
            ans.push_back(it);
        }
        return ans;
    }
};