class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int wordLength = words[0].size();
        int count = 0;
        int dictSize = words.size();
        if (dictSize * wordLength > n) {
            return vector<int>();
        }
        unordered_map<string, int> toFind;
        unordered_map<string, int> hasFound;
        for (string& s : words) {
            ++toFind[s];
        }
        vector<int> result;
        for (int i = 0; i < wordLength; ++i) {
            int left = i;
            hasFound.clear();
            count = 0;
            for (int right = i; right < n - wordLength + 1; right += wordLength) {
                string currentWord = s.substr(right, wordLength);
                if (toFind.find(currentWord) != toFind.end()) {
                    ++hasFound[currentWord];
                    ++count;
                    while (hasFound[currentWord] > toFind[currentWord]) {
                        string temp = s.substr(left, wordLength);
                        --hasFound[temp];
                        --count;
                        left += wordLength;
                    }
                    //at this point, the substring in [left, right] must be valid
                    if (count == dictSize) {
                        result.push_back(left);
                        //even if I delete the following code, it can still pass the OJ
                        //因为下一次loop会更新right和left
                        --hasFound[s.substr(left, wordLength)];
                        left += wordLength;
                        --count;
                    }
                } else {
                    hasFound.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }
        return result;
    }
};