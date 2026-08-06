class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n-1;
        int water = 0;
        while(low <= high){
            int length = high - low;
            int height_ = min(height[low], height[high]);
            int temp_water = length * height_;
            water = max(water, temp_water);
            if(height[low] < height[high]) low++;
            else high--;
        }
        return water;
    }
};