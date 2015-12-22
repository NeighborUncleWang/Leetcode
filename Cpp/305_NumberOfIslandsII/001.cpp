class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        Union_Find islands(n);
        vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<int> result;
        for (auto& position : positions) {
            islands.add(position);
            for (auto& direction : directions) {
                int newRowPosition = position.first + direction[0];
                int newColumnPosition = position.second + direction[1];
                //下面这行检查position是否valid必须有
                //m=n=3, positions=[[0,1],[1,2],[2,1],[1,0],[0,2],[0,0],[1,1]]
                //这个case过不去,因为当position=[0,2],direction=[0,1]时,[0,3]这个invalid position
                //的index和[1,0]这个valid position的index一样,所以islands.contains返回true
                //这会导致bug
                if (newRowPosition < 0 || newRowPosition >= m
                    || newColumnPosition < 0 || newColumnPosition >= n) continue;
                auto newPosition = make_pair(newRowPosition, newColumnPosition);
                if (islands.contains(newPosition)) {
                    islands.unite(position, newPosition);
                }
            }
            result.push_back(islands.length());
        }
        return result;
    }
private:
    class Union_Find {
    private:
        unordered_map<long long, long long> id;
        unordered_map<long long, int> size;
        int count;
        int columnSize;
    public:
        Union_Find(int columnSize) {
            this->count = 0;
            this->columnSize = columnSize;
        }
        long long getIndex(pair<int, int> position) {
            return position.first * columnSize + position.second;
        }
        int length() {
            return count;
        }
        void add(const pair<int, int>& position) {
            int index = getIndex(position);
            id[index] = index;
            size[index] = 1;
            ++count;
        }
        bool contains(pair<int, int> position) {
            long long index = getIndex(position);
            return id.find(index) != id.end();
        }
        long long root(const pair<int, int>& position) {
            long long index = getIndex(position);
            while (id[index] != index) {
                id[index] = id[id[index]];
                index = id[index];
            }
            return index;
        }
        void unite(pair<int, int> lhs, pair<int, int> rhs) {
            long long leftRoot = root(lhs);
            long long rightRoot = root(rhs);
            if (leftRoot == rightRoot) return;
            if (size[leftRoot] < size[rightRoot]) {
                id[leftRoot] = rightRoot;
                size[rightRoot] += size[leftRoot];
            } else {
                id[rightRoot] = leftRoot;
                size[leftRoot] += size[rightRoot];
            }
            --count;
        }
    };
};