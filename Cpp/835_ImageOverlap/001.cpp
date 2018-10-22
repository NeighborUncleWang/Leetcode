class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<int> indicesA, indicesB;
        for (int i = 0; i < n * n; ++i) {
            if (A[i / n][i % n]) {
                indicesA.push_back(i / n * 100 + i % n);
            }
            if (B[i / n][i % n]) {
                indicesB.push_back(i / n * 100 + i % n);
            }
        }
        unordered_map<int, int> count;
        for (int idxA : indicesA) {
            for (int idxB : indicesB) {
                ++count[idxA - idxB];
            }
        }
        int res = 0;
        for (auto it : count) {
            res = max(res, it.second);
        }
        return res;
    }
};
