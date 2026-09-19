class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x_i = clamp(xCenter, x1, x2), y_i = clamp(yCenter, y1, y2);
        return sqrt((x_i - xCenter) * (x_i - xCenter) + (y_i - yCenter) * (y_i - yCenter)) <= radius;
    }
}; 