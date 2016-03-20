class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        int left = max(A, E);
        int right = min(C, G);
        int bottom = max(B, F);
        int top = min(D, H);
        int overlap = 0;
        if (left < right && bottom < top) {
            overlap = (right - left) * (top - bottom);
        }
        return sum - deduction;
    }
};