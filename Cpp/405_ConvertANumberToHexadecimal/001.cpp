class Solution {
public:
    string toHex(int num) {
        string result;
        while (num != 0) {
            int digit = num & 0x0000000f;
            if (digit < 10) {
                result += digit + '0';
            } else {
                result += digit - 10 + 'a';
            }
            num = (num >> 4) & 0x0fffffff;
        }
        return result.empty() ? "0" : string(result.rbegin(), result.rend());
    }
};