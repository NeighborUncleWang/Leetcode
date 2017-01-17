class Solution {
public:
    int magicalString(int n) {
        string result = "122";
        bool append_one = true;
        for (int i = 2; result.size() < n; ++i) {
            if (append_one) {
                result.append(result[i] - '0', '1');
            } else {
                result.append(result[i] - '0', '2');
            }
            append_one = !append_one;
        }
        return count(result.begin(), result.begin() + n, '1');
    }
};