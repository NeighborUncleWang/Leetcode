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
    //这里call的还是自己的pow
    //不会call std::pow()
    //complier会优先选用户定义的函数？
    //在这个pow里即使n<0也会被当成>0对待
    //所以没有必要在调用之前对n取反
    //而且如果n = INT_MIN, -n还是 INT_MIN
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