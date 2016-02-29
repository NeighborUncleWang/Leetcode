class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adjList;
        unordered_map<char, Status> statuses;
        //construct the graph
        for (int i = 0; i < n - 1; ++i) {
            for (char ch : words[i]) { 
                statuses[ch] = kUnknown; 
            }
            for (int j = 0; j < words[i].size(); ++j) {
                if (j < words[i + 1].size() && words[i + 1][j] != words[i][j]) {
                    adjList[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
            }
        }
        for (char ch : words.back()) {
            statuses[ch] = kUnknown;
        }
        string result;
        for (auto iter : statuses) {
            if (statuses[iter.first] == kUnknown && dfsCycle(adjList, statuses, iter.first, result)) {
                return "";
            }
        }
        return string(result.rbegin(), result.rend());
    }
private:
    enum Status {
        kUnknown,
        kDiscovered,
        kVisited,
    };
    bool dfsCycle(unordered_map<char, unordered_set<char>>& adjList, unordered_map<char, Status>& statuses, 
    char current, string& result) {
        statuses[current] = kDiscovered;
        for (char neighbor : adjList[current]) {
            //其实可以把下面两个条件归到一起也能通过OJ
            if (statuses[neighbor] == kDiscovered) {
                return true;
            } else if (statuses[neighbor] == kUnknown && dfsCycle(adjList, statuses, neighbor, result)) {
                return true;
            }
        }
        result.push_back(current);
        statuses[current] = kVisited;
        return false;
    }
};