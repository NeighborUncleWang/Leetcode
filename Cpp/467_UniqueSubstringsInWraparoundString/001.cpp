class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26, 0);
        int max_ends_here = 1;
        for (int i = 0; i < p.size(); ++i) {
            if(i > 0 && (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25)) {
                ++max_ends_here;
            } else {
                max_ends_here = 1;
            }
            count[p[i] - 'a'] = max(count[p[i] - 'a'], max_ends_here);
        }
        return accumulate(count.begin(), count.end(), 0);
    }
};