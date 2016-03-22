class Solution {
public:
    int compareVersion(string version1, string version2) {
        while (!version1.empty() || !version2.empty()) {
            int number1 = getNext(version1);
            int number2 = getNext(version2);
            if (number1 > number2) {
                return 1;
            } else if (number1 < number2) {
                return -1;
            }
        }
        return 0;
    }
private:
    int getNext(string& s) {
        auto iter = s.find('.');
        if (s.size() == 0) {
            return 0;
        } else if (iter == string::npos) {
            auto temp = s;
            s.clear();
            return stoi(temp); 
        } else {
            auto temp = s.substr(0, iter);
            s = s.substr(iter + 1);
            return stoi(temp);
        }
    }
};
