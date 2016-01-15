class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        dfs(result, "", num, 0, target, 0, 0);
        return result;
    }
private:
    void dfs(vector<string>& result, string sequence, string& num, 
    int index, int target, long long leftVal, long long leftNum) {
        if (index == num.size() && target == leftVal) {
            result.push_back(sequence);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            string currentNum = num.substr(index, i - index + 1);
            if (i > index && currentNum[0] == '0') continue;
            if (index == 0) {
                dfs(result, currentNum, num, i + 1, target, stoll(currentNum), stoll(currentNum));
            } else {
                long long val = stoll(currentNum);
                dfs(result, sequence + '+' + currentNum, num, i + 1, target,
                leftVal + val, val);
                dfs(result, sequence + '-' + currentNum, num, i + 1, target,
                leftVal - val, -val);
                dfs(result, sequence + '*' + currentNum, num, i + 1, target,
                leftVal - leftNum + val * leftNum, leftNum * val);
            }
        }
    }
};