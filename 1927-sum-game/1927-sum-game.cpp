class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftKnownSum = 0;
        int rightKnownSum = 0;

        int leftQMarkCount = 0;
        int rightQMarkCount = 0;

        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n/2) leftQMarkCount++;
                else rightQMarkCount++;
            }
            else{
                if(i < n/2){
                    leftKnownSum += num[i] - '0';
                }
                else rightKnownSum += num[i] - '0';
            }
        }
        int totalQMarks = leftQMarkCount + rightQMarkCount;
        if(totalQMarks % 2 == 1) return true;

        int LEFT = 2 * leftKnownSum + 9 * leftQMarkCount;
        int RIGHT = 2 * rightKnownSum + 9 * rightQMarkCount;

        if(LEFT == RIGHT) return false;
        return true;

    }
};