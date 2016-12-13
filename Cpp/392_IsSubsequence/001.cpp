class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_index = 0;
        for (int t_index = 0; t_index < t.size(); ++t_index) {
            s_index += (s[s_index] == t[t_index]);
        }
        return s_index == s.size();
    }
};