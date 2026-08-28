class Solution {
public:
string result = "";
int n, m;
string mid_char = "";

    bool solve(string &curr, vector<int>& count, string& target, int i, bool greater){
        if(i == m){
            string full = curr + mid_char;
            for(int k = m-1; k >= 0; k--){
                full.push_back(curr[k]);
            }

            if(greater || full > target){
                result = full;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch-'a'] == 0) continue;
            if(!greater && ch < target[i]) continue;

            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater = greater || (ch > target[i]);
            if(solve(curr, count, target, i+1, isGreater)) return true;

            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        n = s.length();
        m = n/2;
        vector<int> freq(26, 0);
        for(char ch : s) freq[ch - 'a']++;

        int odd_count = 0;
        int odd_idx = -1;
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 != 0){
                odd_count++;
                odd_idx = i;
            }
        }

        if((n % 2 == 0 && odd_count > 0) || (n % 2 != 0 && odd_count != 1)) return "";

        if(odd_idx != -1) mid_char = string(1, 'a' + odd_idx);

        vector<int> half_count(26, 0);
        for(int i = 0; i < 26; i++){
            half_count[i] = freq[i]/2;
        }
        string curr = "";
        solve(curr, half_count, target, 0, false);
        return result;
    }
};