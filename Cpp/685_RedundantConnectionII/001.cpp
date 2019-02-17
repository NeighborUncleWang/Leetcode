class Solution {
private:
    int getRoots(vector<int>& roots, int node) {
        while (node != roots[node]) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> roots(n + 1, 0), candidateA, candidateB;
        for (auto& edge : edges) {
            if (roots[edge[1]] != 0) {
                //one candidate is the previous edge that has edge[1] as endpoint
                candidateA = vector<int>{roots[edge[1]], edge[1]};
                //another candidate is current edge
                candidateB = edge;
                // mark the edge as invalid
                edge[1] = 0;
            } else {
                roots[edge[1]] = edge[0];
            }
        }
        iota(roots.begin() + 1, roots.end(), 1);
        for (auto& edge : edges) {
            //invalid edge, skip
            if (edge[1] == 0) continue;
            int lhs = getRoots(roots, edge[0]);
            // found cycle
            // if the root of edge[0] is edge[1]
            // it means there is a path from edge[1] to edge[0]
            // then another directed edge from edge[0] to edge[1]
            // will form a cycle
            if (lhs == edge[1]) {
                return candidateA.empty() ? edge : candidateA;
            }
            int rhs = getRoots(roots, edge[1]);
            // if not found cycle, we do union
            // here it must be roots[rhs] instead of lhs
            // because this is a directed graph
            roots[rhs] = lhs;
        }
        return candidateB;
    }
};
