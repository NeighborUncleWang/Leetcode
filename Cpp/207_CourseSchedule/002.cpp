class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph graph(numCourses, prerequisites);
        return graph.BFS();
    }
private:
    class Graph {
    private:
        int verticesNumber;
        vector<vector<int>> adjacentList;
        vector<int> inDegree;
    public:
        Graph(int numCourses, vector<pair<int, int>>& prerequisites) : verticesNumber(numCourses), 
        adjacentList(numCourses), inDegree(numCourses, 0) {
            for (auto i : prerequisites) {
                adjacentList[i.second].push_back(i.first);
                ++inDegree[i.first];
            }
        }
        bool BFS(void) {
            queue<int> nodesQueue;
            int count = 0;
            bool hasCycle = false;
            for (int i = 0; i < inDegree.size(); ++i) {
                if (inDegree[i] == 0) {
                    nodesQueue.push(i);
                }
            }
            while (!nodesQueue.empty()) {
                int node = nodesQueue.front();
                nodesQueue.pop();
                ++count;
                for (auto i : adjacentList[node]) {
                    if (--inDegree[i] == 0) {
                        nodesQueue.push(i);
                    }
                }
            }
            return count == verticesNumber ? true : false;
        }
    };
};
