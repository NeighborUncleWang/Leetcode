class Solution {
public:
    int magicalString(int n) {
        string res = "122";
        for (int i = 2; res.size() < n; ++i) {
            res.append(res[i] - '0', res.back() == '1' ? '2' : '1');
        }
        return count(res.begin(), res.begin() + n, '1');
    }
};