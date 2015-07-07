class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) {
            return 0;
        }
        int i = 0;
        bool negative = false;
        int result = 0;
        while (str[i] == ' ') {
            ++i;
        }
        if (i == str.size()) {
            return 0;
        }
        if (str[i] == '-') {
            negative = true;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            if (negative == true && result > -((INT_MIN + str[i] - '0') / 10)) {//learn how to deal with the case when result is INT_MIN
                return INT_MIN;
            } else if (negative == false && result > (INT_MAX - str[i] + '0') / 10) {
                return INT_MAX;
            }
            result = result * 10 + str[i] - '0';
            ++i;
        }
        return negative ? -result : result;
    }
};
