class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            int num = 26 - (s[i] - 'a');
            num *= (i+1);
            sum += num;
        }
        return sum;
    }
};