class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        int carry = 0;
        string result(size1 + size2, '0');
        for (int i1 = size1 - 1, i2 = size2 - 1, i = size1 + size2 - 1; i1 >= 0 || i2 >= 0 || carry;) {
            int sum = carry + (i1 >= 0 ? num1[i1--] - '0' : 0) + (i2 >= 0 ? num2[i2--] - '0' : 0);
            carry = sum / 10;
            result[i--] = sum % 10 + '0';
        }
        auto iter = result.find_first_not_of('0');
        return iter == string::npos ? "0" : result.substr(iter); 
    }
};