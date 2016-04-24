class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adjList;
        //这里的predecessor就相当于以前题目的inDegrees vector(Q207 courseSchedule)
        //因为这道题同一条边可能出现两次(case: ["za","zb","ca","cb"])
        //所以用unordered_set<char>来代替int 值
        //其实也可以把adjList改成unordered_map<char, unordered_multiset<char>>
        unordered_map<char, unordered_set<char>> predecessor;
        unordered_set<char> chars;
        //construct the graph
        for (int i = 0; i < n - 1; ++i) {
            chars.insert(words[i].begin(), words[i].end());
            for (int j = 0; j < words[i].size(); ++j) {
                if (j < words[i + 1].size() && words[i + 1][j] != words[i][j]) {
                    adjList[words[i][j]].insert(words[i + 1][j]);
                    predecessor[words[i + 1][j]].insert(words[i][j]);
                    break;
                }
            }
        }
        chars.insert(words.back().begin(), words.back().end());
        queue<char> nodesQueue;
        for (char ch : chars) {
            if (predecessor.find(ch) == predecessor.end()) {
                nodesQueue.push(ch);
            }
        }
        string result;
        while (!nodesQueue.empty()) {
            char current = nodesQueue.front();
            nodesQueue.pop();
            for (char neighbor : adjList[current]) {
                predecessor[neighbor].erase(current);
                if (predecessor[neighbor].empty()) {
                    nodesQueue.push(neighbor);
                }
            }
            result.push_back(current);
        }
        return result.size() == chars.size() ? result : "";
    }
};