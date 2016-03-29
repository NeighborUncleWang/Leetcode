class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        unordered_map<pair<int, int>, int, function<long long(pair<int, int>)>> weights(10,
        [=](pair<int, int> position) { return position.first * n + position.second; });
        unordered_map<pair<int, int>, pair<int, int>, function<long long(pair<int, int>)>> roots(10,
        [=](pair<int, int> position) { return position.first * n + position.second; });
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<int> result;
        int count = 0;
        for (auto& position : positions) {
            roots[position] = position;
            weights[position] = 1;
            ++count;
            for (auto& direction : directions) {
                int ii = position.first + direction.first;
                int jj = position.second + direction.second;
                pair<int, int> newPosition = make_pair(ii, jj);
                if (ii >= 0 && ii < m && jj >= 0 && jj < n
                    && roots.find(newPosition) != roots.end()) {
                    auto leftRoot = getRoot(position, roots);
                    auto rightRoot = getRoot(newPosition, roots);
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
    pair<int, int> getRoot(pair<int, int> position, 
    unordered_map<pair<int, int>, pair<int, int>, function<long long(pair<int, int>)>>& roots) {
        while (position != roots[position]) {
            roots[position] = roots[roots[position]];
            position = roots[position];
        }
        return position;
    }
};