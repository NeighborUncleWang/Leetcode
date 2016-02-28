class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> adjList;
        for (auto& edge : tickets) {
            adjList[edge.first].insert(edge.second);
        }
        vector<string> result;
        dfs(adjList, "JFK", result);
        return vector<string>(result.rbegin(), result.rend());
    }
private:
    void dfs(unordered_map<string, multiset<string>>& adjList, string current, vector<string>& result) {
        while (adjList[current].size()) {
            string next = *adjList[current].begin();
            adjList[current].erase(adjList[current].begin());
            dfs(adjList, next, result);
        }
        result.push_back(current);
    }
};