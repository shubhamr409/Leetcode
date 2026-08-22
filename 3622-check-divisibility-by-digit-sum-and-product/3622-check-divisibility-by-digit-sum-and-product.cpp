class Solution {
public:
    bool checkDivisibility(int n) {
        int digSum = 0;
        int digProd = 1;
        int num = n;
        while(num > 0){
            int dig = num % 10;
            num /= 10;
            digSum += dig;
            digProd *= dig;
        }
        digSum += digProd;
        if(n % digSum == 0) return true;
        return false;
    }
};