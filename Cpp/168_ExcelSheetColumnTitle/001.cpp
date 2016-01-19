class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            //since 'A' corresponding to 1 instead of 0
            //we can first do --n at the beginning of each loop
            //但是我感觉现在的代码更有助于理解
            result.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
