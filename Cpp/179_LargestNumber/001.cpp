class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> numsStr(n);
        transform(nums.begin(), nums.end(), numsStr.begin(), [](int num) {return to_string(num); });
        sort(numsStr.begin(), numsStr.end(), [](string& lhs, string& rhs) {
            return lhs + rhs > rhs + lhs;
        });
        string result;
        result = accumulate(numsStr.begin(), numsStr.end(), result);
        auto iter = result.find_first_not_of('0');
        if (iter == string::npos) {
            return "0";
        } else {
            return result.substr(iter);
        }
    }
};