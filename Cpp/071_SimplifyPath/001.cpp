class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string str;
        vector<string> symbols;
        while (getline(ss, str, '/')) {
            //如果输入是"///"
            //两个"/"分隔符之间会读入一个空的string
            //所以要有判断str != ""
            if (str == ".." && !symbols.empty()) {
                symbols.pop_back();
            } else if (str != "." && str != "" && str != "..") {
                symbols.push_back(str);
            }
        }
        string result;
        for (string& str : symbols) {
            result += "/" + move(str);
        }
        return result.empty() ? "/" : result;
    }
};