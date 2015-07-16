class Solution {
public:
    string getPermutation(int n, int k) {
        string sequence;
        string result;
        if (n == 0)
            return result;
        vector<bool> used(n, false);
        helper(n, k, used, sequence, result);
        return result;
    }
private:
    void helper(int n, int& k, vector<bool>& used, string& sequence, string& result) {
        if (sequence.size() == n) {
            --k;
            if (k == 0) {
                result = sequence;
            }
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (used[i] == false) {
                used[i] = true;
                sequence.push_back(i + 1 + '0');
                helper(n, k, used, sequence, result);
                sequence.pop_back();
                used[i] = false;
            }
        }
    }
};
