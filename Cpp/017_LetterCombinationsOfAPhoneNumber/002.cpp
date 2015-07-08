class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mappingTable = {"", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        result.push_back("");
        for (string::size_type i = 0; i < digits.size(); ++i) {
            int digit = digits[i] - '0';
            vector<string> temp;
            for (string::size_type j = 0; j < mappingTable[digit].size(); ++j) {
                for (vector<string>::size_type k = 0; k < result.size(); ++k) {
                    temp.push_back(result[k] + mappingTable[digit][j]);//don't use string::append, this will alter the element in result, use operator +, this operator can take one string and one char
                }
            }
            result = temp;
        }
        return result;
    }
};
