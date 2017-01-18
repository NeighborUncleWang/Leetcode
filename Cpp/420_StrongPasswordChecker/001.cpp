class Solution {
public:
    int strongPasswordChecker(string s) {
        int upper = 1, lower = 1, digit = 1, repeat = 0;
        vector<int> deletion(3, 0);
        int change = 0;
        for (int i = 0; i < s.size(); ++ i) {
            ++repeat;
            if (i < (int)s.size() - 1 && s[i + 1] != s[i]) {
                if (repeat >= 3) {
                    change += repeat / 3;
                    ++deletion[repeat % 3];
                }
                repeat = 0;
            }
            if (isupper(s[i])) {
                upper = 0;
            }
            if (islower(s[i])) {
                lower = 0;
            }
            if (isdigit(s[i])) {
                digit = 0;
            }
        }
        if (repeat >= 3) {
            change += repeat / 3;
            ++deletion[repeat % 3];
        }
        if (s.size() <= 20) {
            return max(upper + lower + digit, max(change, 6 - (int)s.size()));
        } else {
            int to_delete = s.size() - 20;
            //如果to_delete <= deletion[0]那么deletion[0]可以1 delete可以减少1 replacement
            //这样效率最高
            //这种减少方法每个repeat substring只能进行一次
            if (to_delete <= deletion[0]) {
                change -= to_delete;
            //如果to_delete还有剩余，那么deletion[1]里面可以2 delete减少1 replacement
            //这种减少方法每个repeat substring只能进行一次
            } else if (to_delete - deletion[0] <= 2 * deletion[1]) {
                change -= deletion[0] + (to_delete - deletion[0]) / 2;
            } else {
            //如果to_delete还有剩余，那么剩余的to_delete可以3 delete减少1 replacement
            //这种减少方法没有次数限制
                change -= deletion[0] + deletion[1] + (to_delete - deletion[0] - 2 * deletion[1]) / 3;
            }
            //change有可能减到小于0，不过最后结果还是对的
            return to_delete + max(upper + lower + digit, change);
        }
    }
};