class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream v1(version1);
        stringstream v2(version2);
        while (!v1.eof() || !v2.eof()) {
            int number1 = getNext(v1);
            int number2 = getNext(v2);
            if (number1 > number2) {
                return 1;
            } else if (number1 < number2) {
                return -1;
            }
        }
        return 0;
    }
private:
    int getNext(stringstream& ss) {
        if (ss.eof()) {
            return 0;
        }
        string s;
        getline(ss, s, '.');
        return stoi(s);
    }
};