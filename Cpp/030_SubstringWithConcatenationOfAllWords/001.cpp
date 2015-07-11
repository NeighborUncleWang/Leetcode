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
        unordered_map<string, string::size_type> realCount;
        for (string::size_type i = 0; i < wordsLength; ++i) {
            ++expectCount[words[i]];
        }
        for (string::size_type i = 0; i < wordLength; ++i) {
            realCount.clear();//remember to clear the hash map for each new i
            string::size_type left = i;
            string::size_type count = 0;
            for (string::size_type right = i; right < s.size() - wordLength + 1; right += wordLength) {
                auto subString = s.substr(right, wordLength);
                if (expectCount.find(subString) != expectCount.end()) {
                    ++realCount[subString];
                    if (realCount[subString] <= expectCount[subString]) {
                        ++count;
                    } else {
                        while (realCount[subString] > expectCount[subString]) {
                            auto temp = s.substr(left, wordLength);
                            if (temp != subString) {
                                --count;
                            }
                            --realCount[temp];
                            left += wordLength;
                        }
                    }
                } else {
                    realCount.clear();
                    count = 0;
                    //I used to have right += wordLength here. Since the for loop will increase the right, so there is no need to add it here. Otherwise it will skip some possible solution
                    left = right + wordLength;
                }
                if (count == wordsLength) {
                    result.push_back(left);
                    auto temp = s.substr(left, wordLength);
                    --realCount[temp];
                    left += wordLength;
                    --count;
                }
            }
        }
        return result;
    }
};
