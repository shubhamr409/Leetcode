class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int num = 1;
        int i = 0;
        while(candies > 0){
            int give = min(candies, num);
            ans[i] += give;
            candies -= give;
            num++;
            i = (i+1) % num_people;
        }
        return ans;
    }
};