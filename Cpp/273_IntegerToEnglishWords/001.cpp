class Solution {
public:
    string numberToWords(int num) {
        vector<string> less_than_twenty{"", " One", " Two", " Three", " Four", " Five", 
        " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", 
        " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        vector<string> tens{"", "", " Twenty", " Thirty", " Forty", " Fifty", 
        " Sixty", " Seventy", " Eighty", " Ninety"};
        vector<string> thousands{"", " Thousand", " Million", " Billion"};
        string res;
        for (int i = 0; num > 0; num /= 1000, ++i) {
            //if(num % 1000)这个判断必须有，否则1,000,000会输出One Million Thousand
            if (num % 1000) {
                res = helper(num % 1000, less_than_twenty, tens) + thousands[i] + res;
            }
        }
        return res == "" ? "Zero" : res.substr(1);
    }
private:
    string helper(int num, vector<string>& less_than_twenty, vector<string>& tens) {
        if (num < 20) {
            return less_than_twenty[num];
        } else if (num < 100) {
            return tens[num / 10] + less_than_twenty[num % 10];
        } else {
            return less_than_twenty[num / 100] + " Hundred" + helper(num % 100, less_than_twenty, tens);
        }
    }
};