class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> currentLevel;
        unordered_set<string> nextLevel;
        dict.insert(end);
        currentLevel.insert(start);
        unordered_map<string, vector<string>> parentMap;
        bool foundPath = false;
        while (!currentLevel.empty()) {
            //这里必须每一个level结束时一次性清除这个level的所有node
            for (const string& str : currentLevel) {
                dict.erase(str);
            }
            for (const string& word : currentLevel) {
                string newWord = word;
                for (int i = 0; i < newWord.size(); ++i) {
                    char temp = newWord[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (dict.find(newWord) != dict.end()) {
                            if (newWord == end) {
                                foundPath = true;
                            }
                            nextLevel.insert(newWord);
                            //这里之所以是parentMap[newWord].push_back(word)
                            //而不是partentMap[word].push_back(newWord)是为了
                            //后面构造path的时候能从确保能到达end的path从后往前往start构造
                            //如果从start往end构造的话会造成前期不知道哪条路径能到达end
                            parentMap[newWord].push_back(word);
                        }
                    }
                    newWord[i] = temp;
                }
            }
            currentLevel.clear();
            swap(nextLevel, currentLevel);
        }
        vector<vector<string>> result;
        vector<string> sequence;
        if (foundPath) {
            //这里我们先push_back(end) 而不是start,因为我们是反着构造path的
            list<string> sequence;
            getPath(end, start, parentMap, sequence, result);
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