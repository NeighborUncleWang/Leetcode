class Solution {
private:
    int GCD(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        return z == 0 || z % GCD(x, y) == 0;
    }
};