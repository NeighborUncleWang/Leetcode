class Solution {
public:
    string countAndSay(int n) {
        string result;
        if (n == 0) {
            return result;
        }
        result.push_back('1');
        for (int i = 1; i < n; ++i) {
            string newResult;
            int count = 0;
            for (int j = 0; j < result.size(); ++j) {
                ++count;
                if (j < result.size() - 1 && result[j + 1] != result[j]) {
                    newResult.push_back(count + '0');
                    newResult.push_back(result[j]);
                    count = 0;
                }
            }
            newResult.push_back(count + '0');
            newResult.push_back(result.back());
            result = newResult;
        }
        return result;
    }
};
