class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph graph(numCourses, prerequisites);
        vector<int> result;
        graph.BFS(result);
        return result;
    }
private:
    class Graph {
    private:
        int numVertices;
        vector<vector<int>> adjacentList;
        vector<int> inDegree;
    public:
        Graph(int numCourses, vector<pair<int, int>>& prerequisites) : numVertices(numCourses),
        adjacentList(numCourses), inDegree(numCourses) {
            for (auto i : prerequisites) {
                adjacentList[i.second].push_back(i.first);
                ++inDegree[i.first];
            }
        }
        void BFS(vector<int>& result) {
            queue<int> nodesQueue;
            int count = 0;
            for (int i = 0; i < inDegree.size(); ++i) {
                if (inDegree[i] == 0) {
                    nodesQueue.push(i);
                }
            }
            while (!nodesQueue.empty()) {
                auto node = nodesQueue.front();
                nodesQueue.pop();
                ++count;
                result.push_back(node);
                for (auto i : adjacentList[node]) {
                    if (--inDegree[i] == 0) {
                        nodesQueue.push(i);
                    }
                }
            }
            if (count != numVertices) {
                result.clear();
            }
        }
    };
};
