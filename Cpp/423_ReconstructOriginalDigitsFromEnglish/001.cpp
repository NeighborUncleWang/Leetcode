class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10, 0);
        for (char ch : s) {
            if (ch == 'z') ++count[0];
            if (ch == 'w') ++count[2];
            if (ch == 'u') ++count[4];
            if (ch == 'x') ++count[6];
            if (ch == 'g') ++count[8];
            if (ch == 'f') ++count[5];//5 - 4
            if (ch == 't') ++count[3];//3 - 2 - 8
            if (ch == 'i') ++count[9];//9 - 5 - 6 - 8
            if (ch == 's') ++count[7];//7 - 6
            if (ch == 'o') ++count[1];//1 - 4 - 2 - 0
        }
        count[5] -= count[4];
        count[3] -= count[2] + count[8];
        count[9] -= count[5] + count[6] + count[8];
        count[7] -= count[6];
        count[1] -= count[4] + count[2] + count[0];
        string result;
        for (int i = 0; i < 10; ++i) {
            result.append(count[i], i + '0');
        }
        return result;
    }
};