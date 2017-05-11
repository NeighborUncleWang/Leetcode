class Solution {
private:
    const string alphanum = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
    string GetCode() {
        string code;
        for (int i = 0; i < 6; ++i) {
            int index = rand() % 62;
            code += alphanum[index];
        }
        return code;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url2code.find(longUrl) != url2code.end()) {
            return url2code[longUrl];
        }
        string code = GetCode();
        while (code2url.find(code) != code2url.end()) {
            code = GetCode();
        }
        url2code[longUrl] = code;
        code2url[code] = longUrl;
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.rfind('/') + 1);
        return code2url[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));