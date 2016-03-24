class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        //这里只能用pointer不能用reference
        //因为reference必须初始化，之后不能再改变值
        unordered_set<string> head, tail, *pHead, *pTail;
        head.insert(beginWord);
        tail.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        int length = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                pHead = &tail;
                pTail = &head;
            } else {
                pHead = &head;
                pTail = &tail;
            }
            unordered_set<string> temp;
            for (string word : *pHead) {
                for (int i = 0; i < word.size(); ++i) {
                    char oldValue = word[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        word[i] = ch;
                        if (pTail->find(word) != pTail->end()) {
                            return length;
                        } else if (wordList.find(word) != wordList.end()) {
                            temp.insert(word);
                            wordList.erase(word);
                        }
                    }
                    word[i] = oldValue;
                }
            }
            *pHead = move(temp);
            ++length;
        }
        return 0;
    }
};