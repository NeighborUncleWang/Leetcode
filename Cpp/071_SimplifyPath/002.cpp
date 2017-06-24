class Solution {
public:
    string simplifyPath(string path) {
        vector<string> symbols;
        for (auto it1 = path.find_first_not_of('/'); it1 != string::npos; ) {
            auto it2 = path.find('/', it1);
            string str = path.substr(it1, it2 - it1);
            if (str == ".." && !symbols.empty()) {
                symbols.pop_back();
            } else if (str != "." && str != "..") {
                symbols.push_back(str);
            }
            it1 = path.find_first_not_of('/', it2);
        }
        string res;
        for (string& symbol : symbols) {
            res += '/' + symbol;
        }
        return res.empty() ? "/" : res;
    }
};