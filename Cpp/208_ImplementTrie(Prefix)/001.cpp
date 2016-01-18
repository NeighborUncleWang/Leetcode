struct TrieNode {
    //存成TrieNode*形式可以直接通过next[index] == nullptr
    //来判断next[index]是否已经初始化，否则存成vector<TrieNode>形式
    //的话不好判断next[index]是否已经初始化

    //能否在declare时直接初始化类成员，即写成vector<TrieNode*> next(26, nullptr)形式？
    //还是所有对象都要在构造函数中初始化？ 可以，不过只能用 = 和 {}， 不能直接用()初始化vector
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isWord = false;
    // Initialize your data structure here.
    TrieNode() {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto current = root;
        for (char ch : word) {
            if (current->children[ch - 'a'] == nullptr) {
                current->children[ch - 'a'] = new TrieNode();
            }
            current = current->children[ch - 'a'];
        }
        current->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto p = find(word);
        return p && p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* find(string& s) {
        auto current = root;
        for (char ch : s) {
            if (current->children[ch - 'a'] == nullptr) {
                return nullptr;
            }
            current = current->children[ch - 'a'];
        }
        return current;
    }
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");