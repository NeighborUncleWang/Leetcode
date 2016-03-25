class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_set<string> head, tail, *pHead = nullptr, *pTail = nullptr;
        head.insert(beginWord);
        tail.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        bool foundPath = false;
        unordered_map<string, vector<string>> parentMap;
        bool forward = true;
        while (!head.empty() && !tail.empty() && !foundPath) {
            if (head.size() > tail.size()) {
                pHead = &tail;
                pTail = &head;
                forward = false;
            } else {
                pHead = &head;
                pTail = &tail;
                forward = true;
            }
            unordered_set<string> intermediate;
            for (const string& word : *pHead) {
                string newWord = word;
                for (int i = 0; i < newWord.size(); ++i) {
                    char temp = newWord[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (pTail->find(newWord) != pTail->end()) {
                            foundPath = true;
                            forward ? parentMap[newWord].push_back(word) : parentMap[word].push_back(newWord);
                        } else if (wordList.find(newWord) != wordList.end()) {
                            intermediate.insert(newWord);
                            forward ? parentMap[newWord].push_back(word) : parentMap[word].push_back(newWord);
                        }
                    }
                    newWord[i] = temp;
                }
            }
            for (const string& word : intermediate) {
                wordList.erase(word);
            }
            *pHead = move(intermediate);
        }
        vector<vector<string>> result;
        vector<string> sequence;
        if (foundPath) {
            //这里我们先push_back(end) 而不是start,因为我们是反着构造path的
            list<string> sequence;
            getPath(endWord, beginWord, parentMap, sequence, result);
            return result;
        } else {
            return result;
        }
    }
private:
    void getPath(const string& current, const string& start, unordered_map<string, vector<string>>& parentMap, 
    list<string>& sequence, vector<vector<string>>& result) {
        if (current == start) {
            sequence.push_front(current);
            result.push_back(vector<string>(sequence.begin(), sequence.end()));
            sequence.pop_front();
            return;
        }
        sequence.push_front(current);
        for (string& word : parentMap[current]) {
            getPath(word, start, parentMap, sequence, result);
        }
        sequence.pop_front();
    }
};