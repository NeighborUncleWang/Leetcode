class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= (n - 1) / 2; ++i) {
            if (i > 1 && num[0] == '0') continue;
            string num1 = num.substr(0, i);
            for (int j = 1; n - i - j >= max(i, j); ++j) {
                if (j > 1 && num[i] == '0') continue;
                string num2 = num.substr(i, j);
                if (isValid(num1, num2, i + j, num)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool isValid(string num1, string num2, int start, string& num) {
        string sum = addNums(num1, num2);
        if (sum == num.substr(start)) {
            return true;
        }
        //don't use string::find to check that num.startsWith(sum, start)
        //that equals to strStr problem, will increase the complexity
        return num.substr(start, sum.size()) == sum && isValid(num2, sum, start + sum.size(), num);
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
            sum.push_back(digit % 10 + '0');
        }
        if (carry) {
            sum += '1';
        }
        return string(sum.rbegin(), sum.rend());
    }
};