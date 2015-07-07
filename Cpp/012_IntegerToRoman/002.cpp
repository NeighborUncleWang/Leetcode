class Solution {
public:
    string intToRoman(int num) {
        string romanChar = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int dividend = 1000;
        string result;
        for (int i = 6; i >= 0; i -= 2) {
            int digit = num / dividend;
            switch (digit) {
                case 9:
                    result.append(1, romanChar[i]);
                    result.append(1, romanChar[i + 2]);
                    break;
                case 8:
                case 7:
                case 6:
                case 5:
                    result.append(1, romanChar[i + 1]);
                    result.append(digit - 5, romanChar[i]);
                    break;
                case 4:
                    result.append(1, romanChar[i]);
                    result.append(1, romanChar[i + 1]);
                    break;
                case 3:
                case 2:
                case 1:
                    result.append(digit - 0, romanChar[i]);
                    break;
                default:
                    break;
            }
            num = num % dividend;
            dividend /= 10;
        }
        return result;
    }
};
