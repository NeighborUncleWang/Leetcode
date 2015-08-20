class Solution {
public:
    bool isMatch(string s, string p) {
        int startS = 0;
        int startP = 0;
        int lengthS = s.size();
        int lengthP = p.size();
        bool hasStar = false;
        int i = 0;
        int j = 0;
        //这里不需要事先s.push_back('\0'), p.push_back('\0'), 因为在xcode里s[s.size()] == '\0'
        //也就是说std::string也是以\0结尾的
        //这里要用到这个主要是因为当s="hi", p="*?"时，会出现j=2,i=1的情况，这时候也会进入default case
        //然后i会退回之前记录的位置重新匹配
        for ( ; i < lengthS; ++i, ++j) {
            switch (p[j]) {
                case '?':
                    break;
                case '*':
                    hasStar = true;
                    startS = i;
                    while (p[j] == '*') {
                        ++j;
                    }
                    if (j == lengthP) {
                        return true;
                    }
                    startP = j;
                    --i;
                    --j;
                    break;
                default:
                    if (s[i] != p[j]) {
                        if (hasStar == false) {
                            return false;
                        }
                        i = startS;
                        j = startP - 1;
                        ++startS;
                    }
                    break;
            }
        }
        while (j < lengthP && p[j] == '*') {
            ++j;
        }
        return j == lengthP;
    }
};
