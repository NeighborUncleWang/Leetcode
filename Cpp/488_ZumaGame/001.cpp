class Solution {
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int res = helper(board, hand);
        return res == MAX_STEP ? -1 : res;
    }
private:
    const int MAX_STEP = 6;
    int helper(string board, string hand) {
        if (board.empty()) return 0;
        if (hand.empty()) return MAX_STEP;
        int res = MAX_STEP;
        for (int i = 0; i < hand.size(); ++i) {
            for (int j = board.find(hand[i], 0); j < board.size(); j = board.find(hand[i], j + 1)) {
                if (j < board.size() - 1 && board[j] == board[j + 1]) {
                    string next_hand = hand.substr(0, i) + hand.substr(i + 1);
                    string next_board = shrink(board.substr(0, j) + board.substr(j + 2));
                    res = min(res, helper(next_board, next_hand) + 1);
                    ++j;//因为board[j] == board[j + 1]
                } else if (i > 0 && hand[i] == hand[i - 1]) {
                    string next_hand = hand.substr(0, i - 1) + hand.substr(i + 1);
                    string next_board = shrink(board.substr(0, j) + board.substr(j + 1));
                    res = min(res, helper(next_board, next_hand) + 2);
                }
            }
        }
        return res;
    }
    string shrink(string board) {
        while (board.size()) {
            int start = 0;
            bool done = true;
            //每次消掉了同色的球之后，还是得从头开始检查是否有能消的球
            for (int i = 0; i <= board.size(); ++i) {
                if (i == board.size() || board[i] != board[start]) {
                    if (i - start >= 3) {
                        board = board.substr(0, start) + board.substr(i);
                        done = false;
                        break;
                    } else {
                        start = i;
                    }
                }
            }
            if (done) break;
        }
        return board;
    }
};