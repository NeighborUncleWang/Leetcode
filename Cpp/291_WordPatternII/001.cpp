class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        int n = pattern.size();
        int m = str.size();
        unordered_map<char, string> p2s;
        unordered_set<string> s2p;
        return match(pattern, 0, n, str, 0, m, p2s, s2p);
    }

private:
    bool match(string &pattern, int i, int n, string &str, int j, int m,
               unordered_map<char, string> &p2s, unordered_set<string> &s2p) {
        if (i == n && j == m) {
            return true;
        } else if (i == n || j == m) {
            return false;
        }
        char ch = pattern[i];
        if (p2s.find(ch) != p2s.end()) {
            string chMatch = p2s[ch];
            int length = chMatch.size();
            string word = str.substr(j, length);
            if (word != chMatch) {
                return false;
            } else {
                return match(pattern, i + 1, n, str, j + length, m, p2s, s2p);
            }
        } else {
            for (int k = j; k < m; ++k) {
                string s = str.substr(j, k - j + 1);
                if (s2p.find(s) != s2p.end()) {
                    //这里之所以跳过是因为这里已经保证ch没有match的word
                    //所以一旦有word match就说明这个情况不对
                    //之所以可以用unordered_set而不用unordered_map也是如此
                    //只用判断这个key存不存在就行
                    //不用去管它是否match到ch这个value
                    continue;
                } else {
                    s2p.insert(s);
                    p2s[ch] = s;
                    if (match(pattern, i + 1, n, str, k + 1, m, p2s, s2p)) {
                        return true;
                    }
                    s2p.erase(s);
                    p2s.erase(ch);
                }
            }
            //务必记得加return false
            //如果dfs的函数有返回值的话，一定要记得检查是否都有返回值
            //如果是void dfs()可以没有
            return false;
        }
    }
};