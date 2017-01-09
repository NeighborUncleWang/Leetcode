class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n, head = 1, step = 1;
        while (remaining != 1) {
            if (left || remaining % 2) {
                head += step;
            }
            step *= 2;
            remaining /= 2;
            left = !left;
        }
        return head;
    }
};