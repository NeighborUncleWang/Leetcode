class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows);
        for (int i = 0; i < s.size();) {
            for (int index = 0; index < numRows && i < s.size(); ++index) {
                strs[index].push_back(s[i++]);
            }
            for (int index = numRows - 2; index >= 1 && i < s.size(); --index) {
                strs[index].push_back(s[i++]);
            }
        }
        string result;
        for (string& str : strs) {
            result += move(str);
        }
        return result;
    }
};