class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> result(size1 + size2, 0);
        for (int i = size1 - 1; i >= 0; --i) {
            for (int j = size2 - 1; j >= 0; --j) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string product(size1 + size2, '0');
        transform(result.begin(), result.end(), product.begin(), [](int digit) { return digit + '0'; });
        auto iter = product.find_first_not_of('0');
        return iter == string::npos ? "0" : product.substr(iter);
    }
};