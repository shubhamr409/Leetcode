class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int size = upper - lower + 1;    
        vector<bool> marked(size, 0);
        for (int x : nums) {
            if (x >= lower && x <= upper) {
                marked[x - lower] = true;
            }
        }

        vector<vector<int>> disappeared;
        int curr_lower;
        int curr_upper;
        for(int i = 0; i < size; i++){
            if(marked[i] == 0){
                curr_lower = i+lower;
                int j = i;
                while(j < size && marked[j] == 0) j++;
                curr_upper = (j-1) + lower;
                disappeared.push_back({curr_lower, curr_upper});
                i = j-1;
            } 
        }
        return disappeared;
    }
};