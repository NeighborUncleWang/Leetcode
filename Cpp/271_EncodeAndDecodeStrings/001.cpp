class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString;
        for (string& str : strs) {
            encodedString += to_string(str.size()) + '@' + str;
        }
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int head = 0;
        while (head < s.size()) {
            int pos = s.find('@', head);
            int length = stoi(s.substr(head, pos - head));
            result.push_back(s.substr(pos + 1, length));
            head = pos + length + 1;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));