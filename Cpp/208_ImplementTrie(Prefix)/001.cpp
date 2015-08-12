class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : next(26, nullptr) {
        isWord = false;
    }
    bool isWord;
    //存成TrieNode*形式可以直接通过next[index] == nullptr
    //来判断next[index]是否已经初始化，否则存成vector<TrieNode>形式
    //的话不好判断next[index]是否已经初始化
    vector<TrieNode*> next;
	//能否在declare时直接初始化类成员，即写成vector<TrieNode*> next(26, nullptr)形式？
	//还是所有对象都要在构造函数中初始化？
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (current->next[index] == nullptr) {
                current->next[index] = new TrieNode();
            }
            current = current->next[index];
        }
        current->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size() && current != nullptr; ++i) {
            current = current->next[word[i] - 'a'];
        }
        if (current == nullptr || current->isWord == false) {
            return false;
        } else {
            return true;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* current = root;
        int i = 0;
        for ( ; i < prefix.size() && current != nullptr; ++i) {
            current = current->next[prefix[i] - 'a'];
        }
        if (i < prefix.size() || current == nullptr) {
            return false;
        } else {
            return true;
        }
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
