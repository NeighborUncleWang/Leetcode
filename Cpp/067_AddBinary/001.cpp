class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string result;
        int sizeA = a.size();
        int sizeB = b.size();
        for (int i = sizeA - 1, j = sizeB - 1; i >= 0 || j >= 0 || carry;) {
            int sum = carry;
            sum += i >= 0 ? a[i--] - '0' : 0;
            sum += j >= 0 ? b[j--] - '0' : 0;
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        return string(result.rbegin(), result.rend());
    }
};