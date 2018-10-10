struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(27, nullptr);
    unordered_map<string, int> counts;
};
class AutocompleteSystem {
private:
    string prefix;
    TrieNode* root;
    TrieNode* current;
    int getIndex(char ch) {
        return ch == ' ' ? 26 : ch - 'a';
    }
    void addWord(string& word, int count) {
        auto cur = root;
        for (char ch : word) {
            int idx = getIndex(ch);
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur->children[idx]->counts[word] += count;
            cur = cur->children[idx];
        }
    }
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        current = root;
        for (int i = 0; i < sentences.size(); ++i) {
            addWord(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            addWord(prefix, 1);
            prefix.clear();
            current = root;
            return vector<string>();
        }
        prefix += c;
        if (current == nullptr || (current = current->children[getIndex(c)]) == nullptr) {
            return vector<string>();
        }
        auto comp = [] (auto& lhs, auto& rhs) {
            return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> heap(comp);
        vector<string> res;
        for (auto it : current->counts) {
            heap.emplace(it.second, it.first);
        }
        for (int i = 0; i < 3 && !heap.empty(); ++i) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
