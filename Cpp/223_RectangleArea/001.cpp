class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        pair<int, int> horizon1(A, C);
        pair<int, int> horizon2(E, G);
        pair<int, int> vertical1(B, D);
        pair<int, int> vertical2(F, H);
        int sum = getDistance(horizon1) * getDistance(vertical1)
        + getDistance(horizon2) * getDistance(vertical2);
        int deduction = getDistance(merge(horizon1, horizon2)) * getDistance(merge(vertical1, vertical2));
        return sum - deduction;
    }
private:
    pair<int, int> merge(pair<int, int> interval1, pair<int, int> interval2) {
        return pair<int, int>(max(interval1.first, interval2.first), min(interval1.second, interval2.second));
    }
    int getDistance(pair<int, int> interval) {
        if (interval.first >= interval.second) {
            return 0;
        } else {
            return interval.second - interval.first;
        }
    }
};
