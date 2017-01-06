class TicTacToe {
private:
    vector<int> rows;
    vector<int> columns;
    int diagonal = 0;
    int anti_diagonal = 0;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : rows(n, 0), columns(n, 0), n(n) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int to_add = player == 1 ? 1 : -1;
        rows[row] += to_add;
        columns[col] += to_add;
        if (row == col) {
            diagonal += to_add;
        }
        if (row + col == n - 1) {
            anti_diagonal += to_add;
        }
        if (abs(rows[row]) == n || abs(columns[col]) == n || abs(diagonal) == n || 
        abs(anti_diagonal) == n) {
            return player;
        } else {
            return 0;
        }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */