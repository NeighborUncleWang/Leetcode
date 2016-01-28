class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> result(n + 1, 0);
        result[0] = 1;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = n; j >= 1; --j) {
                //记得在?:两边加（），否则会变成？result[j - 1] : 0 + result[j]
                //或者写成result[j] += s[i - 1] == t[j - 1] ? result[j - 1] : 0;
                //result[j - 1]代表选择当前t[j - 1]作为subsequence中的一个char,
                //result[j]代表舍弃当前t[j - 1]
                result[j] = (s[i - 1] == t[j - 1] ? result[j - 1] : 0) + result[j];
            }
        }
        return result.back();
    }
};
