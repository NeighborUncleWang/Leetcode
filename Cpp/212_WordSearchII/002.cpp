struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isWord = false;
};
struct Trie {
    TrieNode* root = new TrieNode();
    void AddString(const string& word) {
        auto current = root;
        for (char ch : word) {
            if (current->children[ch - 'a'] == nullptr) {
                current->children[ch - 'a'] = new TrieNode();
            }
            current = current->children[ch - 'a'];
        }
        current->isWord = true;
    }
    //I think I need to write a destructor for the trie.
};
class Solution {
private:
    Trie trie;
    void dfs(vector<vector<char>>& board, vector<string>& result, string& sequence, 
    int i, int j, int rowSize, int columnSize, vector<vector<bool>>& visited, 
    TrieNode* current, vector<pair<int, int>>& directions) {
        if (current && current->isWord == true) {
            result.push_back(sequence);
            //delete the word from the trie to avoid multiple copies in the result
            current->isWord = false;
            return;
        } else if (current == nullptr || i < 0 || i >= rowSize || j < 0 || j >= columnSize || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        sequence.push_back(board[i][j]);
        for (auto& direction : directions) {
            int ii = i + direction.first;
            int jj = j + direction.second;
            dfs(board, result, sequence, ii, jj, rowSize, columnSize, visited, 
            current->children[board[i][j] - 'a'], directions);
        }
        visited[i][j] = false;
        sequence.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& word : words) {
            trie.AddString(word);
        }
        int rowSize = board.size();
        int columnSize = rowSize == 0 ? 0 : board[0].size();
        string sequence;
        vector<string> result;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        vector<vector<bool>> visited(rowSize, vector<bool>(columnSize, false));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                dfs(board, result, sequence, i, j, rowSize, columnSize, visited, trie.root, directions);
            }
        }
        return result;
    }
};