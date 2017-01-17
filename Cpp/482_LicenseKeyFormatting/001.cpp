class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        for (auto it = S.rbegin(); it != S.rend(); ++it) {
            if (*it != '-') {
                if (result.size() % (K + 1) == K) {
                    result += '-';
                }
                result += toupper(*it);
            }
        }
        return string(result.rbegin(), result.rend());
    }
};