class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int wordsSize = words.size();
        vector<int> result;
        if (wordLength * wordsSize > s.size()) {
            return result;
        }
        unordered_map<string, int> needToFind;
        unordered_map<string, int> hasFound;
        for (int i = 0; i < words.size(); ++i) {
            ++needToFind[words[i]];
        }
        for (int i = 0; i < wordLength; ++i) {
            hasFound.clear();
            int windowLeft = i;
            int count = 0;
            for (int windowRight = i; windowRight <= (int)s.size() - wordLength;
            windowRight += wordLength) {
                string currentWord = s.substr(windowRight, wordLength);
                if (needToFind.find(currentWord) != needToFind.end()) {
                    ++hasFound[currentWord];
                    if (hasFound[currentWord] <= needToFind[currentWord]) {
                        ++count;
                    } else {
                        string temp = s.substr(windowLeft, wordLength);
                        while (temp != currentWord) {
                            --hasFound[temp];
                            windowLeft += wordLength;
                            --count;
                            temp = s.substr(windowLeft, wordLength);
                        }
                        --hasFound[temp];
                        windowLeft += wordLength;
                    }
                } else {
                    count = 0;
                    windowLeft = windowRight + wordLength;
                    hasFound.clear();
                }
                if (count == words.size()) {
                    result.push_back(windowLeft);
                    //even if I delete the following code, it can still pass the OJ
                    string temp = s.substr(windowLeft, wordLength);
                    --hasFound[temp];
                    windowLeft += wordLength;
                    --count;
                }
            }
        }
        return result;
    }
};
