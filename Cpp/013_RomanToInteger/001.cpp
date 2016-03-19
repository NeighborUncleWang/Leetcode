class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashMap{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            if (i < size - 1 && hashMap[s[i]] < hashMap[s[i + 1]]) {
                result -= hashMap[s[i]];
            } else {
                result += hashMap[s[i]];
            }
        }
        return result;
    }
};