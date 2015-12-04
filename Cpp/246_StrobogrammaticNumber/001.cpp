class Solution {
public:
    bool isStrobogrammatic(string num) {
        int numSize = num.size();
        for (int i = 0; i <= numSize / 2; ++i) {
            switch (num[i]) {
                case '0':
                case '1':
                case '8':
                    if (num[i] != num[numSize - 1 - i]) {
                        return false;
                    }
                    break;
                case '6':
                    if (num[numSize - 1 - i] != '9') {
                        return false;
                    }
                    break;
                case '9':
                    if (num[numSize - 1 - i] != '6') {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};