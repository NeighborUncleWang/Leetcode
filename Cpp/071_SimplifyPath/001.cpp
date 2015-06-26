class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        vector<string> st;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') { ++i; }
            if (i == path.size()) {
                break;
            }
            int start = i;
            while (i < path.size() && path[i] != '/') { ++i; }
            int end = i;
            string s(path.begin() + start, path.begin() + end);//will construct from [begin, end), so should be path.begin() + end instead of path.begin() + end - 1
            //string s = path.substr(start, end - start);//another way to construct the string
            if (s == "..") {
                if (st.size() > 0) {
                    st.pop_back();
                }
            } else if (s != ".") {
                st.push_back(s);
            }
        }
        string result;
        if (st.size() == 0) {
            return "/";
        } else {
            for (int j = 0; j < st.size(); ++j) {
                result = result + "/" + st[j];
            }
            return result;
        }
    }
};
