class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        unordered_map<string, int> hashMap;
        int row = picture.size(), col = row ? picture[0].size() : 0;
        vector<int> cols(col, 0);
        for (int i = 0; i < row; ++i) {
            string key;
            int rowCount = 0;
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    ++cols[j];
                    ++rowCount;
                }
                key += picture[i][j];
            }
            if (rowCount != N) key = "";
            ++hashMap[key];
        }
        int res = 0;
        for (auto& it : hashMap) {
            if (it.first != "" && it.second == N) {
                for (int j = 0; j < it.first.size(); ++j) {
                    if (it.first[j] == 'B' && cols[j] == N) {
                        res += N;
                        cout << j << endl;
                    }
                }
            }
        }
        return res;
    }
};