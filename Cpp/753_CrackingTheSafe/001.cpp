class Solution {
public:
    string crackSafe(int n, int k) {
        string ans(n, '0');
        unordered_set<string> visited{ans};
        for (int i = 0; i < pow(k, n); ++i) {
            string pre = ans.substr(ans.size() - n + 1, n - 1);
            for (int j = k - 1; j >= 0; --j) {
                string next = pre + char('0' + j);
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    ans += '0' + j;
                    break;
                }
            }
        }
        return ans;
    }
};
