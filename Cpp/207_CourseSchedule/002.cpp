class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> inDegrees(numCourses, 0);
        for (auto& i : prerequisites) {
            adjList[i.second].push_back(i.first);
            ++inDegrees[i.first];
        }
        queue<int> nodesQueue;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) {
                nodesQueue.push(i);
            }
        }
        int visitedNodes = 0;
        while (!nodesQueue.empty()) {
            int node = nodesQueue.front();
            nodesQueue.pop();
            for (int i : adjList[node]) {
                if (--inDegrees[i] == 0) {
                    nodesQueue.push(i);
                }
            }
            ++visitedNodes;
        }
        return visitedNodes == numCourses;
    }
};