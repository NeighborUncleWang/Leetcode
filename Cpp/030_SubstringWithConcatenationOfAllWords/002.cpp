class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        string::size_type wordLength = words[0].size();
        vector<string>::size_type wordsLength = words.size();
        if (s.size() < wordLength * wordsLength) {
            return result;
        }
        unordered_map<string, string::size_type> expectCount;
        for (vector<string>::size_type i = 0; i < words.size(); ++i) {
            ++expectCount[words[i]];
        }
        unordered_map<string, string::size_type> realCount;
        for (string::size_type i = 0; i < s.size() - wordLength * wordsLength + 1; ++i) {
            realCount.clear();
            vector<string>::size_type count = 0;
            for (string::size_type j = i; j < s.size() - wordLength + 1; j += wordLength) {
                string subString = s.substr(j, wordLength);
                if (expectCount.find(subString) != expectCount.end()) {
                    ++realCount[subString];
                    ++count;
                    if (realCount[subString] > expectCount[subString]) {
                        break;
                    }
                } else {
                    break;
                }
                if (count == wordsLength) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};
