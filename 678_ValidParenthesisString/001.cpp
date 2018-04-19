class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char ch : s) {
            low += ch == '(' ? 1 : -1;
            high += ch == ')' ? -1 : 1;
            if (high < 0) {
                return false;
            }
            low = max(0, low);
        }
        return low == 0;
    }
};
