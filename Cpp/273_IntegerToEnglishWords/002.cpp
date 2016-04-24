class Solution {
public:
    string numberToWords(int num) {
        vector<string> thousands{"", " Thousand", " Million", " Billion"};
        string result;
        int i = 0;
        while (pow(1000, i) <= num / 1000) {
            ++i;
        }
        int base = pow(1000, i);
        for (; i >= 0; --i) {
            if (num / base) {
                result += helper(num / base) + thousands[i];
            }
            num %= base;
            base /= 1000;
        }
        return result.empty() ? "Zero" : result.substr(1);
    }
private:
    string helper(int num) {
        vector<string> lessThan20{
            "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine",
            " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen",  " Fifteen", " Sixteen", " Seventeen",
            " Eighteen", " Nineteen"
        };
        vector<string> tens{
            "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"
        };
        if (num < 20) {
            return lessThan20[num];
        } else if (num < 100) {
            return tens[num / 10] + lessThan20[num % 10];
        } else {
            return lessThan20[num / 100] + " Hundred" + helper(num % 100);
        }
    }
};