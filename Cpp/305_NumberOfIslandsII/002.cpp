class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind unionFind(m, n);
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<int> result;
        for (auto& position : positions) {
            unionFind.add(position);
            for (auto& direction : directions) {
                int ii = position.first + direction.first;
                int jj = position.second + direction.second;
                pair<int, int> newPosition = make_pair(ii, jj);
                //下面这行检查position是否valid必须有
                //m=n=3, positions=[[0,1],[1,2],[2,1],[1,0],[0,2],[0,0],[1,1]]
                //这个case过不去,因为当position=[0,2],direction=[0,1]时,[0,3]这个invalid position
                //的index和[1,0]这个valid position的index一样,所以islands.contains返回true
                //这会导致bug
                if (newPosition.first >= 0 && newPosition.first < m && newPosition.second >= 0 && newPosition.seoncd < n 
                && unionFind.roots.find(newPosition) != unionFind.roots.end()) {
                    unionFind.unite(position, newPosition);
                }
            }
            result.push_back(unionFind.count);
        }
        return result;
    }
private:
    struct UnionFind {
        int count;
        unordered_map<pair<int, int>, int, function<long long(pair<int, int>)>> weights;
        unordered_map<pair<int, int>, pair<int, int>, function<long long(pair<int, int>)>> roots;
        int row;
        int column;
        UnionFind(int m, int n) {
            count = 0;
            weights = unordered_map<pair<int, int>, int, function<long long(pair<int, int>)>>(10, 
            [=](pair<int, int> position) { return position.first * n + position.second; });
            roots = unordered_map<pair<int, int>, pair<int, int>, function<long long(pair<int, int>)>>(10, 
            [=](pair<int, int> position) { return position.first * n + position.second; });
            row = m;
            column = n;
        }
        void add(pair<int, int> position) {
            roots[position] = position;
            weights[position] = 1;
            ++count;
        }
        pair<int, int> getRoot(pair<int, int> position) {
            while (position != roots[position]) {
                roots[position] = roots[roots[position]];
                position = roots[position];
            }
            return position;
        }
        void unite(pair<int, int> position1, pair<int, int> position2) {
            auto leftRoot = getRoot(position1);
            auto rightRoot = getRoot(position2);
            if (leftRoot == rightRoot) {
                return;
            }
            if (weights[leftRoot] < weights[rightRoot]) {
                roots[leftRoot] = rightRoot;
                weights[rightRoot] += weights[leftRoot];
            } else {
                roots[rightRoot] = leftRoot;
                weights[leftRoot] += weights[rightRoot];
            }
            --count;
        }
    };
};