class Solution {
public:
    int totalNQueens(int n) {
        vector<int> positionForRow;
        int result = 0;
        helper(n, 0, positionForRow, result);
        return result;
    }
private:
    void helper(int n, int row, vector<int>& positionForRow, int& result) {
        if (row == n) {//construct the solution
            ++result;
            return;//never forget to add return!!!
        }
        for (int i = 0; i < n; ++i) {
            positionForRow.push_back(i);
            if (isValid(row, positionForRow)) {
                helper(n, row + 1, positionForRow, result);
            }
            positionForRow.pop_back();
        }
    }
    bool isValid(int row, vector<int>& positionForRow) {
        for (int i = 0; i < row; ++i) {
            if (positionForRow[i] == positionForRow[row]
            || abs(positionForRow[i] - positionForRow[row]) == row - i) {
                return false;
            }
        }
        return true;
    }
};
