class Solution {
public:
int n;

    bool isPalindrome(string& s , int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        n = s.size();
        if(k == 1) return n;
        vector<vector<int>> t(n+1, vector<int>(n+1));

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(isPalindrome(s, i, j)){
                    int take = 1 + (j+k <=n ? t[j+1][j+k] : 0);
                    int grow = t[i][j+1];
                    int slide = t[i+1][j+1];
                    t[i][j] = max({take, grow, slide});
                }
                int grow = t[i][j+1];
                int slide = t[i+1][j+1];
                t[i][j] = max({t[i][j], grow, slide});
            }
        }
        return t[0][k-1];
    }
};