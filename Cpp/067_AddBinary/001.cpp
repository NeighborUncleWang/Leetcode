class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i = 0;
        for ( ; i < a.size() && i < b.size(); ++i) {
            int digit = (a[i] - '0' + b[i] - '0' + carry) % 2;
            carry = (a[i] - '0' + b[i] - '0' + carry) / 2;
            result.push_back(digit + '0');
        }
        if (i < a.size()) {
            for ( ; i < a.size(); ++i) {
                int digit = (a[i] - '0' + carry) % 2;
                carry = (a[i] - '0' + carry) / 2;
                result.push_back(digit + '0');
            }
        } else if (i < b.size()) {
            for ( ; i < b.size(); ++i) {
                int digit = (b[i] - '0' + carry) % 2;
                carry = (b[i] - '0' + carry) / 2;
                result.push_back(digit + '0');
            }
        }
        if (carry) {
            result.push_back(carry + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
