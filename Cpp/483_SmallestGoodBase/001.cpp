class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        for (int m = 2; m <= log(num + 1) / log(2) - 1; ++m) {
            long long k = pow(num, 1.0 / m);
            //这里k必须转换成long double，而且必须写成 (pow(k, m + 1) - 1) / (k - 1) == num
            //不能写成 pow(k, m + 1) - 1 == num * (k - 1),否则精度不够通不过
            //或者老老实实写一个sum然后把所有的多项式加起来和num比较
            if ((unsigned long long)((pow((long double)k, m + 1) - 1) / (k - 1)) == num) {
                return to_string(k);
            }
        }
        return to_string(num - 1);
    }
};