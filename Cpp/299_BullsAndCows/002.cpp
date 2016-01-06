class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count(10, 0);
        int A = 0;
        int B = 0;
        for (int i = 0; i < secret.size(); ++i) {
            int g = guess[i] - '0';
            int s = secret[i] - '0';
            if (g == s) {
                ++A;
            } else {
                if (count[g] < 0) {
                    ++B;
                }
                if (count[s] > 0) {
                    ++B;
                }
                ++count[g];
                --count[s];
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};