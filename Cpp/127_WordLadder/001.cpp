class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_dict(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int length = 2;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                for (int j = 0; j < cur.size(); ++j) {
                    char temp = cur[j];
                    //这里即使node没有改变(ch == temp)也没有关系
                    //因为原来node已经被标记成visited了
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        cur[j] = ch;
                        if (visited.find(cur) == visited.end() && word_dict.find(cur) != word_dict.end()) {
                            if (cur == endWord) {
                                return length;
                            }
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[j] = temp;
                }
            }
            ++length;
        }
        return 0;
    }
};