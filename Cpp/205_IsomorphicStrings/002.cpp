class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char c{};
        cout << c;
        unordered_map<char, char> mapStoT;
        unordered_map<char, char> mapTtoS;
        for (int i = 0; i < s.size(); ++i) {
            if (mapStoT.find(s[i]) == mapStoT.end() 
            && mapTtoS.find(t[i]) == mapTtoS.end()) {
                mapStoT[s[i]] = t[i];
                mapTtoS[t[i]] = s[i];
            } else {
                if (mapStoT[s[i]] != t[i] || mapTtoS[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
