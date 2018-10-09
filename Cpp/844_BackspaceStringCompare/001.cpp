class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1;
        while (i >= 0 || j >= 0) {
            int skipS = 0;
            while (i >= 0) {
                if (S[i] == '#') {
                    ++skipS;
                    --i;
                } else if (skipS > 0) {
                    --skipS;
                    --i;
                } else {
                    break;
                }
            }
            int skipT = 0;
            while (j >= 0) {
                if (T[j] == '#') {
                    ++skipT;
                    --j;
                } else if (skipT > 0) {
                    --skipT;
                    --j;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0 && S[i] != T[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;
            --i;
            --j;
        }
        return true;
    }
};
