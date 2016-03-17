class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> s2t(256, -1);
        vector<int> t2s(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (s2t[s[i]] != t2s[t[i]]) return false;
            //这里就是把s[i]和t[i]都map到同一个unique的value上(这里是i)
            //这样就可以检查相互的map是否是唯一的
            s2t[s[i]] = i;
            t2s[t[i]] = i;
        }
        return true;
    }
};