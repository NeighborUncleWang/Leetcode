class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        int count = 0;
        for (auto it = S.rbegin(); it != S.rend(); ++it) {
            if (*it != '-') {
                if (count == K) {
                    result += '-';
                    count = 0;
                }
                result += toupper(*it);
                ++count;
            }
        }
        return string(result.rbegin(), result.rend());
    }
};