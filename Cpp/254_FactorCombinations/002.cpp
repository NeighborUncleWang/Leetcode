class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> sequence;
        helper(result, sequence, n, 2);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int> sequence, int n, int lowBound) {
        for (int i = lowBound; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                sequence.push_back(i);
                helper(result, sequence, n / i, i);
                sequence.push_back(n / i);
                result.push_back(sequence);
            }
        }
    }
};