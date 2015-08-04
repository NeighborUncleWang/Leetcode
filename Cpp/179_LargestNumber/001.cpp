class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator());
        string result;
        for (int i = 0; i < nums.size(); ++i) {
            result += to_string(nums[i]);
        }
        auto start = result.find_first_not_of('0');
        //trim the proceeding 0s
        if (start == string::npos) {
            return "0";
        } else {
            return result.substr(start);
        }
    }
private:
    struct comparator {
        bool operator()(int left, int right) {
            string leftString = to_string(left);
            string rightString = to_string(right);
			//compare two strings instead of two int number to avoid overflow
            return leftString + rightString > rightString + leftString;
        }
    };
};
