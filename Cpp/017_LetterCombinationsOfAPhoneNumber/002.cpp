class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> hashMap{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        deque<string> result{""};
        for (int i = 0; i < digits.size(); ++i) {
            int currentDigit = digits[i] - '0';
            int size = result.size();
            for (int j = 0; j < size; ++j) {
                for (char ch : hashMap[currentDigit]) {
                    result.push_back(result.front() + ch);
                }
                result.pop_front();
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};