struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isWord = false;
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        auto current = root;
        for (char ch : word) {
            if (current->children[ch - 'a'] == nullptr) {
                current->children[ch - 'a'] = new TrieNode();
            }
            current = current->children[ch - 'a'];
        }
        current->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word, 0, root);
    }
private:
    bool helper(string& word, int index, TrieNode* current) {
        //这里比较的是current->isWord而不是current->children[x]->isWord
        //所以刚好和index == word.size()对应上，别纠结……
        if (index == word.size() && current && current->isWord == true) {
            return true;
        } else if (index == word.size() || current == nullptr) {
            return false;
        }
        char ch = word[index];
        if (ch == '.') {
            for (auto child : current->children) {
                if (helper(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            return helper(word, index + 1, current->children[ch - 'a']);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");