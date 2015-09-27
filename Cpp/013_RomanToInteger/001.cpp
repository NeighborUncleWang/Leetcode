class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dictionary{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size() - 1 && dictionary[s[i]] < dictionary[s[i + 1]]) {
                result -= 2 * dictionary[s[i]];
            }
            result += dictionary[s[i]];
        }
        return result;
    }
};
