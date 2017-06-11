class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //这里只能用pointer不能用reference
        //因为reference必须初始化，之后不能再改变值
        unordered_set<string> word_dict(wordList.begin(), wordList.end());
        if (word_dict.find(endWord) == word_dict.end()) return 0;
        int len = 2;
        unordered_set<string> tail, head, *headp, *tailp;
        head.insert(beginWord);
        tail.insert(endWord);
        unordered_set<string> visited{beginWord, endWord};
        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                headp = &tail;
                tailp = &head;
            } else {
                headp = &head;
                tailp = &tail;
            }
            unordered_set<string> next;
            for (auto s : *headp) {
                for (int i = 0; i < s.size(); ++i) {
                    char temp = s[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        s[i] = ch;
                        if (tailp->find(s) != tailp->end()) {
                            return len;
                        } else if (visited.find(s) == visited.end() && word_dict.find(s) != word_dict.end()) {
                            visited.insert(s);
                            next.insert(s);
                        }
                    }
                    s[i] = temp;
                }
            }
            *headp = move(next);
            ++len;
        }
        return 0;
    }
};