class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> alpha(26, 0);
        int i = 0;
        int max_len = INT_MIN;
        for(int j = 0; j < n; j++){
            alpha[s[j]-'a']++;
            while(alpha[s[j]-'a'] > 2){
                alpha[s[i]-'a']--;
                i++;
            }
            int len = j - i + 1;
            max_len = max(len, max_len);
        }
        return max_len;
    }
};