class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<string> strs(numRows);
        for (int i = 0, index = 0, step = 1; i < s.size(); ++i) {
            strs[index].push_back(s[i]);
            if (index == 0) {
                step = 1;
            } else if (index == numRows - 1) {
                step = -1;
            }
            index += step;
        }
        string result;
        for (string& str : strs) {
            result += move(str);
        }
        return result;
    }
};