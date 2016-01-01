class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> sequence;
        helper(2, n, sequence, result);
        return result;
    }
private:
    void helper(int lastNumber, int n, vector<int>& sequence, vector<vector<int>>& result) {
        if (n == 1) {
            if (sequence.size() > 1) {
                result.push_back(sequence);
            }
            return;
        }
        for (int i = lastNumber; i <= n; ++i) {
            if (n % i == 0) {
                sequence.push_back(i);
                helper(i, n / i, sequence, result);
                sequence.pop_back();
            }
        }
    }
};