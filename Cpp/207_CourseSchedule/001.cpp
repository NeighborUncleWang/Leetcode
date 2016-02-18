class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        for (auto& i : prerequisites) {
            adjList[i.second].push_back(i.first);
        }
        vector<Status> statuses(numCourses, kUnknown);
        for (int i = 0; i < numCourses; ++i) {
            if (statuses[i] == kUnknown && !dfs(adjList, statuses, i)) {
                return false;
            }
        }
        return true;
    }
private:
    enum Status {
        kVisited,
        kUnknown,
        kDiscovered,
    };
    bool dfs(vector<vector<int>>& adjList, vector<Status>& statuses, int node) {
        statuses[node] = kDiscovered;
        for (int i : adjList[node]) {
            if (statuses[i] == kDiscovered) {
                return false;
            } else if (statuses[i] == kUnknown && !dfs(adjList, statuses, i)) {
                return false;
            }
        }
        statuses[node] = kVisited;
        return true;
    }
};