class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
       long long ans = 0;
       priority_queue<int>pq;
       for(int i=0;i<gifts.size();i++)
       {
            pq.push(gifts[i]);
       }
       while(k>0)
       {
            int x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
            k--;
       }
       while(!pq.empty())
       {
            int x = pq.top();
            pq.pop();
            ans+=x;
       }
       return ans; 
    }
};