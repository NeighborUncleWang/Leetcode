class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph graph(numCourses, prerequisites);
        return !graph.DFS();
    }
private:
    //how to write enumerator
    //https://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Enumerator_Names
    enum Color{ 
        White, 
        Gray, 
        Black,
    };
    class Graph{
    private:
        int verticesNumber;
        vector<vector<int>> adjacentList;
        vector<Color> colorList;
    public:
        Graph(int v, vector<pair<int, int>>& prerequisites) : verticesNumber(v), adjacentList(v), colorList(v) {
            for (int i = 0; i < prerequisites.size(); ++i) {
                adjacentList[prerequisites[i].second].push_back(prerequisites[i].first);
            }
        }
        bool DFS(void) {
            bool hasCycle = false;
            for (int i = 0; i < colorList.size(); ++i) {
                colorList[i] = White;
            }
            for (int i = 0; i < adjacentList.size(); ++i) {
                if (colorList[i] == White) {
                    DFSVisit(i, hasCycle);
                }
            }
            return hasCycle;
        }
        void DFSVisit(int index, bool& hasCycle) {
            colorList[index] = Gray;
            //可以用foreach形式 for (w : v)
            for (int i = 0; i < adjacentList[index].size(); ++i) {
                if (colorList[adjacentList[index][i]] == White) {
                    DFSVisit(adjacentList[index][i], hasCycle);
                } else if (colorList[adjacentList[index][i]] == Gray) {
                    hasCycle = true;
                    //这里可以直接return吗？直接return的话这个节点就永远是gray了，不过好像没有关系
                    return;
                }
            }
            colorList[index] = Black;//别忘了设为black，否则就一直是gray了
        }
    };
};
