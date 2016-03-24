class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> hashMap;
        int size = words.size();
        for (int i = 0; i < size; ++i) {
            hashMap[words[i]] = i;
        }
        vector<vector<int>> result;
        for (int i = 0; i < size; ++i) {
            string word = words[i];
            int left = 0;
            int right = 0;
            while (left <= right) {
                string temp = word.substr(left, right);
                reverse(temp.begin(), temp.end());
                auto iter = hashMap.find(temp);
                if (iter != hashMap.end() && iter->second != i
                    && isPalindrome(word, left == 0 ? right : 0, left == 0 ? word.size() - 1 : left - 1)) {
                    result.push_back(left == 0 ? vector<int>{i, iter->second} : vector<int>{iter->second, i});
                }
                right < word.size() ? ++right : ++left;
            }

        }
        return result;
    }
private:
    bool isPalindrome(string& word, int start, int end) {
        while (start < end) {
            if (word[start++] != word[end--]) {
                return false;
            }
        }
        return true;
    }
};