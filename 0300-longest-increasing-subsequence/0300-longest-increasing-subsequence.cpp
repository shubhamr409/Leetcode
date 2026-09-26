class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> sub;
        sub.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]> sub[sub.size()-1])sub.push_back(nums[i]);
            else if(nums[i] == sub[sub.size()-1])continue;
            else
            {
                int l=0,r=sub.size()-1;
                int c=0;
                while(l<=r)
                {
                    int m = l + (r-l)/2;
                    if(sub[m] == nums[i])
                    {
                        c=1;break;
                    }
                    else if(sub[m]>nums[i])
                    {
                        r=m-1;
                    }
                    else 
                    {
                        l=m+1;
                    }
                }
                if(c==1)continue;
                if(sub[l] >= nums[i])sub[l]=nums[i];
            }
        }
        return sub.size();
    }
};