class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //S(M ∪ N) = S(M) + S(N) - S(M ∩ N)
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        //use long to avoid overflow
        int deduction = max((long)min(C, G) - (long)max(A, E), (long)0) * max((long)min(D, H) - (long)max(B, F), (long)0);
        cout << sum << endl;
        cout << deduction << endl;
        return sum - deduction;
    }
};
