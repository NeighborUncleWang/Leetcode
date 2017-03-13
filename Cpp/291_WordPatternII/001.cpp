class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        int m = pattern.size(), n = str.size();
        unordered_map<char, string> p2s;
        //s2p可以只用unordered_set<string>
        //因为不需要检查s2p[word] != ch这一项
        unordered_map<string, char> s2p;
        return match(pattern, 0, m, str, 0, n, p2s, s2p);
    }
private:
    bool match(string& pattern, int i, int m, string& str, int j, int n,
    unordered_map<char, string>& p2s, unordered_map<string, char>& s2p) {
        if (i == m && j == n) {
            return true;
        } else if (i == m || j == n) {
            return false;
        }
        char ch = pattern[i];
        if (p2s.find(ch) == p2s.end()) {
            for (int k = j; k < n; ++k) {
                string word = str.substr(j, k - j + 1);
                if (s2p.find(word) == s2p.end()) {
                    //这里之所以只检查s2p.find(word) == s2p.end()的情况
                    //是因为这里已经保证ch没有match的word
                    //所以一旦有word match就说明这个情况不对
                    //之所以可以用unordered_set而不用unordered_map也是如此
                    //只用判断这个key存不存在就行
                    //不用去管它是否match到ch这个value
                    p2s[ch] = word;
                    s2p[word] = ch;
                    if (match(pattern, i + 1, m, str, k + 1, n, p2s, s2p)) {
                        return true;
                    }
                    p2s.erase(ch);
                    s2p.erase(word);
                }
            }
            //最后记得返回false
            return false;
        } else {
            string word = p2s[ch];
            if (word != str.substr(j, word.size())) {
                return false;
            } else {
                return match(pattern, i + 1, m, str, j + word.size(), n, p2s, s2p);
            }
        }
    } 
};