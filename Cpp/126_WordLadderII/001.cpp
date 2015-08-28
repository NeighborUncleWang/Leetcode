class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> currentLevel;
        unordered_set<string> nextLevel;
        dict.insert(end);
        currentLevel.insert(start);
        unordered_map<string, vector<string>> parentMap;
        bool foundPath = false;
        while (!currentLevel.empty() && !foundPath) {
            for (auto &i : currentLevel) {
                dict.erase(i);
            }
            for (auto &word : currentLevel) {
                for (int i = 0; i < word.size(); ++i) {
					//这里多次调用构造函数和析构函数，可以优化一下
                    auto newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (newWord == word) {
                            continue;
                        }
                        if (dict.find(newWord) != dict.end()) {
                            if (newWord == end) {
                                foundPath = true;
                            }
                            nextLevel.insert(newWord);
							//这里之所以是parentMap[newWord].push_back(word)
							//而不是partentMap[word].push_back(newWord)是为了
							//后面构造path的时候能从确保能到达end的path从后往前往start构造
							//如果从start往end构造的话会造成前期不知道哪条路径能到达end
							//导致多出运行时间，这里说的都是从start往end搜的情况
							//其实可以从end往start搜这样后面构造path时就不用reverse两次了
							//这个后面再写了NND，今天太晚了，终于搞定了
                            parentMap[newWord].push_back(word);
                        }
                    }
                }
            }
            currentLevel.clear();
            swap(nextLevel, currentLevel);
        }
        vector<vector<string>> result;
        vector<string> sequence;
        if (foundPath) {
			//这里我们先push_back(end) 而不是start,因为我们是反着构造path的
            vector<string> sequence(1, end);
            getPath(end, start, parentMap, sequence, result);
            return result;
        } else {
            return result;
        }
    }
private:
    void getPath(const string& current, const string& start, unordered_map<string, vector<string>>& parentMap, 
    vector<string>& sequence, vector<vector<string>>& result) {
        if (current == start) {
            reverse(sequence.begin(), sequence.end());
            result.push_back(sequence);
            reverse(sequence.begin(), sequence.end());
            return;
        }
        for (auto &i : parentMap[current]) {
            sequence.push_back(i);
            getPath(i, start, parentMap, sequence, result);
            sequence.pop_back();
        }
    }
};
