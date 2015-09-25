class Solution {
public:
    int myAtoi(string str) {
        int i = str.find_first_not_of(' ');
        if (i == string::npos) {
            return 0;
        }
        bool negative = false;
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            ++i;
            negative = true;
        }
        int result = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            if (result > (INT_MAX - str[i] + '0') / 10) {
                if (negative) {
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            }
            result = result * 10 + str[i] - '0';
            ++i;
        }
        return negative ? -result : result;
    }
};
