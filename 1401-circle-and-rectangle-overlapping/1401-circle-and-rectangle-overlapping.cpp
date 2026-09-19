class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x_i , y_i;
        if(x1 > xCenter) x_i = x1;
        else if(x2 < xCenter) x_i = x2;
        else x_i = xCenter;

        if(y1 > yCenter) y_i = y1;
        else if(y2 < yCenter) y_i = y2;
        else y_i = yCenter;

        return sqrt((x_i - xCenter) * (x_i - xCenter) + (y_i - yCenter) * (y_i - yCenter)) <= radius;
    }
}; 