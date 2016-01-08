class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjacentList(n);
        for (auto& edge : edges) {
            adjacentList[edge.first].push_back(edge.second);
            adjacentList[edge.second].push_back(edge.first);
        }
        int count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                ++count;
                dfs(i, adjacentList, visited);
            }
        }
        return count;
    }
private:
    void dfs(int index, vector<vector<int>>& adjacentList, vector<bool>& visited) {
        //必须在这里就把visited[index]设为true
        //visited其实相当于!unkown
        //如果dfs的最后设成true会出现死循环
        //比如5,[[0,1],[1,2],[3,4]] case
        visited[index] = true;
        for (int neighbor : adjacentList[index]) {
            if (visited[neighbor] == false) {
                dfs(neighbor, adjacentList, visited);
            }
        }
    }
};