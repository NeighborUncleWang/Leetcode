class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() < T.size()) return "";
        int minLeft = 0, minRight = INT_MAX, minLen = S.size();
        for (int i = 0; i <= S.size() - T.size(); ++i) {
            if (S[i] == T[0]) {
                int right = find(S, i, min(i + minRight - minLeft, S.size()), T);
                if (right != -1 && right - i < minRight - minLeft) {
                    minLeft = i;
                    minRight = right;
                }
            }
        }
        return minRight == INT_MAX ? "" : S.substring(minLeft, minRight - minLeft);
    }
private:
    int find(const string& S, int left, int right, const string& T) {
        int i = 0;
        for ( ; i < T.size() && left < right; ++left) {
            if (S[left] == T[i]) {
                ++i;
            }
        }
        return i == T.size() ? left : -1;
    }
};
