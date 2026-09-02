class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_ele = *min_element(nums1.begin(), nums1.end());

        if(min_ele % 2 == 1) return true;

        for(int &num : nums1){
            if(num % 2 == 1) return false;
        }
        return true;
    }
};