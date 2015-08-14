struct TrieNode {
    bool isWord;
    vector<TrieNode*> children;
    TrieNode(void) : isWord(false), children(26) {}
};
class Trie {
public:
    TrieNode* root;
    Trie(void) {
        root = new TrieNode;
    }
    void insert(string word) {
        auto current = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode;
            }
            current = current->children[index];
        }
        current->isWord = true;
    }
    //I think I need to write a destructor for the trie.
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.insert(words[i]);
        }
        int rowSize = board.size();
        vector<string> result;
        if (rowSize == 0) {
            return result;
        }
        int columnSize = board[0].size();
        vector<vector<bool>> visited(rowSize, vector<bool>(columnSize, false));
        string solution;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                DFS(board, visited, i, rowSize, j, columnSize, trie, trie.root, solution, result);
            }
        }
        return result;
    }
private:
    void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int rowSize,
    int column, int columnSize, Trie& trie, TrieNode* current, string solution, vector<string>& result) {
        if (current != nullptr && current->isWord) {
            result.push_back(solution);
            //delete the word from the trie to avoid multiple copies in the result
            current->isWord = false;
            return;
        } else if (current == nullptr || row >= rowSize || row < 0
        || column >= columnSize || column < 0 || visited[row][column]) {
            return;
        }
        visited[row][column] = true;
        int index = board[row][column] - 'a';
        DFS(board, visited, row + 1, rowSize, column, columnSize, trie, current->children[index],
        solution + board[row][column], result);
        DFS(board, visited, row, rowSize, column + 1, columnSize, trie, current->children[index],
        solution + board[row][column], result);
        DFS(board, visited, row - 1, rowSize, column, columnSize, trie, current->children[index],
        solution + board[row][column], result);
        DFS(board, visited, row, rowSize, column - 1, columnSize, trie, current->children[index],
        solution + board[row][column], result);
        visited[row][column] = false;
    }
};
