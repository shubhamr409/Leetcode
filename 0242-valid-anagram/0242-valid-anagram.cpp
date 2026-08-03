class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26, 0);
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            vec[c-'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            char c = t[i];
            if(vec[c-'a'] == 0) return false;
            vec[c-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(vec[i] != 0) return false;
        }
        return true;
    }
};