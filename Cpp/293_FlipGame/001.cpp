class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        // 另一种写法
        // for (auto it = s.find("++", 0); it != string::npos; it = s.find("++", it + 1)) {
        //     res.push_back(s.substr(0, it) + "--" + s.substr(it + 2));
        // }
        for (int i = 0; i < (int)s.size() - 1; ++i) {
            if (s[i] == s[i + 1] && s[i] == '+') {
                result.push_back(s.substr(0, i) + "--" + s.substr(i + 2));
            }
        }
        return result;
    }
};