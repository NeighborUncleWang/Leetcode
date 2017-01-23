class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (auto& transaction : transactions) {
            balance[transaction[0]] -= transaction[2];
            balance[transaction[1]] += transaction[2];
        }
        vector<int> account;
        for (auto& it : balance) {
            if (it.second) {
                account.push_back(it.second);
            }
        }
        int res = INT_MAX;
        helper(account, 0, 0, res);
        return res;
    }
private:
    void helper(vector<int> account, int start, int num, int& res) {
        while (start < account.size() && account[start] == 0) ++start;
        if (start == account.size()) {
            res = min(res, num);
            return;
        }
        for (int i = start + 1; i < account.size(); ++i) {
            if (account[start] < 0 && account[i] > 0 || account[start] > 0 && account[i] < 0) {
                account[i] += account[start];
                helper(account, start + 1, num + 1, res);
                account[i] -= account[start];
            }
        }
    }
};