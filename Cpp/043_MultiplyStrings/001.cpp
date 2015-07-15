class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result(num1.size() + num2.size() + 1, '0');//有可能有仅为所以结果多加一位
        for (size_t i = 0; i < num1.size(); ++i) {
            int carry = 0;
            int digit1 = num1[i] - '0';
            for (size_t j = 0; j < num2.size(); ++j) {
                int exist = result[i + j] - '0';
                int digit2 = num2[j] - '0';
                result[i + j] = (digit1 * digit2 + exist + carry) % 10 + '0';
                carry = (digit1 * digit2 + exist + carry) / 10;
            }
            if (carry) {
                result[num2.size() + i] += carry;//这里其实可以用result[j + i + 1] = carry，因为这时候result[i + j + 1]一定为0
            }
        }
        reverse(result.begin(), result.end());
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            ++start;
        }
        return result.substr(start, result.size() - start);
    }
};
