class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string solution;
        if (s.size() == 0) {
            return result;
        }
        helper(s, 0, 0, solution, result);
        return result;
    }
private:
    void helper(string& s, int startIndex, int segment, string solution, vector<string>& result) {
        if (segment == 4 && startIndex == s.size()) {
            result.push_back(solution);
            return;
        } else if (segment == 4 || startIndex >= s.size()) {
            return;
        }
        for (int i = 1; i <= 3 && startIndex + i <= s.size(); ++i) {
            auto subString = s.substr(startIndex, i);
            if (isValidNums(subString)) {
                if (segment == 0) {
					//we didn't push and pop the solution mannually, we rely on the stack to maitain the field for us
                    helper(s, startIndex + i, segment + 1, solution + subString, result);
                } else {
                    helper(s, startIndex + i, segment + 1, solution + '.' + subString, result);
                }
            }
        }
    }
    bool isValidNums(string& subString) {
        auto number = stoi(subString);
		//we should test subString.size() > 1 instead of number > 0, since subString may be "00"
        if (subString[0] == '0' && subString.size() > 1) {
            return false;
        }
        if (number >= 0 && number <= 255) {
            return true;
        } else {
            return false;
        }
    }
};
