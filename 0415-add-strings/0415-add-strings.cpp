class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int n = num1.size()-1;
        int m = num2.size()-1;
        int carry = 0;

        while(n >= 0 || m >= 0 || carry > 0){
            int sum = carry;

            if(n >= 0){
                sum += num1[n]-'0';
                n--;
            }
            if(m >= 0){
                sum += num2[m]-'0';
                m--;
            }
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};