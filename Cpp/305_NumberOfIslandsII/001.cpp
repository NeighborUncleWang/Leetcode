class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<long long> roots(m * n, -1);
        vector<int> weights(m * n, 0);
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        vector<int> result;
        for (auto& position : positions) {
            long long index = position.first * n + position.second;
            roots[index] = index;
            weights[index] = 1;
            ++count;
            for (auto& direction : directions) {
                int ii = position.first + direction.first;
                int jj = position.second + direction.second;
                long long newIndex = ii * n + jj;
                if (ii >= 0 && ii < m && jj >= 0 && jj < n && roots[newIndex] != -1) {
                    long long leftRoot = getRoot(index, roots);
                    long long rightRoot = getRoot(newIndex, roots);
                    if (leftRoot != rightRoot) {
                        if (weights[leftRoot] < weights[rightRoot]) {
                            roots[leftRoot] = rightRoot;
                            weights[rightRoot] += weights[leftRoot];
                        } else {
                            roots[rightRoot] = leftRoot;
                            weights[leftRoot] += weights[rightRoot];
                        }
                        --count;
                    }
                }
            }
            result.push_back(count);
        }
        return result;
    }
private:
    long long getRoot(long long index, vector<long long>& roots) {
        while (index != roots[index]) {
            roots[index] = roots[roots[index]];
            index = roots[index];
        }
        return index;
    }
};