class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind unionFind(m, n);
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<int> result;
        for (auto& position : positions) {
            int i = position.first;
            int j = position.second;
            unionFind.add(i, j);
            for (auto& direction : directions) {
                int ii = i + direction.first;
                int jj = j + direction.second;
                //下面这行检查position是否valid必须有
                //m=n=3, positions=[[0,1],[1,2],[2,1],[1,0],[0,2],[0,0],[1,1]]
                //这个case过不去,因为当position=[0,2],direction=[0,1]时,[0,3]这个invalid position
                //的index和[1,0]这个valid position的index一样,所以islands.contains返回true
                //这会导致bug
                if (ii >= 0 && ii < m && jj >= 0 && jj < n && unionFind.roots[ii * n + jj] != -1) {
                    unionFind.unite(i, j, ii, jj);
                }
            }
            result.push_back(unionFind.count);
        }
        return result;
    }
private:
    struct UnionFind {
        int count;
        vector<long long> weights;
        vector<long long> roots;
        int row;
        int column;
        UnionFind(int m, int n) {
            count = 0;
            weights = vector<long long>(m * n, 0);
            roots = vector<long long>(m * n, -1);
            row = m;
            column = n;
        }
        long long getIndex(int i, int j) {
            return i * column + j;
        }
        void add(int i, int j) {
            long long index = getIndex(i, j);
            roots[index] = index;
            weights[index] = 1;
            ++count;
        }
        long long getRoot(int i, int j) {
            long long index = getIndex(i, j);
            while (index != roots[index]) {
                roots[index] = roots[roots[index]];
                index = roots[index];
            }
            return index;
        }
        void unite(int row1, int column1, int row2, int column2) {
            long long leftRoot = getRoot(row1, column1);
            long long rightRoot = getRoot(row2, column2);
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