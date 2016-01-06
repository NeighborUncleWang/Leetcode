class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secretCount(10, 0);
        vector<int> guessCount(10, 0);
        int A = 0;
        int B = 0;
        for (int i = 0; i < secret.size(); ++i) {
            int g = guess[i] - '0';
            int s = secret[i] - '0';
            if (g == s) {
                ++A;
            } else {
                ++secretCount[s];
                ++guessCount[g];
            }
        }
        for (int i = 0; i < secretCount.size(); ++i) {
            B += min(secretCount[i], guessCount[i]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};