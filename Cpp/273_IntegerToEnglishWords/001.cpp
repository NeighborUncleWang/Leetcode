class Solution {
public:
    string numberToWords(int num) {
        vector<string> thousands{"", " Thousand", " Million", " Billion"};
        string result;
        for (int i = 0; num > 0; num /= 1000, ++i) {
            //if(num % 1000)这个判断必须有，否则1,000,000会输出One Million Thousand
            if (num % 1000) {
                result = helper(num % 1000) + thousands[i] + result;
            }
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