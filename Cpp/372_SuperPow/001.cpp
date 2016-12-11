class Solution {
private:
    const int base = 1337;
    int PowMode(int a, int last_digit) {
        a %= base;
        int result = 1;
        for (int i = 0; i < last_digit; ++i) {
            result = result * a % base;
        }
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return PowMode(superPow(a, b), 10) * PowMode(a, last_digit) % base;
    }
};