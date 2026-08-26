class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int cnt = 0;
        int left = 0, right = 0;
        int n = s.size();
        string ans = "";
        while(right < n){
            if(s[right] == '1') cnt++;
            while(cnt > k || (left < right && s[left] == '0')){
                if(s[left] == '1'){
                    cnt--;
                }
                left++;
            }

           if(cnt == k){
                string current = s.substr(left, right-left+1);
                if(ans.empty() || current.length() < ans.length() || (current.length()==ans.length() && current < ans)){
                    ans = current;
                }
           }
          right++;
        }
        return ans;
    }
};