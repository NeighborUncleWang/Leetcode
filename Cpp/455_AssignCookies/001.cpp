class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int i = 0;
        for (int j = 0; i < s.size() && j < g.size();++j) {
            if (s[i] >= g[j]) {
                ++i;
            }
        }
        return i;
    }
};