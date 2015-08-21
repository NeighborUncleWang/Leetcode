class Solution {
public:
    bool isMatch(string s, string p) {
        int lengthS = s.size();
        int lengthP = p.size();
        //this block of code is used to speed up the code
        int notStar = count_if(p.begin(), p.end(), [](char c){return c != '*';});
        if (notStar > lengthS) {
            return false;
        }
        vector<bool> previous(lengthP + 1, false);
        vector<bool> current(lengthP + 1, false);
        previous[0] = true;
        for (int i = 1; i <= lengthP; ++i) {
            if (p[i - 1] == '*') {
                previous[i] = previous[i - 1];
            }
        }
        for (int i = 1; i <= lengthS; ++i) {
            for (int j = 1; j <= lengthP; ++j) {
                if (p[j - 1] != '*') {
                    current[j] = previous[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                } else {
                    current[j] = previous[j] || current[j - 1];
                }
            }
            previous = current;
        }
        return lengthS == 0 ? previous.back() : current.back();
    }
};
