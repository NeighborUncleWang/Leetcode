class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = generate(S);
        string t = generate(T);
        return s == t;
    }
private:
    string generate(const string& s) {
        string res;
        for (char ch : s) {
            if (ch != '#') {
                res += ch;
            } else if (!res.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
};
