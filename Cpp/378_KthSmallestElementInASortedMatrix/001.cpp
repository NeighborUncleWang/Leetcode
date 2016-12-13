class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [&matrix](pair<int, int> left, pair<int, int> right) {
            return matrix[left.first][left.second] > matrix[right.first][right.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        for (int j = 0; j < column; ++j) {
            heap.emplace(0, j);
        }
        for (int i = 0; i < k - 1; ++i) {
            auto top = heap.top();
            heap.pop();
            if (++top.first < row) {
                heap.emplace(top.first, top.second);
            }
        }
        return matrix[heap.top().first][heap.top().second];
    }
};