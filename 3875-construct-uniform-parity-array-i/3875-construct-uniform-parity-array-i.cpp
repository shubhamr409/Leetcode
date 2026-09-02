class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> even;
        vector<int> odd;
        for(int num : nums1){
            if(num % 2 == 0) even.push_back(num);
            else odd.push_back(num);
        }
        if(odd.size() == 0 || even.size() == 0) return true;

        int odd_anchor = odd[0];
        for(int j = 0; j< even.size(); j++){
            even[j] = even[j] - odd_anchor;
        }
        return true;
    }
};