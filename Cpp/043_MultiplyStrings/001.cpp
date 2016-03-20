class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        //结果的长度一定<= size1 + size2
        //因为9*9=81
        //积的size最多是两个乘数size之和
        string result(size1 + size2, '0');
        for (int i = size1 - 1; i >= 0; --i) {
            for (int j = size2 - 1; j >= 0; --j) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + result[i + j + 1] - '0';
                result[i + j + 1] = sum % 10 + '0';
                result[i + j] += sum / 10;
            }
        }
        auto iter = result.find_first_not_of('0');
        return iter == string::npos ? "0" : result.substr(iter);
    }
};