class Solution {
public:
    bool isMatch(string s, string p) {
        int lengthS = s.size();
        int lengthP = p.size();
        vector<bool> previous(lengthP + 1, false);
        vector<bool> current(lengthP + 1, false);
        previous[0] = true;
        for (int j = 1; j <= lengthP; ++j) {
            if (p[j - 1] == '*') {
                previous[j] = previous[j - 2];
            }
        }
        for (int i = 1; i <= lengthS; ++i) {
            for (int j = 1; j <= lengthP; ++j) {
                if (p[j - 1] != '*') {
                    current[j] = previous[j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                } else {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        current[j] = current[j - 2] || previous[j];
                    } else {
                        current[j] = current[j - 2];
                    }
                }
            }
            previous = current;
        }
        return lengthS == 0 ? previous.back() : current.back(); 
    } 
};
