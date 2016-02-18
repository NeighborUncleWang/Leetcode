class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> adjList(numCourses, vector<int>());
        for (auto& i : prerequisites) {
            adjList[i.second].push_back(i.first);
        }
        vector<Status> statuses(numCourses, kUnknown);
        for (int i = 0; i < numCourses; ++i) {
            if (statuses[i] == kUnknown && !dfs(adjList, i, statuses, result)) {
                return vector<int>{};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
private:
    //Status一定要写在dfs前面，否则编译通不过，有点奇怪
    //同一个class里面不是应该不需要提前声明也行的吗
    enum Status {
        kUnknown,
        kDiscovered,
        kVisited,
    };
    bool dfs(vector<vector<int>>& adjList, int node, vector<Status>& statuses, vector<int>& result) {
        statuses[node] = kDiscovered;
        for (int i : adjList[node]) {
            if (statuses[i] == kUnknown && !dfs(adjList, i, statuses, result)) {
                return false;
            } else if (statuses[i] == kDiscovered) {
                return false;
            }
        }
        statuses[node] = kVisited;
        result.push_back(node);
        return true;
    }
};