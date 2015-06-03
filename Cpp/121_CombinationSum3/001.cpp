class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        DFS(1, k, n);
        return solution;
    }
private:
    vector<vector<int>> solution;
    vector<int> temp;
    void DFS(int i, int k, int n) {
        if (k == 0) {
            if (n == 0) {
                solution.push_back(temp);
                return;
            } else {
                return;
            }
        }
        for (int j = i; j < 10; ++j) {
            if (n - j < 0) { return; }
            temp.push_back(j);
            DFS(j + 1, k - 1, n - j);
            temp.pop_back();
        }
    }
};