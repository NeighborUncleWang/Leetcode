class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
		//this is to avoid the case that s is already a palindrome
        string l = s + " " + r;
        int k = -1;
        //pattern[0] must be -1
        vector<int> pattern(l.size(), -1);
        for (int i = 1; i < l.size(); ++i) {
            while (k > - 1 && l[k + 1] != l[i]) {
                k = pattern[k];
            }
            if (l[k + 1] == l[i]) {
                ++k;
            }
            pattern[i] = k; 
        }
        //pattern.back() + 1 is the length of the proper suffix and proper prefix
        //pattern.back() is only the index of the proper prefix
        return r.substr(0, r.size() - pattern.back() - 1) + s;
    }
};
