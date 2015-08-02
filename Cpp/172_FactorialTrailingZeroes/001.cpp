class Solution {
public:
    int trailingZeroes(int n) {
		//number of trailing zeroes = floor(n / 5) + floor(n / 25) + floor(n / 125) + ...
        int count = 0;
        while (n > 0) {
            n = n / 5;
            count += n;
        }
        return count;
    }
};
