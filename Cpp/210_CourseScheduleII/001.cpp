class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph graph(numCourses, prerequisites);
        vector<int> result;
        graph.DFS(result);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    enum Color {
        White,
        Gray,
        Black,
    };
    class Graph {
    private:
        vector<vector<int>> adjacentList;
        vector<Color> colorList;
    public:
        Graph(int numCourses, vector<pair<int, int>>& prerequisites) : adjacentList(numCourses), colorList(numCourses, White) {
            for (auto i : prerequisites) {
                adjacentList[i.second].push_back(i.first);
            }
        }
        void DFS(vector<int>& result) {
            bool hasCycle = false;
            for (auto &i : colorList) {
                i = White;
            }
            for (int i = 0; i < adjacentList.size(); ++i) {
                if (colorList[i] == White) {
                    DFSVisit(i, result, hasCycle);
                }
            }
            if (hasCycle) {
                result.clear();
            }
        }
        void DFSVisit(int i, vector<int>& result, bool& hasCycle) {
            colorList[i] = Gray;
            for (auto j : adjacentList[i]) {
                if (colorList[j] == White) {
                    DFSVisit(j, result, hasCycle);
                } else if (colorList[j] == Gray) {
                    hasCycle = true;
                    return;
                }
            }
            colorList[i] = Black;
            result.push_back(i);
        }
    };
};
