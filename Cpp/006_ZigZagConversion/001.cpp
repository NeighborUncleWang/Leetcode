class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0) {//actually don't have this testcase
            return string("");
        }
        if (numRows == 1) {
            return s;
        }
        string result;
        int zigzagSize = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.size(); j += zigzagSize) {
                result += s[j];
                if (i != 0 && i != numRows - 1 && zigzagSize - 2 * i + j < s.size()) {
                    result += s[zigzagSize - 2 * i + j];
                }
            } 
        }
        return result;
    }
};
