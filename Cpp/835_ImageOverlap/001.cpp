struct myhash {
    int operator() (pair<int, int> key) const {
        return key.first * 10 + key.second;
    }
};
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<pair<int, int>> locA, locB;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j]) {
                    locA.emplace_back(i, j);
                }
                if (B[i][j]) {
                    locB.emplace_back(i, j);
                }
            }
        }
        auto hash = [=] (auto key) {
            return key.first * n + key.second;
        };
        unordered_map<pair<int, int>, int, decltype(hash)> count(10, hash);
        //下面是用strcut myhash 初始化 unordered_map的方法
        //其中myhash operator()后面必须加const，不然会出错
        // unordered_map<pair<int, int>, int, myhash> count;
        for (auto& loc1 : locA) {
            for (auto& loc2 : locB) {
                ++count[{loc1.first - loc2.first, loc1.second - loc2.second}];
            }
        }
        int res = 0;
        for (auto& it : count) {
            res = max(res, it.second);
        }
        return res;
    }
};
