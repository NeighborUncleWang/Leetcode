class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hashMap(256, 0);
        for (char ch : t) {
            ++hashMap[ch];
        }
        int count = t.size();
        //这题如果t有重复的char也要算进去，所以用t.size()
        int minLength = INT_MAX;
        int minLeft = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            //这里s中不在t里面的char在hashMap中的值也会被减1
            //这样才能在后面if (map[s[left++]]++ >= 0) ++count;中
            //判断left扫过的char是不是在t里面
            if (hashMap[s[right]]-- > 0) {
                --count;
            }
            while (count == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }
                //这里用>=0也是可以的
                //但是因为一旦出现++count
                //这个while loop就跳出了
                //所以用==也对
                if (hashMap[s[left++]]++ >= 0) {
                    ++count;
                }
            }
        }
        return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
    }
};