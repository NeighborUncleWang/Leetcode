class Solution {
private:
    vector<string> split(string& s, char ch) {
        stringstream ss(s);
        vector<string> result;
        string temp;
        //".11.1."这种例子最后会存成["", "11", "1"]
        //最后一个delimiter后面如果是空字符串的话不会被读进来
        while (getline(ss, temp, ch)) {
            result.push_back(temp);
        }
        return result;
    }
    bool validIPv4(string& s) {
        if (s.empty() || s.back() == '.') return false;
        vector<string> tokens = split(s, '.');
        if (tokens.size() != 4) return false;
        for (string& token : tokens) {
            if (token.size() > 3) return false;
            if (token.find_first_not_of("0123456789") != string::npos) return false;
            if (token.size() > 1 && token[0] == '0') return false;
            if (token.empty()) return false;
            if (stoi(token) < 0 || stoi(token) > 255) return false;
        }
        return true;
    }
    bool validIPv6(string& s) {
        if (s.empty() || s.back() == ':') return false;
        vector<string> tokens = split(s, ':');
        if (tokens.size() != 8) return false;
        for (string& token : tokens) {
            if (token.find_first_not_of("0123456789abcdefABCDEF") != string::npos) return false;
            if (token.size() > 4) return false;
            if (token.empty()) return false;
        }
        return true;
    }
public:
    string validIPAddress(string IP) {
        if (validIPv6(IP)) {
            return "IPv6";
        } else if (validIPv4(IP)) {
            return "IPv4";
        } else {
            return "Neither";
        }
    }
};