class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<Status> statuses(numCourses, kUnknown);
        for (auto& prerequisite : prerequisites) {
            adjList[prerequisite.second].push_back(prerequisite.first);
        }
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (statuses[i] == kUnknown && dfsCycle(adjList, statuses, result, i)) {
                return vector<int>();
            }
        }
        return vector<int>(result.rbegin(), result.rend());
    }
private:
    //Status一定要写在dfs前面，否则编译通不过，有点奇怪
    //同一个class里面不是应该不需要提前声明也行的吗
    enum Status {
        kUnknown,
        kDiscovered,
        kVisited,
    };
    //if found cycle, return true;
    //else return false
    bool dfsCycle(vector<vector<int>>& adjList, vector<Status>& statuses, vector<int>& result, int current) {
        statuses[current] = kDiscovered;
        for (int neighbor : adjList[current]) {
            if (statuses[neighbor] == kDiscovered) {
                return true;
            } else if (statuses[neighbor] == kUnknown && dfsCycle(adjList, statuses, result, neighbor)) {
                return true;
            }
        }
        statuses[current] = kVisited;
        result.push_back(current);
        return false;
    }
};