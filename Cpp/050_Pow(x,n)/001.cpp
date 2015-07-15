class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / pow(x, n);//actually if I use 1 istead of 1.0 I can still pass OJ
        } else {
            return pow(x, n);
        }
    }
private:
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        auto half = pow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};
