class Solution {
public:
    int myAtoi(string str) {
        auto iter = str.find_first_not_of(' ');
        if (iter == string::npos) {
            return 0;
        }
        bool isNegative = false;
        if (str[iter] == '-' || str[iter] == '+') {
            isNegative = str[iter++] == '-' ? true : false;
        }
        int result = 0;
        for (; iter < str.size() && isdigit(str[iter]); ++iter) {
            //这里一定要INT_MAX - str[iter] + '0'
            //而不是INT_MAX + '0' - str[iter]
            //否则INT_MAX + '0'会返回一个负数
            //那结果就出错了
            //但是转念一想也没事，因为一旦INT_MAX + '0'变成负数了
            //INT_MAX + '0' - str[iter]又会变回正数
            if (result > (INT_MAX - str[iter] + '0') / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + str[iter] - '0';
        }
        return isNegative ? -result : result;
    }
};