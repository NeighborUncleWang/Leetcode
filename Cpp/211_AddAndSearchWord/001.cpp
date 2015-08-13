struct TrieNode {
    bool isWord;
    vector<TrieNode*> next;
    TrieNode(void) : isWord(false), next(26, nullptr) {}
};
class WordDictionary {
public:
    WordDictionary(void) {
        root = new TrieNode;
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (current->next[index] == nullptr) {
                current->next[index] = new TrieNode;
            }
            current = current->next[index];
        }
        current->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int length = word.size();
        return get(word, root, 0, length);
    }
private:
    TrieNode* root;
    bool get(string& word, TrieNode* current, int index, int length) {
        if (current != nullptr && current->isWord == true && index == length) {
            return true;
        } else if (current == nullptr || index == length) {
            return false;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; ++i) {
                auto result = get(word, current->next[i], index + 1, length);
                if (result) {
                    return true;
                }
            }
            return false;
        } else {
            return get(word, current->next[word[index] - 'a'], index + 1, length);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
