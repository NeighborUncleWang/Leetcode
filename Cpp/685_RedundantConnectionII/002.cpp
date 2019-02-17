class Solution {
private:
    void dfs(int current, vector<vector<int>>& adjList, vector<int>& parents,
        vector<int>& status, unordered_set<int>& loop) {
        status[current] = 1;
        for (int neighbor : adjList[current]) {
            // found a loop
            if (status[neighbor] == 1) {
                loop.insert(neighbor);
                while (parents[current] != current) {
                    loop.insert(current);
                    current = parents[current];
                }
                return;
            } else if (status[neighbor] == 0) {
                parents[neighbor] = current;
                dfs(neighbor, adjList, parents, status, loop);
            }
        }
        status[current] = 2;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> roots(n + 1, 0), candidateA, candidateB;
        int nodeWithTwoParents = 0;
        for (auto& edge : edges) {
            if (roots[edge[1]] != 0) {
                //one candidate is the previous edge that has edge[1] as endpoint
                candidateA = vector<int>{roots[edge[1]], edge[1]};
                //another candidate is current edge
                candidateB = edge;
                // mark the edge as invalid
                edge[1] = 0;
                nodeWithTwoParents = edge[1];
            } else {
                roots[edge[1]] = edge[0];
            }
        }
        vector<vector<int>> adjList(n + 1);
        vector<int> parents(n + 1, 0), status(n + 1, 0);
        unordered_set<int> loop;
        for (auto& edge : edges) {
            //invalid edge, skip
            if (edge[1] == 0) continue;
            adjList[edge[0]].push_back(edge[1]);
        }
        for (int i = 1; i <= n; ++i) {
            // not visited
            if (status[i] == 0) {
                dfs(i, adjList, parents, status, loop);
            }
        }
        if (loop.empty()) {
            return candidateB;
        } else if (!candidateA.empty()) {
            return candidateA;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (loop.find(edges[i][0]) != loop.end() && loop.find(edges[i][1]) != loop.end()) {
                return edges[i];
            }
        }
        return candidateB;
    }
};
