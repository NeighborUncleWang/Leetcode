class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n == 0) {
            return result;
        }
        //this vector will store the position of the queen in each row
        //for example, if queen_position[2] = 3
        //it means the matrix[2][3] has a queen
        vector<int> queen_position;
        SolutionConstructor(n, 0, queen_position, result);
        return result;
    }
private:
    void SolutionConstructor(int n, int row, vector<int>& queen_position, vector<vector<string>>& result) {
        if (n == row) {
            //construct the solution
            vector<string> solution;
            //the sequence stores one line result in current soluton
            string sequence(n, '.');
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (queen_position[i] == j) {
                        sequence[j] = 'Q';
                    } else {
                        sequence[j] = '.';
                    }
                }
                solution.push_back(sequence);
            }
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < n; ++i) {
            queen_position.push_back(i);
            if (IsValid(i, row, queen_position)) {
                SolutionConstructor(n, row + 1, queen_position, result);
            }
            queen_position.pop_back();
        }
    }
    bool IsValid(int position, int row, vector<int>& queen_position) {
        for (int i = 0; i < row; ++i) {
            if (queen_position[i] == position
            || abs(queen_position[i] - position) == row - i) {
                return false;
            }
        }
        return true;
    }
};
