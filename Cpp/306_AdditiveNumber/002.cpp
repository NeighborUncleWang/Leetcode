class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= (n - 1) / 2; ++i) {
            string num1 = num.substr(0, i);
            if (num1[0] == '0' && num1.size() > 1) {
                continue;
            }
            for (int j = 1; n - i - j >= max(i, j); ++j) {
                string num2 = num.substr(i, j);
                if (num2[0] == '0' && num2.size() > 1) {
                    continue;
                }
                if (isValid(num1, num2, num.substr(i + j))) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool isValid(string num1, string num2, string rest) {
        if (addNums(num1, num2) == rest) {
            return true;
        }
        string sum = addNums(num1, num2);
        //rest.find(sum) == 0 checke whether rest starts with sum
        return rest.find(sum) == 0 && isValid(num2, sum, rest.substr(sum.size()));
    }
    string addNums(long long num1, long long num2) {
        return to_string(num1 + num2);
    }
    string addNums(string num1, string num2) {
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        string sum;
        int carry = 0;
        while (i1 >= 0 || i2 >= 0) {
            int digit = (i1 >= 0 ? num1[i1--] - '0' : 0) + (i2 >= 0 ? num2[i2--] - '0' : 0) + carry;
            carry = digit / 10;
            digit %= 10;
            sum.push_back(digit + '0');
        }
        if (carry) {
            sum += '1';
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};