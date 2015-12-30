class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> charMap{{'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}, {'0', '0'}};
        int n = num.size();
        for (int left = 0, right = n - 1; left <= right; ++left, --right) {
            if (charMap.find(num[left]) == charMap.end()
            || charMap[num[left]] != num[right]) {
                return false;
            }
        }
        return true;
    }
};