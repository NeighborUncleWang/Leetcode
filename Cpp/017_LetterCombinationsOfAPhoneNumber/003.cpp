class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> mappingTable = {"", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result{""};
        for (char digit : digits) {
            vector<string> temp;
            for (char ch : mappingTable[digit - '0']) {
                for (string& s : result) {
                    //don't use string::append, this will alter the element in result, 
                    //use operator +, this operator can take one string and one char
                    temp.push_back(s + ch);
                }
            }
            result = move(temp);
        }
        return result;
    }
};