class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for (char ch : num) {
            while (!result.empty() && k > 0 && ch < result.back()) {
                result.pop_back();
                --k;
            }
            result.push_back(ch);
        }
        auto it = result.find_first_not_of('0');
        int size = result.size();
        //最后有可能k>0,比如每一位数从左往右单调不递减:1123,那么就减去最后的k位
        return it == string::npos || size == k ? "0" : result.substr(it, size - k);
    }
};