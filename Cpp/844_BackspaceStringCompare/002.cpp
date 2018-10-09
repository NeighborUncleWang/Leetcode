class Solution {
public:
    bool backspaceCompare(string S, string T) {
        for (int i = S.length() - 1, j = T.length() - 1; i >= 0 || j >= 0;i--, j--){
            for (int skipS = 0; i >= 0 && (skipS || S[i] == '#'); --i) skipS += S[i] == '#' ? 1 : -1;
            for (int skipT = 0; j >= 0 && (skipT || T[j] == '#'); --j) skipT += T[j] == '#' ? 1 : -1;
            if (i >= 0 && j >= 0 && S[i] != T[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;
        }
        return true;
    }
};
