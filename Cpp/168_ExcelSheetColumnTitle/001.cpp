class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            --n;//since 'A' corresponding to 1 instead of 0
            result.push_back(n % 26 + 'A');
            n = n / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
