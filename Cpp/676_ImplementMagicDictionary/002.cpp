class MagicDictionary {
private:
    unordered_map<int, vector<string>> map;
    int diff(string& left, string& right) {
        int res = 0;
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                ++res;
            }
        }
        return res;
    }
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto& word : dict) {
            map[word.size()].push_back(word);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (auto& s : map[word.size()]) {
            if (diff(s, word) == 1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
