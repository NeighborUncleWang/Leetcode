class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string result;
        if (numerator < 0 ^ denominator < 0) {
            result.append(1, '-');
        }
        //不要直接用 long long d = abs(denominator),因为abs(denominator) == -denominator;
        //当denominator = INT_MIN时,-INT_MIN == INT_MIN,所以最后d依旧是INT_MIN
        //这个好像是唯一的处理方法，用unsigned long long d = denominator
        //会使d = 0xFFFF_FFFF_8000_0000(denominator = INT_MIN)
        //n = 0xFFFF_FFFF_FFFF_FFFF(numerator = - 1)
        //当signed类型向unsigned类型转化时，这个变量的bit
        //pattern（二进制补码表示形式）保持不变，
        //如果目标类型长度比当前类型长（比如unsigned long long int VS
        //int），那么就会用符号位补齐高32位。
        //然后再将其当成一个正数来看，所以还是不对。
        long long n = numerator;
        long long d = denominator;
        n = abs(n);
        d = abs(d);
        result += to_string(n / d);
        if (n % d == 0) {
            return result;
        }
        result += '.';
        unordered_map<int, int> hashMap;
        //seems remainder is a reserved word for a function in cmath
        //remainder必须是long long类型,否则当denominator是INT_MIN时会出错
        for (long long remainder = n % d; remainder != 0; remainder %= d) {
            if (hashMap.find(remainder) != hashMap.end()) {
                result.insert(hashMap[remainder], 1, '(');
                result += ')';
                return result;
            } else {
                hashMap[remainder] = result.size();
                remainder *= 10;
                result += to_string(remainder / d);
            }
        }
        return result;
    }
};
