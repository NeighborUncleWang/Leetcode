class Solution {
private:
    struct TrieNode {
        bool is_word = false;
        vector<TrieNode*> children;
        vector<string> starts_with;
        TrieNode() : children(26, nullptr) {}
    };
    struct Trie {
        TrieNode* root = new TrieNode();
        Trie(vector<string>& words) {
            for (string& word : words) {
                auto current = root;
                for (char ch : word) {
                    if (current->children[ch - 'a'] == nullptr) {
                        current->children[ch - 'a'] = new TrieNode();
                    }
                    current->starts_with.push_back(word);
                    current = current->children[ch - 'a'];
                }
                current->is_word = true;
                //其实下面这行可以省掉，因为在dfs生成prefix的时候永远不会把单词的最后一个char加上去
                //["ball","area","lead","lady"]
                //比如对于上面的quare,在找lady的prefix的时候到lad就停止了
                current->starts_with.push_back(word);
            }
        }
        vector<string> GetStartsWith(string& prefix) {
            auto current = root;
            for (char ch : prefix) {
                if (current->children[ch - 'a'] == nullptr) {
                    return vector<string>();
                }
                current = current->children[ch - 'a'];
            }
            return current->starts_with;
        }
    };
    void dfs(vector<vector<string>>& result, vector<string>& square, int index, int n, Trie& trie) {
        if (index == n) {
            result.push_back(square);
            return;
        }
        string prefix;
        for (int j = 0; j < index; ++j) {
            prefix += square[j][index];
        }
        for (string s : trie.GetStartsWith(prefix)) {
            square.push_back(s);
            dfs(result, square, index + 1, n, trie);
            square.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return vector<vector<string>>();
        int n = words[0].size();
        vector<vector<string>> result;
        vector<string> square;
        Trie trie(words);
        dfs(result, square, 0, n, trie);
        return result;
    }
};