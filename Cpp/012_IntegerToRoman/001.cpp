class Solution {
public:
    string intToRoman(int num) {
        //I 1
        //V 5
        //X 10
        //L 50
        //C 100
        //D 500
        //M 1,000
        int dividend = 1000;
        vector<int> digits;
        while (dividend != 0) {
            digits.push_back(num / dividend);
            num %= dividend;
            dividend /= 10;
        }
        string result;
        result += digitToRomanChar(digits[0], 'M', ' ', ' ');
        result += digitToRomanChar(digits[1], 'C', 'D', 'M');
        result += digitToRomanChar(digits[2], 'X', 'L', 'C');
        result += digitToRomanChar(digits[3], 'I', 'V', 'X');
        return result;
    }
private:
    string digitToRomanChar(int digit, char one, char five, char ten) {
        string result;
        switch (digit) {
            case 9:
                result = string{one, ten};
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                result += five;
                for (int i = 5; i < digit; ++i) {
                    result += one;
                }
                break;
            case 4:
                result = string{one, five};
                break;
            case 3:
            case 2:
            case 1:
                for (int i = 0; i < digit; ++i) {
                    result += one;
                }
                break;
            default:
                break;
        }
        return result;
    }
};
