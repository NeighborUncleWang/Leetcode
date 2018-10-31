class MagicDictionary {
private:
    unordered_set<string> words;
    unordered_map<string, int> neighbors;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto& s : dict) {
            for (int i = 0; i < s.size(); ++i) {
                ++neighbors[s.substr(0, i) + "*" + s.substr(i + 1)];
            }
            words.insert(s);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); ++i) {
            string neighbor = word.substr(0, i) + "*" + word.substr(i + 1);
            if (neighbors[neighbor] > 1 || neighbors[neighbor] == 1 && words.find(word) == words.end()) {
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
