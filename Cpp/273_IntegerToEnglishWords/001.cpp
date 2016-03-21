class Solution {
public:
    string numberToWords(int num) {
        const static vector<string> thousands{"", " Thousand", " Million", " Billion"};
        int i = 0;
        string words;
        while (num) {
            //这个判断必须有，否则1000,000会输出One Million Thousand
            if (num % 1000) {
                words = helper(num % 1000) + thousands[i] + words;
            }
            ++i;
            num /= 1000;
        }
        return words.size() ? words.substr(1) : "Zero";
    }
private:
    string helper(int num) {
        const static vector<string> lessThan20{
            "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine",
            " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen",  " Fifteen", " Sixteen", " Seventeen",
            " Eighteen", " Nineteen"
        };
        const static vector<string> tens{
            "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"
        };
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return lessThan20[num];
        } else if (num < 100) {
            return tens[num / 10] + lessThan20[num % 10];
        } else {
            return lessThan20[num / 100] + " Hundred" + helper(num % 100);
        }
    }
};