class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> mappingTable = {"", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
        deque<string> result{""};
        for (char digit : digits) {
            int size = result.size();
            for (int i = 0; i < size; ++i) {
                for (char ch : mappingTable[digit - '0']) {
                    result.push_back(result.front() + ch);
                }
                result.pop_front();
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};